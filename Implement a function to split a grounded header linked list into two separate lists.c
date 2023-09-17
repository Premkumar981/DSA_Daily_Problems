#include <stdio.h>
#include <stdlib.h>

// Define the structure of an employee record
struct Employee {
    int employeeID;
    struct Employee* next;
};

// Function to split the linked list into two lists (even and odd)
void splitLinkedList(struct Employee* head, struct Employee** evenList, struct Employee** oddList) {
    struct Employee* evenHead = NULL;
    struct Employee* oddHead = NULL;
    struct Employee* current = head;

    while (current != NULL) {
        if (current->employeeID % 2 == 0) {
            // Employee ID is even, add to the even list
            if (evenHead == NULL) {
                evenHead = current;
                *evenList = evenHead;
            } else {
                evenHead->next = current;
                evenHead = evenHead->next;
            }
        } else {
            // Employee ID is odd, add to the odd list
            if (oddHead == NULL) {
                oddHead = current;
                *oddList = oddHead;
            } else {
                oddHead->next = current;
                oddHead = oddHead->next;
            }
        }

        current = current->next;
    }

    // Terminate the lists
    if (evenHead != NULL) {
        evenHead->next = NULL;
    }
    if (oddHead != NULL) {
        oddHead->next = NULL;
    }
}

// Function to print a linked list
void printList(struct Employee* head) {
    struct Employee* current = head;

    while (current != NULL) {
        printf("%d ", current->employeeID);
        current = current->next;
    }

    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct Employee* head = NULL;
    struct Employee* tail = NULL;

    for (int i = 0; i < n; i++) {
        int employeeID;
        scanf("%d", &employeeID);

        struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
        newEmployee->employeeID = employeeID;
        newEmployee->next = NULL;

        if (head == NULL) {
            head = newEmployee;
            tail = newEmployee;
        } else {
            tail->next = newEmployee;
            tail = newEmployee;
        }
    }

    struct Employee* evenList = NULL;
    struct Employee* oddList = NULL;

    // Split the linked list into even and odd lists
    splitLinkedList(head, &evenList, &oddList);

    // Print the even and odd lists
    printf("Even List: ");
    printList(evenList);

    printf("Odd List: ");
    printList(oddList);

    // Free the memory allocated for the linked list nodes
    struct Employee* current = head;
    while (current != NULL) {
        struct Employee* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

