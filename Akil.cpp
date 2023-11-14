#include <iostream>
#include <vector>

using namespace std;

int hashFunction(int key, int size) {
    int square = key * key;
    int middleDigits = (square / 10) % 100;
    return middleDigits % size;
}

void storeKeys(int n, vector<int>& keys) {
    vector<int> hashTable(100, -1);

    for (int i = 0; i < n; i++) {
        int key = keys[i];
        int index = hashFunction(key, 100);

        while (hashTable[index] != -1) {
            index = (index + 1) % 100;
        }

        hashTable[index] = key;
    }

    for (int i = 0; i < 100; i++) {
        if (hashTable[i] != -1) {
            cout << "Index " << i << ": Key " << hashTable[i] << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> keys(n);
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    storeKeys(n, keys);

    return 0;
}
