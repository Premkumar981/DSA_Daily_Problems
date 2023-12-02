#include <stdio.h>
#define SIZE 100

int calHash(int key, int size) {
    return key % size;
}

int main() {
    int size, numKeys, i;
    scanf("%d", &size);
    scanf("%d", &numKeys);
    int keys[numKeys];
    int hashTable[SIZE];

    for (i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    for (i = 0; i < numKeys; ++i) {
        scanf("%d", &keys[i]);
    }

    for (i = 0; i < numKeys; ++i) {
        int index = calHash(keys[i], size);
        while (hashTable[index] != -1) {
            index = (index + 1) % size;  // Linear probing
        }
        hashTable[index] = keys[i];
        printf("%d ", index);
    }

    return 0;
}

