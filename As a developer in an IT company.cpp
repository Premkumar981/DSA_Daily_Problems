#include <stdio.h>

void MaxHeapify(int arr[], int i, int N) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < N && arr[left] > arr[largest])
        largest = left;
    
    if (right < N && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
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
    
    printf("%d\n", arr[0] + arr[arrayCount - 1]);
    
    return 0;
}

