#include <iostream>

class StackNode {
public:
    int data;
    StackNode* next;

    StackNode(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    StackNode* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    // Push an element onto the stack
    void push(int value) {
        StackNode* newNode = new StackNode(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    // Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack underflow!" << std::endl;
            return -1; // or handle the error as needed
        }
        int topData = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        size--;
        return topData;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // Get the current size of the stack
    int getSize() const {
        return size;
    }

    // Peek at the top element without removing it
    int peek() const {
        if (isEmpty()) {
            std::cerr << "Stack is empty!" << std::endl;
            return -1; // or handle the error as needed
        }
        return top->data;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element is: " << stack.peek() << std::endl; // Should output 30

    std::cout << "Popped element: " << stack.pop() << std::endl; // Should output 30
    std::cout << "Popped element: " << stack.pop() << std::endl; // Should output 20

    std::cout << "Current size of stack: " << stack.getSize() << std::endl; // Should output 1

    return 0;
}
