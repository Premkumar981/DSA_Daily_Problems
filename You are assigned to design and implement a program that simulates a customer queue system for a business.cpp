#include <iostream>

struct Node {
    int customerID; 
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

void initializeQueue(Queue* q) {
    q->front = nullptr;
    q->rear = nullptr;
}

bool isEmpty(Queue* q) {
    return q->front == nullptr;
}

void enqueue(Queue* q, int customerID) { // Modified parameter name
    Node* newNode = new Node;
    newNode->customerID = customerID; // Modified assignment
    newNode->next = nullptr;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

bool dequeue(Queue* q, int& customerID) { // Modified parameter name
    if (isEmpty(q)) {
        return false;
    }

    Node* temp = q->front;
    customerID = temp->customerID; // Modified assignment
    q->front = q->front->next;

    if (q->front == nullptr) {
        q->rear = nullptr;
    }

    delete temp;
    return true;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        Node* current = q->front;
        std::cout << "Customer IDs in the queue are: ";
        while (current != nullptr) {
            std::cout << current->customerID << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

int main() {
    Queue q;
    int customerID; // Modified variable name
    int option;

    initializeQueue(&q);

    while (true) {
        if (!(std::cin >> option)) {
            break;
        }

        switch (option) {
            case 1:
                if (!(std::cin >> customerID)) {
                    break;
                }

                enqueue(&q, customerID);
                std::cout << "Customer ID " << customerID << " is enqueued." << std::endl;
                break;

            case 2:
                if (dequeue(&q, customerID)) {
                    std::cout << "Dequeued customer ID: " << customerID << std::endl;
                } else {
                    std::cout << "Queue is empty." << std::endl;
                }
                break;

            case 3:
                display(&q);
                break;

            default:
                std::cout << "Invalid option." << std::endl;
                break;
        }
    }

    return 0;
}
