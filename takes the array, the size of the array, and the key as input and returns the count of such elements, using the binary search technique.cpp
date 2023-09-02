#include <iostream>
using namespace std;

int binarySearchCount(int arr[], int n, int key)
{
    int left = 0, right = n;

    int mid;
    while (left < right) {
        mid = (right + left) >> 1;

        if (arr[mid] == key) {
            while (mid + 1 < n && arr[mid + 1] == key)
                mid++;
            break;
        }
        else if (arr[mid] > key)
            right = mid;
        else
            left = mid + 1;
    }

    while (mid > -1 && arr[mid] > key)
        mid--;

    return mid + 1;
}

int main()
{
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cin >> key;

    int count = binarySearchCount(arr, n, key);
    cout << count << endl;

    delete[] arr;

    return 0;
}

