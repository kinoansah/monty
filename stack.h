#ifndef STACK_H
#define STACK_H

/* Struct for a stack node */
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

/* Function to create a new stack node */
StackNode* createNode(int data);

/* Function to check if the stack is empty */
int isEmpty(StackNode* root);

/* Function to push an element onto the stack */
void push(StackNode** root, int data);

/* Function to pop an element from the stack */
int pop(StackNode** root);

/* Function to get the value at the top of the stack */
int peek(StackNode* root);

/* Function to swap the top two elements of the stack */
void swap(StackNode** root);

/* Function to add the top two elements of the stack */
void add(StackNode** root);

/* Function to print all the values on the stack */
void printStack(StackNode* root);

#endif /* STACK_H */
