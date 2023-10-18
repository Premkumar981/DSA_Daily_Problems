#include <stdio.h>

void merge(float arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    float Left[n1], Right[n2];

    for (int i = 0; i < n1; i++) {
        Left[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        Right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (Left[i] >= Right[j]) { // Sort in descending order
            arr[k++] = Left[i++];
        } else {
            arr[k++] = Right[j++];
        }
    }

    while (i < n1) {
        arr[k++] = Left[i++];
    }
    while (j < n2) {
        arr[k++] = Right[j++];
    }
}

void mergeSort(float arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    float arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}

