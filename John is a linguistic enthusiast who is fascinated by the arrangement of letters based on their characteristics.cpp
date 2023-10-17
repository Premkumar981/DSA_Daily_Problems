#include <iostream>
#include <vector>
using namespace std;

bool isVowel(char c) {
    char vowels[] = "aeiouAEIOU";
    for (int i = 0; vowels[i] != '\0'; i++) {
        if (c == vowels[i]) {
            return true;
        }
    }
    return false;
}

void merge(vector<char>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<char> left_half(n1);
    vector<char> right_half(n2);

    for (int i = 0; i < n1; i++) {
        left_half[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++) {
        right_half[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (isVowel(left_half[i]) && !isVowel(right_half[j])) {
            arr[k++] = left_half[i++];
        } else if (!isVowel(left_half[i]) && isVowel(right_half[j])) {
            arr[k++] = right_half[j++];
        } else {
            arr[k++] = left_half[i++];
        }
    }

    while (i < n1) {
        arr[k++] = left_half[i++];
    }

    while (j < n2) {
        arr[k++] = right_half[j++];
    }
}

void mergeSort(vector<char>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;

    vector<char> characters(n);

    for (int i = 0; i < n; i++) {
        cin >> characters[i];
    }

    mergeSort(characters, 0, n - 1);

    for (char c : characters) {
        cout << c << " ";
    }

    return 0;
}
