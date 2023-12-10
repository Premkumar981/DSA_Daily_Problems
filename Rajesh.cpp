#include <iostream>
using namespace std;
#define TABLE_SIZE 100

int hashTable[TABLE_SIZE];

int midSquareHash(int key) {
    int square = key * key;
    int middleDigits = (square / 100) % 100;
    return middleDigits % TABLE_SIZE;
}

int insert(int key) {
    int index = midSquareHash(key);

    if (hashTable[index] == 0) {
        hashTable[index] = key;
        return index;
    }

    // Linear probing to find the next available slot
    int newIndex = (index + 1) % TABLE_SIZE;
    while (newIndex != index) {
        if (hashTable[newIndex] == 0) {
            hashTable[newIndex] = key;
            return newIndex;
        }
        newIndex = (newIndex + 1) % TABLE_SIZE;
    }

    // Table is full
    return -1;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;

        int index = insert(key);
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != 0) {
            cout << "Index " << i << ": Key " << hashTable[i] << endl;
        }
    }

    return 0;
}

