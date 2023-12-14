#include <stdio.h>

int main() {
    int tableSize = 10;
    int numKeys;
    scanf("%d", &numKeys);
    
    int keys[numKeys];
    for (int i = 0; i < numKeys; i++) {
        scanf("%d", &keys[i]);
    }
    
    int hashTable[tableSize];
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1;
    }

    // Allocate seats based on ticket IDs
    for (int i = 0; i < numKeys; i++) {
        int seat = keys[i] % tableSize;

        // Find the next available seat if the current one is occupied
        while (hashTable[seat] != -1) {
            seat = (seat + 1) % tableSize;
        }

        // Assign the seat to the guest
        hashTable[seat] = keys[i];
    }

    // Print seat allocation
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] != -1) {
            printf("Seat Number %d: Ticket ID %d\n", i, hashTable[i]);
        }
    }

    return 0;
}

