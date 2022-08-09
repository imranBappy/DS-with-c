#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next, *prev;
} Node;
Node *head;
Node *tail;

void push(int data);
void pop();
void print_list();
void print_list_reverse();
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    
    print_list();
    print_list_reverse();

    return 0;
}
void push(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (!head)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail = newNode;
}

void pop()
{
    if (!head)
    {
        printf("List is empty!\n");
        return;
    }
    else if (tail == head)
    {
        head = NULL;
        tail = NULL;
        return;
    }
    Node *temp = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    free(temp);
}
void print_list()
{
    if (!head)
    {
        printf("List is empty!\n");
        return;
    }
    Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
void print_list_reverse()
{
    if (!head)
    {
        printf("List is empty!\n");
        return;
    }
    Node *temp = tail;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    } while (temp != tail);
    printf("\n");
}
