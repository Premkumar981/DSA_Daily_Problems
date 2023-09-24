#include <iostream>
using namespace std;

// Define a structure for a node in the linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to swap elements pairwise in a linked list
Node* swapPairs(Node* head) {
    if (!head || !head->next) {
        return head;
    }

    Node* newHead = head->next;
    Node* prev = nullptr;

    while (head && head->next) {
        Node* first = head;
        Node* second = head->next;

        first->next = second->next;
        second->next = first;

        if (prev) {
            prev->next = second;
        }

        prev = first;
        head = first->next;
    }

    return newHead;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Linked list before swapping pairwise: ";
    printList(head);

    head = swapPairs(head);

    cout << "Linked list after swapping pairwise: ";
    printList(head);

    return 0;
}

