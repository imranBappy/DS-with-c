// A simple C program for traversal of a linked list
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

    Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (!head)
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

void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf(" %d ", n->data);
        n = n->next;
    }
}

int main()
{
    insert(1);
    insert(2);
    insert(3);

    printList(head);

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("1");
    // }

    return 0;
}
