#include <iostream>
#include <string>
using namespace std;

void removeDuplicates(string arr[], int& size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                // Shift elements to fill the gap
                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--; // Decrease the size of the array
                j--;    // Adjust the index to recheck the current position
            }
        }
    }
}

int main() {
    const int MAX_SIZE = 100;
    string arr[MAX_SIZE];
    int size;

    // Input the size of the array
    cin >> size;

    // Input the strings in the array
    
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Call the function to remove duplicates
    removeDuplicates(arr, size);

    // Display the updated array
    cout << "Updated array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
