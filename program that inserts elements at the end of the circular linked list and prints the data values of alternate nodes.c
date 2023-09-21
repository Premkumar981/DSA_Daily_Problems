#include <stdio.h>
#include <stdlib.h>

// Define a structure for the circular linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = head;
    }
    return head;
}

// Function to print alternate nodes of the circular linked list
void printAlternateNodes(struct Node* head) {
    if (head == NULL) {
        printf("Linked List is empty.\n");
        return;
    }

    struct Node* current = head;
    int isEven = 0; // To track if the node is at an even or odd position

    printf("Alternate Nodes: ");
    do {
        if (isEven % 2 == 0) {
            printf("%d ", current->data);
        }
        current = current->next;
        isEven++;
    } while (current != head);

    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, data;

    // Input elements to be inserted at the end of the circular linked list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }

    // Print alternate nodes of the circular linked list
    printAlternateNodes(head);

    // Free memory
    if (head != NULL) {
        struct Node* current = head->next;
        while (current != head) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
        free(head);
    }

    return 0;
}

