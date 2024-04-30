#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    char arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Stack Overflow: Cannot push element onto full stack.\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop element from empty stack.\n");
        return '\0';
    }
    return stack->arr[stack->top--];
}

int isBalanced(char *expression) {
    Stack stack;
    initialize(&stack);
    int i = 0;
    
    while (expression[i] != '\0') {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (isEmpty(&stack)) {
                return 0;
            }
            char topChar = pop(&stack);
            if ((expression[i] == ')' && topChar != '(') ||
                (expression[i] == ']' && topChar != '[') ||
                (expression[i] == '}' && topChar != '{')) {
                return 0;
            }
        }
        i++;
    }
    
    return isEmpty(&stack);
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter expression: ");
    fgets(expression, MAX_SIZE, stdin);
    
    int result = isBalanced(expression);
    if (result) {
        printf("Expression is balanced.\n");
    } else {
        printf("Expression is not balanced.\n");
    }
    
    return 0;
}