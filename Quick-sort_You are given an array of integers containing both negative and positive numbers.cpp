#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to rearrange negatives before positives while maintaining relative order
void rearrangeNegativesBeforePositives(int arr[], int n) {
    int negativeIndex = 0;
    
    // Move all negative numbers to the beginning of the array
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            swap(&arr[i], &arr[negativeIndex]);
            negativeIndex++;
        }
    }
}

// Standard Quick Sort partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    rearrangeNegativesBeforePositives(arr, n);
    quickSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    free(arr); // Free the dynamically allocated memory
    return 0;
}

