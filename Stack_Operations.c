#include <stdio.h>
#include <stdlib.h>

int *stack = NULL;
int top = -1;
int capacity = 0;

// Initialize stack
void initStack(int size) {
    capacity = size;
    stack = (int *)malloc(capacity * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

// Resize stack if full
void resize() {
    capacity *= 2;
    stack = (int *)realloc(stack, capacity * sizeof(int));
    if (stack == NULL) {
        printf("Memory reallocation failed\n");
        exit(1);
    }
    printf("Stack resized to capacity %d\n", capacity);
}

// Push operation
void push() {
    int x;
    printf("Enter element to push: ");
    scanf("%d", &x);
    if (top + 1 == capacity)
        printf("Stack Overflow\n");
    stack[++top] = x;                            // top is incremented by 1
    printf("%d pushed to stack\n", x);
}

// Pop operation
void pop() {
    if (top < 0)
        printf("Stack Underflow\n");
    else
        printf("%d popped from stack\n", stack[top--]);                // top is decremented by 1
}

// Peek operation
void peek() {
    if (top < 0)
        printf("Stack is empty\n");
    else
        printf("Top element is %d\n", stack[top]);
}

// Proper stack visual display
void displayStack() {
    if (top < 0) {
        printf("Stack is empty\n");
    } else {
        printf("\n--- Stack View ---\n");
        printf("\n------\n");
        for (int i = top; i >= 0; i--) {
            if (i == top)
                printf("| %d | <-- top\n", stack[i]);
            else
                printf("| %d |\n", stack[i]);
        }
        printf("------\n\n");
    }
}

// Main function
int main() {
    int choice, size;
    printf("Enter initial stack size: ");
    scanf("%d", &size);
    initStack(size);

    do {
        printf("\n==== Stack Menu ====\n");
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

    free(stack);
    return 0;
}