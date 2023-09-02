#include <iostream>
using namespace std;

int findFirstOccurrence(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;  // Look for the first occurrence on the left side
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int findLastOccurrence(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;  // Look for the last occurrence on the right side
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    int firstOccurrence = findFirstOccurrence(arr, n, target);
    int lastOccurrence = findLastOccurrence(arr, n, target);

    if (firstOccurrence != -1 && lastOccurrence != -1) {
        cout << "The first occurrence of " << target << " is at index " << firstOccurrence << "." <<endl;
        cout << "The last occurrence of " << target << " is at index " << lastOccurrence << ".";
    } else {
        cout << "Target value " << target << " is not found in the array." ;
    }

    return 0;
}
