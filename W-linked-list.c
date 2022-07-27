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
void last_to_first()
{
    Node *first = head;
    Node *last = NULL;
    while (first->next)
    {
        first = first->next;
    }
    last = first;
    while (last)
    {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

Node *search(int item)
{
    Node *node = head;
    if (!node)
    {
        printf("List is empty\n");
        return NULL;
    }

    while (node)
    {
        if (node->data == item)
        {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

Node *remove_node(int item)
{

    Node *node = head;
    Node *prev = NULL;
    if (!node)
    {
        printf("List is empty\n");
        return NULL;
    }
    while (node)
    {
        if (node->data == item)
        {
            if (!prev)
            {
                node->prev = NULL;
                head = node->next;
                return node;
            }
            prev->next = node->next;
            prev->next->prev = prev;
            return node;
        }
        prev = node;
        node = node->next;
    }
    return NULL;
}

int main()
{
    append(10);
    append(100);
    append(200);
    insert(999, 99999);
    remove_node(100);
    print_list();
    last_to_first();
    Node *node = search(200);
    if (node)
    {
        printf("Data : %d\n", node->data);
    }
    else
    {
        printf("Not Found!\n");
    }
    printf("Length of list: %d\n", length());

    return 0;
}