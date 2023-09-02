#include <iostream>
using namespace std;

bool isValuePresent(int arr[], int size, int targetValue) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == targetValue) {
            return true;
        }
    }
    return false;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int targetValue;
    cin >> targetValue;

    bool isPresent = isValuePresent(arr, size, targetValue);

    if (isPresent) {
        cout << "The target value " << targetValue << " is present in the array." << endl;
    } else {
        cout << "The target value " << targetValue << " is not present in the array." << endl;
    }

    delete[] arr;
    return 0;
}
