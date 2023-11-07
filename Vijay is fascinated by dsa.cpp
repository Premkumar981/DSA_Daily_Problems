// You are using GCC
#include <stdio.h>
#define MAX_SIZE 100

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void deleteRoot(int arr[], int *n) {
    if (*n <= 0) {
        return; // Nothing to delete
    }

    // Replace the root with the last element
    arr[0] = arr[*n - 1];
    (*n)--;

    // Heapify the updated array
    heapify(arr, *n, 0);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[MAX_SIZE];

    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    buildMaxHeap(arr, n);
    deleteRoot(arr, &n);
    printArray(arr, n);

    return 0;
}

