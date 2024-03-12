class Stack:
    def __init__(self, capacity):
        self.capacity = capacity
        self.stack = [None] * capacity
        self.top = -1

    def is_empty(self):
        return self.top == -1

    def is_full(self):
        return self.top == self.capacity - 1

    def push(self, item):
        if self.is_full():
            print("Stack Overflow. Cannot push element:", item)
        else:
            self.top += 1
            self.stack[self.top] = item
            print("Pushed", item, "onto the stack")

    def pop(self):
        if self.is_empty():
            print("Stack Underflow. Cannot pop from an empty stack.")
            return None
        else:
            item = self.stack[self.top]
            self.top -= 1
            print("Popped", item, "from the stack")
            return item

    def peek(self):
        if self.is_empty():
            print("Stack is empty. Cannot peek.")
            return None
        else:
            return self.stack[self.top]

    def size(self):
        return self.top + 1


# Example usage:
if __name__ == "__main__":
    stack_capacity = 5
    stack = Stack(stack_capacity)

    stack.push(1)
    stack.push(2)
    stack.push(3)

    print("Top element:", stack.peek())
    print("Stack size:", stack.size())

    popped_item = stack.pop()
    print("Popped item:", popped_item)

    print("Is the stack empty?", stack.is_empty())
