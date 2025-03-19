// C programming for converting infix to  a postfix expression using stack
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Stack structure to hold operators
struct Stack {
    char arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Function to check if the character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to check the precedence of operators
int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;  // For non-operators
    }
}

// Function to check if the character is an operand (numbers or variables)
int isOperand(char c) {
    return isalpha(c) || isdigit(c);
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack s;
    initStack(&s);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char element = infix[i];

        if (isOperand(element)) {
            // If the element is an operand, add it to the result (postfix expression)
            postfix[j++] = element;
        } else if (element == '(') {
            // If the element is '(', push it onto the stack
            s.arr[++s.top] = element;
        } else if (element == ')') {
            // If the element is ')', pop from the stack until '(' is found
            while (s.top != -1 && s.arr[s.top] != '(') {
                postfix[j++] = s.arr[s.top--];
            }
            s.top--;  // Pop '('
        } else if (isOperator(element)) {
            // If the element is an operator
            while (s.top != -1 && precedence(s.arr[s.top]) >= precedence(element)) {
                postfix[j++] = s.arr[s.top--];
            }
            s.arr[++s.top] = element;
        }
    }

    // Pop all remaining operators from the stack
    while (s.top != -1) {
        postfix[j++] = s.arr[s.top--];
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];
    
    // Input infix expression
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    // Output the postfix expression
    printf("Postfix expression: %s\n", postfix);

return 0;
}
