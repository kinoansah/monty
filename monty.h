#ifndef MONTY_H
#define MONTY_H

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function to create a new stack node */
stack_t *createNode(int data);

/* Function to check if the stack is empty */
int isEmpty(stack_t *root);

/* Function to push an element onto the stack */
void push(stack_t **root, int data);

/* Function to pop an element from the stack */
int pop(stack_t **root);

/* Function to get the value at the top of the stack */
int peek(stack_t *root);

/* Function to swap the top two elements of the stack */
void swap(stack_t **stack);

/* Function to add the top two elements of the stack */
void add(stack_t **stack);

/* Function to print all the values on the stack */
void printStack(stack_t *root);

#endif /* MONTY_H */

