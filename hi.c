// Dynamic Stack Implementation using Array in C:
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

// Stack structure
struct Stack {
    int top;
    int arr[MAXSIZE];
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top < 0);
}

// Function to push an element to the stack
int push(struct Stack* stack) {
    int val;
    if (stack->top == MAXSIZE - 1) {
        printf("Overflow !!\n");
        return 0;
    } else {
        printf("Enter value to push: ");
        scanf("%d", &val);
        stack->top++;
        stack->arr[stack->top] = val;
        printf("Item pushed\n");
        return 1;
    }
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Underflow !!\n");
        return 0;
    } else {
        stack->top--;
        printf("Item popped\n");
        return 1;
    }
}

// Function to display the stack elements
void display(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Printing stack elements:\n");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d\n", stack->arr[i]);
        }
    }
}

int main() {
    int choice = 0;
    struct Stack s;
    initStack(&s);
    
    printf("********* Stack operations using array *********\n");
    printf("\n------------------------------------------------\n");

    while (choice != 4) {
        printf("\nChoose one from the below options:\n");
        printf("1. Push\n2. Pop\n3. Show\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                push(&s);
                break;
            }
            case 2: {
                pop(&s);
                break;
            }
            case 3: {
                display(&s);
                break;
            }
            case 4: {
                printf("Exiting...\n");
                exit(0);
                break;
            }
            default: {
                printf("Please enter a valid choice\n");
                break;
            }
        }
    }
    
return 0;
}
