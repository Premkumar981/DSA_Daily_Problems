#include <iostream>
#include <stack>

// Define the structure for a node in the linked list
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Define a class for the stack implemented using a linked list
class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    // Function to push an element onto the stack
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    // Function to pop the top element from the stack
    int pop() {
        if (isEmpty()) {
            return -1; // Return -1 to indicate an empty stack
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

// Function to convert decimal to binary using a stack
std::string decimalToBinary(int decimal) {
    Stack stack;
    while (decimal > 0) {
        stack.push(decimal % 2);
        decimal /= 2;
    }

    std::string binaryRepresentation;
    while (!stack.isEmpty()) {
        binaryRepresentation += std::to_string(stack.pop());
    }

    return binaryRepresentation;
}

int main() {
    int decimal;
    std::cin >> decimal;

    std::string binaryRepresentation = decimalToBinary(decimal);

    std::cout << "Binary representation: " << binaryRepresentation << std::endl;

    return 0;
}

