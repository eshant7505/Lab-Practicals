class ArrayStack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()

    def peek(self):
        if not self.is_empty():
            return self.items[-1]

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class StructStack:
    def __init__(self):
        self.top = None

    def is_empty(self):
        return self.top is None

    def push(self, item):
        new_node = Node(item)
        new_node.next = self.top
        self.top = new_node

    def pop(self):
        if not self.is_empty():
            popped = self.top.data
            self.top = self.top.next
            return popped

    def peek(self):
        if not self.is_empty():
            return self.top.data

def infix_to_postfix(expression, stack):
    precedence = {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3}
    result = []

    for char in expression:
        if char.isalnum():
            result.append(char)
        elif char == '(':
            stack.push(char)
        elif char == ')':
            while not stack.is_empty() and stack.peek() != '(':
                result.append(stack.pop())
            stack.pop()  # Pop '('
        else:
            while not stack.is_empty() and precedence.get(stack.peek(), 0) >= precedence.get(char, 0):
                result.append(stack.pop())
            stack.push(char)

    while not stack.is_empty():
        result.append(stack.pop())

    return ''.join(result)

def main():
    infix_expression = "a+b*(c^d-e)^(f+g*h)-i"
    
    # Using Array Stack
    array_stack = ArrayStack()
    result_array_stack = infix_to_postfix(infix_expression, array_stack)
    print("Infix Expression:", infix_expression)
    print("Postfix Expression (Array Stack):", result_array_stack)

    # Using Struct Stack
    struct_stack = StructStack()
    result_struct_stack = infix_to_postfix(infix_expression, struct_stack)
    print("Postfix Expression (Struct Stack):", result_struct_stack)

if __name__ == "__main__":
    main()
