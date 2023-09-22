#include <stdio.h>
#include <stdlib.h>

// Define the structure of a player node
struct Player {
    int jerseyNumber;
    struct Player* next;
};

// Function to rotate the linked list to the right by k positions
struct Player* rotateList(struct Player* head, int k) {
    if (head == NULL || head->next == NULL || k <= 0) {
        return head;
    }

    // Calculate the length of the linked list
    int length = 0;
    struct Player* current = head;
    while (current->next != NULL) {
        length++;
        current = current->next;
    }
    length++;

    // Calculate the effective rotation count (k % length)
    k = k % length;

    if (k == 0) {
        return head; // No rotation needed
    }

    // Find the new tail and new head
    struct Player* newTail = head;
    struct Player* newHead = head;
    for (int i = 0; i < length - k - 1; i++) {
        newTail = newTail->next;
    }
    newHead = newTail->next;

    // Update the pointers
    newTail->next = NULL;
    current->next = head;

    return newHead;
}

// Function to print the linked list
void printList(struct Player* head) {
    struct Player* current = head;
    while (current != NULL) {
        printf("%d ", current->jerseyNumber);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    // Initialize the linked list
    struct Player* head = (struct Player*)malloc(sizeof(struct Player));
    head->next = NULL;
    struct Player* tail = head;

    // Populate the linked list with player jersey numbers
    for (int i = 0; i < n; i++) {
        int jerseyNumber;
        scanf("%d", &jerseyNumber);

        struct Player* newPlayer = (struct Player*)malloc(sizeof(struct Player));
        newPlayer->jerseyNumber = jerseyNumber;
        newPlayer->next = NULL;

        tail->next = newPlayer;
        tail = newPlayer;
    }

    int k;
    scanf("%d", &k);

    // Print the original list
    printf("Original List: ");
    printList(head->next);

    // Rotate the list to the right by k positions
    struct Player* rotatedList = rotateList(head->next, k);

    // Print the rotated list
    printf("Rotated List: ");
    printList(rotatedList);

    // Free the memory allocated for the linked list nodes
    struct Player* current = rotatedList;
    while (current != NULL) {
        struct Player* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

