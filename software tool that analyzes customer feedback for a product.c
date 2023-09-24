#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the doubly linked list node
struct Node {
    char identifier[20];
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(char identifier[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->identifier, identifier);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
struct Node* insertAtEnd(struct Node* head, char identifier[]) {
    struct Node* newNode = createNode(identifier);
    if (head == NULL) {
        return newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        return head;
    }
}

// Function to search for a specific entry and replace it with an updated version
struct Node* searchAndReplace(struct Node* head, char searchId[], char updatedId[]) {
    struct Node* current = head;
    while (current != NULL) {
        if (strcmp(current->identifier, searchId) == 0) {
            strcpy(current->identifier, updatedId);
        }
        current = current->next;
    }
    return head;
}

// Function to display the modified list of feedback entries
void displayList(struct Node* head) {
    struct Node* current = head;
    printf("Modified List: ");
    while (current != NULL) {
        printf("%s ", current->identifier);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;

    for (int i = 0; i < n; i++) {
        char identifier[20];
        scanf("%s", identifier);
        head = insertAtEnd(head, identifier);
    }

    char searchId[20];
    char updatedId[20];
    scanf("%s %s", searchId, updatedId);

    head = searchAndReplace(head, searchId, updatedId);

    displayList(head);

    // Free memory
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

