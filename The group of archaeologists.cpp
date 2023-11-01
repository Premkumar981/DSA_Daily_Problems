#include <stdio.h>

void MaxHeapify(int arr[], int i, int N) {
    int largest = i; // Initialize largest as the root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than the root
    if (left < N && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than the largest so far
    if (right < N && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the root
    if (largest != i) {
        // Swap the root with the largest element
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively MaxHeapify the affected sub-tree
        MaxHeapify(arr, largest, N);
    }
}

void convertMaxHeap(int arr[], int N) {
    for (int i = (N - 2) / 2; i >= 0; --i)
        MaxHeapify(arr, i, N);
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arrayCount;
    scanf("%d", &arrayCount);
    int arr[arrayCount];
    for (int i = 0; i < arrayCount; i++) {
        scanf("%d", &arr[i]);
    }
    convertMaxHeap(arr, arrayCount);
    printArray(arr, arrayCount);
    return 0;
}

