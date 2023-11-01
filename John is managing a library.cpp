#include <stdio.h>
#include <stdlib.h>

struct Book {
    int popularity;
};

void swap(struct Book* a, struct Book* b) {
    struct Book temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(struct Book heap[], int heapSize, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left].popularity > heap[largest].popularity) {
        largest = left;
    }

    if (right < heapSize && heap[right].popularity > heap[largest].popularity) {
        largest = right;
    }

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        maxHeapify(heap, heapSize, largest);
    }
}

void insertBook(struct Book heap[], int* heapSize, struct Book newBook) {
    if (*heapSize == 100) {
        printf("Max heap capacity reached!\n");
        return;
    }

    int i = *heapSize;
    heap[*heapSize] = newBook;
    (*heapSize)++;

    while (i > 0 && heap[(i - 1) / 2].popularity < heap[i].popularity) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printHeap(struct Book heap[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i].popularity);
    }
    printf("\n");
}

int main() {
    struct Book maxHeap[100];
    int heapSize = 0;

    while (1) {
        struct Book newBook;
        if (scanf("%d", &newBook.popularity) != 1) {
            break;
        }
        insertBook(maxHeap, &heapSize, newBook);
    }

    printHeap(maxHeap, heapSize);

    return 0;
}

