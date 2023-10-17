#include <stdio.h>
#include <limits.h> // Include for INT_MIN

#define MAX_ARRAY_LENGTH 100

void merge_descending(char arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char Left[n1], Right[n2];

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

void mergeSortDescending(char arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortDescending(arr, left, mid);
        mergeSortDescending(arr, mid + 1, right);

        merge_descending(arr, left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char arr[MAX_ARRAY_LENGTH]; // Assuming a maximum array length

    for (int i = 0; i < n; i++) {
        scanf(" %c", &arr[i]);
    }

    mergeSortDescending(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");

    return 0;
}

