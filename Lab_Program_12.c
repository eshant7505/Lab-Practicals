#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '\0';
}

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
