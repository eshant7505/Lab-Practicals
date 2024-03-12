#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define the maximum size of the stack
#define MAX_STACK_SIZE 100

// Define the stack structure
typedef struct {
    int top;
    int items[MAX_STACK_SIZE];
} Stack;

// Function prototypes
void initializeStack(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int evaluatePostfix(char *expression);

int main() {
    char expression[100];

    // Get the postfix expression from the user
    printf("Enter the postfix expression (without spaces between digits and operators): ");
    scanf("%s", expression);

    // Evaluate the postfix expression
    int result = evaluatePostfix(expression);

    // Display the result
    printf("Result: %d\n", result);

    return 0;
}

// Initialize the stack
void initializeStack(Stack *s) {
    s->top = -1;
}

// Push a value onto the stack
void push(Stack *s, int value) {
    if (s->top == MAX_STACK_SIZE - 1) {
        printf("Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}

// Pop a value from the stack
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

// Evaluate the postfix expression
int evaluatePostfix(char *expression) {
    Stack stack;
    initializeStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Error: Invalid operator\n");
                    exit(EXIT_FAILURE);
            }
        }
    }

    return pop(&stack);
}

