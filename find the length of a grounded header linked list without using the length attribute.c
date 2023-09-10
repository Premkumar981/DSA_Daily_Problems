#include <stdio.h>
#include <stdlib.h>

// Define the structure of a singly linked list node
struct ListNode {
    int data;
    struct ListNode* next;
};

// Function to find the length of the linked list
int findLength(struct ListNode* head) {
    int count = 0;
    struct ListNode* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    // Initialize the linked list
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Find the length of the linked list
    int length = findLength(head);

    // Print the length
    printf("%d\n", length);

    // Free the memory allocated for the linked list nodes
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

