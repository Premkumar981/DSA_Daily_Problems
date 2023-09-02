#include <iostream>
#include <string>
using namespace std;

void selectionSort(string* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the current element with the minimum element
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
        
        // Print array after each iteration
        cout << "After Iteration " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    string* arr = new string[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Initial order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr, n);

    cout << "Sorted order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
