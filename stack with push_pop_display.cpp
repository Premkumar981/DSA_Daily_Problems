#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100]; // Array to store stack elements
    int top;      // Index of the top element
public:
    Stack() {
        top = -1; // Initialize top to -1 (empty stack)
    }

    // Push an element onto the stack
    void push(int element) {
        if (top == 99) {
            cout << "Stack Overflow. Cannot perform the push operation." << endl;
        } else {
            arr[++top] = element;
            cout << "Element " << element << " pushed onto the stack." << endl;
        }
    }

    // Pop an element from the stack
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow. Cannot perform pop operation." << endl;
        } else {
            cout << "Element " << arr[top--] << " popped from the stack." << endl;
        }
    }

    // Display the elements in the stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Elements in the stack:";
            for (int i = top; i >= 0; i--) {
                cout << " " << arr[i];
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;
    int choice, element;

    while (true) {
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> element;
                stack.push(element);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }

    return 0;
}

