#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// Function to check if an array represents an inorder traversal of a BST
bool isValidInorder(int arr[], int n) {
    int i, prev = INT_MIN;

    for (i = 0; i < n; i++) {
        // If the current element is smaller than the previous one, it's not a valid BST
        if (arr[i] <= prev) {
            return false;
        }
        prev = arr[i];
    }

    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isValidInorder(arr, n)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

