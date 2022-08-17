#include <stdio.h>
#include <stdlib.h>
#define STACK_MAX 100
typedef struct Stack
{
    int top;
    int data[STACK_MAX];
    void (*push)(struct Stack *, int);
    void (*print_stack)(struct Stack *);
    int (*pop)(struct Stack *);
    int (*isEmpty)(struct Stack *);
} Stack;

void push(Stack *stack, int value)
{
    if (stack->top == STACK_MAX)
    {
        printf("Stack overflow: %d\n", stack->top);
        return;
    }
    stack->top++; // (*stack).top stack->top;
    stack->data[stack->top] = value;
}
int pop(Stack *stack)
{
    if (stack->top < 0)
    {
        printf("Stack is empty!");
        return -1;
    }
    int temp = stack->data[stack->top];
    stack->top--;
    return temp;
}
int isEmpty(Stack *stack)
{
    if (stack->top < 0)
        return 1;
    return 0;
}
void print_stack(struct Stack *stack)
{
    printf("top : %d\n", stack->top);
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->data[i]);
    }
}
Stack *make_stack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->push = &push;
    stack->pop = &pop;
    stack->isEmpty = &isEmpty;
    stack->print_stack = &print_stack;
    stack->top = -1;
    return stack;
}
