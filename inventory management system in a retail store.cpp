#include <iostream>

// Define a structure for the linked list node
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Function to add 1 to the barcode represented by the linked list
Node* addOneToBarcode(Node* head) {
    Node* curr = head;
    Node* lastNonNine = nullptr;

    // Traverse the linked list from right to left
    while (curr) {
        if (curr->data != 9) {
            lastNonNine = curr;
        }
        curr = curr->next;
    }

    // Increment the last non-nine digit by 1
    if (lastNonNine) {
        lastNonNine->data++;
    } else {
        // If all digits were 9, we need to add a new node with 1 at the beginning
        Node* newDigit = new Node(1);
        newDigit->next = head;
        head = newDigit;
    }

    // Set all digits to the right of the last non-nine digit to 0
    curr = lastNonNine ? lastNonNine->next : head;
    while (curr) {
        curr->data = 0;
        curr = curr->next;
    }

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    // Read the barcode digits and create the linked list
    for (int i = 0; i < n; i++) {
        int digit;
        std::cin >> digit;
        Node* newNode = new Node(digit);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Add 1 to the barcode
    head = addOneToBarcode(head);

    // Print the modified barcode
    printList(head);

    // Free the memory used by the linked list
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

