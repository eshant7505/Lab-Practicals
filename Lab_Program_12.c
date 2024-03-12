#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a stack of a given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '\0';
}

// Function to check if brackets are balanced in the expression
int areBracketsBalanced(char exp[]) {
    struct Stack* stack = createStack(strlen(exp));

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(stack, exp[i]);
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (isEmpty(stack)) {
                free(stack->array);
                free(stack);
                return 0; // Unbalanced brackets
            }

            char poppedBracket = pop(stack);

            // Check if the popped bracket matches the current closing bracket
            if ((exp[i] == ')' && poppedBracket != '(') ||
                (exp[i] == ']' && poppedBracket != '[') ||
                (exp[i] == '}' && poppedBracket != '{')) {
                free(stack->array);
                free(stack);
                return 0; // Unbalanced brackets
            }
        }
    }

    // If the stack is empty, brackets are balanced
    int result = isEmpty(stack);
    free(stack->array);
    free(stack);
    return result;
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);

    if (areBracketsBalanced(expression)) {
        printf("Brackets are balanced.\n");
    } else {
        printf("Brackets are not balanced.\n");
    }

    return 0;
}
