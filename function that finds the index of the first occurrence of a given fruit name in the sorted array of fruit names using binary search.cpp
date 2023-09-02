#include <iostream>
using namespace std;

int isFruitPresent(string arr[], int size, string target) {
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

int main() {
    int n;
    cin >> n;

    string arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    string target;
    cin >> target;

    int index = isFruitPresent(arr, n, target);
    if (index != -1) {
        cout << "The first occurrence of \"" << target << "\" is at index " << index << ".";
    } else {
        cout << "\"" << target << "\" is not found in the array." << endl;
    }

    return 0;
}
