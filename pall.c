#include <stdio.h>
#include "monty.h"

void pall(int *stack, int top) {
    int i;
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}
