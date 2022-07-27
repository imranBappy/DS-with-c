#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

void append(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (!head)
    {
        head = newNode;
        return;
    }

    Node *node = head;
    while (node)
    {
        if (!node->next)
        {
            node->next = newNode;
            newNode->prev = node;
            return;
        }
        node = node->next;
    }
}
int length()
{
    int count = 0;
    Node *node = head;
    while (node)
    {
        count++;
        node = node->next;
    }
    return count;
}
void print_list()
{
    Node *node = head;
    while (node)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

Node *insert(int data, int position)
{
    int count = 1;
    Node *node = head;
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *prevNode = NULL;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    while (node)
    {
        if (count == position)
        {
            if (1 == position)
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
                return newNode;
            }
            newNode->next = node;
            newNode->prev = node->prev;
            node->prev = newNode;
            prevNode->next = newNode;
            return newNode;
        }
        prevNode = node;
        node = node->next;
        count++;
    }
    newNode->prev = prevNode;
    prevNode->next = newNode;
    return newNode;
}

int main()
{
    append(10);
    append(100);
    append(200);
    insert(999, 99999);
    print_list();

    printf("Length of list: %d\n", length());
    return 0;
}