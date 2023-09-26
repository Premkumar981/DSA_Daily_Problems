#include <iostream>
#include <vector>

using namespace std;

// Define the structure of a singly linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to delete nodes in the specified range
ListNode* deleteNodes(ListNode* head, int start, int end) {
    if (!head) return NULL;

    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    ListNode* current = head;

    // Traverse the list to find the start node
    for (int i = 1; i < start; i++) {
        prev = current;
        current = current->next;
    }

    // Delete nodes within the range [start, end]
    for (int i = start; i <= end; i++) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    // Connect the previous node to the node after the end position
    prev->next = current;

    return dummy.next;
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int size;
    cin >> size;

    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int start, end;
    cin >> start >> end;

    // Create the linked list
    ListNode* head = NULL;
    for (int i = size - 1; i >= 0; i--) {
        ListNode* newNode = new ListNode(arr[i]);
        newNode->next = head;
        head = newNode;
    }

    // Print the linked list before deletion
    cout << "Linked List before deletion: ";
    printList(head);

    // Delete nodes in the specified range
    head = deleteNodes(head, start, end);

    // Print the linked list after deletion
    cout << "Linked List after deletion: ";
    if (!head) {
        cout << "all the elements are deleted";
    } else {
        printList(head);
    }

    return 0;
}

