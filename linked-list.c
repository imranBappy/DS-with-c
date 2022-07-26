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
    printList();
    return 0;
}