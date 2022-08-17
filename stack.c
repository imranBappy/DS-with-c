#include "stack.h"
#include <stdio.h>
int main()
{
    Stack *stack = make_stack();
    stack->push(stack, 10);
    stack->push(stack, 100);
    stack->print_stack(stack);
    return 0;
}