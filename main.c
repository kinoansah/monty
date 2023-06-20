#include <stdio.h>
#include "monty.h"

int main() {
    /* Example usage */
    int stack[STACK_SIZE];
    int top = -1;

    push(1, "10", stack, &top);
    push(2, "20", stack, &top);
    pall(stack, top);
    pint(3, stack, top);
    pop(4, &top);
    swap(5, stack, top);
    add(6, stack, &top);
    pall(stack, top);
    nop();

    return 0;
}
