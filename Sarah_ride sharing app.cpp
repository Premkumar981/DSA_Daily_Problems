#include <stdio.h>
#include <stdlib.h>

struct RideRequest {
    int estimatedPickUpTime;
};

void swap(struct RideRequest* a, struct RideRequest* b) {
    struct RideRequest temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert a new ride request into the min heap based on estimated pick-up time
void insertRideRequest(struct RideRequest heap[], int* heapSize, struct RideRequest newRequest) {
    (*heapSize)++;

    int i = (*heapSize) - 1;
    heap[i] = newRequest;

    while (i > 0 && heap[(i - 1) / 2].estimatedPickUpTime > heap[i].estimatedPickUpTime) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printHeap(struct RideRequest heap[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i].estimatedPickUpTime);
    }
    printf("\n");
}

int main() {
    struct RideRequest minHeap[100];
    int heapSize = 0;

    while (1) {
        struct RideRequest newRequest;
        if (scanf("%d", &newRequest.estimatedPickUpTime) != 1) {
            break;
        }

        insertRideRequest(minHeap, &heapSize, newRequest);
    }
    printHeap(minHeap, heapSize);

    return 0;
}
