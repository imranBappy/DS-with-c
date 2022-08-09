#include <stdio.h>
#include <stdlib.h>
/*
    write implement a circular linked list
*/

typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *head = NULL;
Node *tail = NULL;

void push(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (!tail)
    {
        head = newNode;
        tail = newNode;
        newNode->next = head;
        return;
    }
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
}
void pop()
{
    if (!head)
    {
        printf("list is empty\n");
        return;
    }
    Node *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    temp->next = head;
    free(tail);
    tail = temp;
}
void printList()
{
    Node *temp = head;
    if (!head)
    {
        printf("List is empty\n");
        return;
    }
    printf("%d -> ", temp->data);
    do
    {
        temp = temp->next;
        printf("%d -> ", temp->data);

    } while (temp != tail);
    printf("\n");
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    pop();
    pop();

    printList();

    return 0;
}
