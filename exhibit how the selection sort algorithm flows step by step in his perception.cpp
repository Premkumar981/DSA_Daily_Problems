#include <iostream>
using namespace std;
void selectionSort(int arr[], int n) {
    int min_idx;

    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in the unsorted array
        min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        cout << "After his step: " << (i + 1) << endl;
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    selectionSort(arr, n);

    cout << "Finally, he got it" << endl;
    printArray(arr, n);

    delete[] arr;

    return 0;
}
