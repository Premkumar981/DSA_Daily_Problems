#include <iostream>
#include <string>
using namespace std;

// Function to swap two strings
void swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

// Function to partition the array
int partition(string names[], int low, int high) {
    string pivot = names[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (names[j] < pivot) {
            i++;
            swap(names[i], names[j]);
        }
    }
    swap(names[i + 1], names[high]);
    return (i + 1);
}

// Function to perform Quick Sort
void quickSort(string names[], int low, int high) {
    if (low < high) {
        int pi = partition(names, low, high);

        quickSort(names, low, pi - 1);
        quickSort(names, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    string names[n];
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }
    quickSort(names, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        cout << names[i] << " ";
    }
    
    return 0;
}

