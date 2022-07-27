#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void insert(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *node = head;
    while (node->next)
    {
        node = node->next;
    }
    node->next = newNode;
}
Node *find(int data)
{
    Node *node = head;
    while (node)
    {
        if (node->data == data)
        {
            return node;
        }
        node = node->next;
    }
    return NULL;
}
void delete (int data)
{
    Node *node = head;
    Node *prev = NULL;
    while (node)
    {
        if (node->data == data)
        {
            if (!prev)
            {
                head = node->next;
                free(node);
                return;
            }
            prev->next = node->next;
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
    printf("Data Not Found\n");
}
void printList()
{
    Node *node = head;
    if (!head)
    {
        printf("List is empty\n");
        return;
    }
    while (node)
    {
        printf("%d, ", node->data);
        node = node->next;
    }
}
int main()
{
    insert(130);
    insert(100);
    insert(200);
    insert(300);
    insert(1000);
    delete (1000);

    printList();
    Node *node = find(1000);
    if (node)
    {
        printf("\nNode found with data %d\n", node->data);
    }
    else
    {
        printf("\nNode not found\n");
    }
    return 0;
}