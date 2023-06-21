#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    stack_t *stack = NULL;

    push(&stack, 10, "1");
    push(&stack, 20, "2");
    pall(&stack, "3");
    pint(&stack, "4");
    pop(&stack, "5");
    swap(&stack, "6");
    add(&stack, "7");
    pall(&stack, "8");
    nop(&stack, "9");

    return 0;
}
