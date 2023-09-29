#include <iostream>

using namespace std;

// Define a structure for the linked list node
struct Node {
    int price;
    Node* next;

    Node(int p) : price(p), next(nullptr) {}
};

// Function to calculate the sum of the last m items in the linked list
int sumOfLastMItems(Node* head, int m) {
    int sum = 0;
    Node* current = head;
    int size = 0;

    // Calculate the size of the linked list
    while (current != nullptr) {
        size++;
        current = current->next;
    }

    // Reset the current pointer to the beginning
    current = head;

    // Traverse the list until we reach the (size - m)th node
    for (int i = 0; i < size - m; i++) {
        current = current->next;
    }

    // Calculate the sum of the last m items
    for (int i = 0; i < m; i++) {
        sum += current->price;
        current = current->next;
    }

    return sum;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        Node* newNode = new Node(price);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int m;
    cin >> m;

    int result = sumOfLastMItems(head, m);
    cout << result << endl;

    // Clean up the memory by deleting the linked list
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

