#include <iostream>

struct Node {
    int data;
    Node* next;
};

struct Deque {
    Node* front;
    Node* rear;
};

void initDeque(Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

bool isEmpty(Deque* deque) {
    return deque->front == NULL;
}

void pushBack(Deque* deque, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

int popFront(Deque* deque) {
    if (isEmpty(deque)) {
        std::cout << "The deque is empty." << std::endl;
        exit(1);
    }
    int data = deque->front->data;
    Node* temp = deque->front;
    deque->front = deque->front->next;
    delete temp;
    if (deque->front == NULL) {
        deque->rear = NULL;
    }
    return data;
}

int main() {
    Deque myDeque;
    initDeque(&myDeque);
    int num;
    while (std::cin >> num) {
        if (num == -1)
            break;
        pushBack(&myDeque, num);
    }
    if (isEmpty(&myDeque)) {
        std::cout << "The deque is empty." << std::endl;
    } else {
        int minElement = myDeque.front->data;
        Node* current = myDeque.front->next;
        while (current != NULL) {
            if (current->data < minElement) {
                minElement = current->data;
            }
            current = current->next;
        }
        std::cout <<  minElement ;
    }
    return 0;
}
