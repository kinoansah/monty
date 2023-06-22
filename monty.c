#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define MAX_LINE_LENGTH 100

void executeInstruction(char* instruction, StackNode** stack, int lineNum) {
    char* arg;
    int value;

    if (strcmp(instruction, "push") == 0) {
        /* Parse the argument after push */
        arg = strtok(NULL, " ");
        if (arg == NULL) {
            fprintf(stderr, "Error: L%d: usage: push integer\n", lineNum);
            exit(EXIT_FAILURE);
        }
        value = atoi(arg);
        push(stack, value);
    } else if (strcmp(instruction, "pall") == 0) {
        printStack(*stack);
    } else if (strcmp(instruction, "pint") == 0) {
        if (isEmpty(*stack)) {
            fprintf(stderr, "Error: L%d: can't pint, stack empty\n", lineNum);
            exit(EXIT_FAILURE);
        }
        printf("%d\n", peek(*stack));
    } else if (strcmp(instruction, "pop") == 0) {
        if (isEmpty(*stack)) {
            fprintf(stderr, "Error: L%d: can't pop an empty stack\n", lineNum);
            exit(EXIT_FAILURE);
        }
        pop(stack);
    } else if (strcmp(instruction, "swap") == 0) {
        swap(stack);
    } else if (strcmp(instruction, "add") == 0) {
        add(stack);
    } else if (strcmp(instruction, "nop") != 0) {
        fprintf(stderr, "Error: L%d: unknown instruction %s\n", lineNum, instruction);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char* argv[]) {
    FILE* file;
    StackNode* stack = NULL;
    char line[MAX_LINE_LENGTH];
    char* instruction;
    int lineNum = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: monty file\n");
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        lineNum++;
        instruction = strtok(line, " \n");
        if (instruction != NULL && instruction[0] != '#') {
            executeInstruction(instruction, &stack, lineNum);
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}

