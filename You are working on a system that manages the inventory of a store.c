#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for an item record
struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
    struct Item* prev;
    struct Item* next;
};

// Function to create a new item record
struct Item* createItem(int id, char name[], int quantity, float price) {
    struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
    if (newItem == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newItem->id = id;
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->price = price;
    newItem->prev = NULL;
    newItem->next = NULL;
    return newItem;
}

// Function to insert an item at the end of the doubly linked list
struct Item* insertItem(struct Item* head, int id, char name[], int quantity, float price) {
    struct Item* newItem = createItem(id, name, quantity, price);
    if (head == NULL) {
        return newItem;
    } else {
        struct Item* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newItem;
        newItem->prev = current;
        return head;
    }
}

// Function to search for an item by its ID
struct Item* searchItem(struct Item* head, int searchId) {
    struct Item* current = head;
    while (current != NULL) {
        if (current->id == searchId) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Item* head = NULL;

    for (int i = 0; i < n; i++) {
        int id;
        char name[50];
        int quantity;
        float price;
        scanf("%d", &id);
        scanf("%s", name);
        scanf("%d", &quantity);
        scanf("%f", &price);
        head = insertItem(head, id, name, quantity, price);
    }

    int searchId;
    scanf("%d", &searchId);

    struct Item* foundItem = searchItem(head, searchId);

    if (foundItem != NULL) {
        printf("Item with ID %d is present in the list.\n", searchId);
    } else {
        printf("Item with ID %d is not found in the list.\n", searchId);
    }

    // Free memory
    struct Item* current = head;
    while (current != NULL) {
        struct Item* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

