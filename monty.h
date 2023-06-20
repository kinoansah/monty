#ifndef MONTY_H
#define MONTY_H

#define STACK_SIZE 100

void push(int line_number, char *argument, int *stack, int *top);
void pall(int *stack, int top);
void pint(int line_number, int *stack, int top);
void pop(int line_number, int *top);
void swap(int line_number, int *stack, int top);
void add(int line_number, int *stack, int *top);
void nop(void);

#endif /* MONTY_H */

