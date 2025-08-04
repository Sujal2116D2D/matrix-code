#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **stack = NULL;
int top = -1;
int capacity = 0;

// Initialize stack
void initStack(int size) {
    capacity = size;
    stack = (char **)malloc(capacity * sizeof(char *));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

// Resize stack if full
void resize() {
    capacity *= 2;
    stack = (char **)realloc(stack, capacity * sizeof(char *));
    if (stack == NULL) {
        printf("Memory reallocation failed\n");
        exit(1);
    }
    printf("Stack resized to capacity %d\n", capacity);
}

// Push a string
void push() {
    char buffer[100];
    printf("Enter string to push: ");
    scanf(" %[^\n]", buffer); // Read string with spaces

    if (top + 1 == capacity)
        resize();

    stack[++top] = strdup(buffer); // Allocate and copy string
    printf("\"%s\" pushed to stack\n", buffer);
}

// Pop a string
void pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
    } else {
        printf("\"%s\" popped from stack\n", stack[top]);
        free(stack[top--]); // Free memory
    }
}

// Peek top string
void peek() {
    if (top < 0)
        printf("Stack is empty\n");
    else
        printf("Top element is \"%s\"\n", stack[top]);
}

// Display stack contents
void displayStack() {
    if (top < 0) {
        printf("Stack is empty\n");
    } else {
        printf("\n--- Stack View ---\n");
        printf("\n------\n");
        for (int i = top; i >= 0; i--) {
            if (i == top)
                printf("| %s | <-- top\n", stack[i]);
            else
                printf("| %s |\n", stack[i]);
        }
        printf("------\n\n");
    }
}

// Main
int main() {
    int choice, size;
    printf("Enter initial stack size: ");
    scanf("%d", &size);
    initStack(size);

    do {
        printf("\n==== String Stack Menu ====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack View\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: displayStack(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    // Clean up memory
    for (int i = 0; i <= top; i++)
        free(stack[i]);
    free(stack);

    return 0;
}