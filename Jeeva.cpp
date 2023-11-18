#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the initial index using the division method
int calcHash(int key, int size) {
    return key % size;
}

// Function to insert keys into the hash table using linear probing
void insertKeys(vector<int>& hashTable, int size, vector<int>& keys) {
    for (int i = 0; i < keys.size(); ++i) {
        int key = keys[i];
        int index = calcHash(key, size);

        // Linear probing to resolve collisions
        while (hashTable[index] != -1) {
            index = (index + 1) % size;
        }

        hashTable[index] = key;
    }
}

int main() {
    int size, n;
    cin >> size;  // Size of the hash table
    cin >> n;     // Number of keys

    vector<int> keys(n);
    for (int i = 0; i < n; ++i) {
        cin >> keys[i];
    }

    // Initialize hash table with -1 to represent empty slots
    vector<int> hashTable(size, -1);

    // Insert keys into the hash table using linear probing
    insertKeys(hashTable, size, keys);

    // Create a vector of pairs to store index-key pairs for sorting
    vector<pair<int, int>> indexKeyPairs;
    for (int i = 0; i < size; ++i) {
        if (hashTable[i] != -1) {
            indexKeyPairs.push_back({i, hashTable[i]});
        }
    }

    // Sort the vector of pairs based on the index
    sort(indexKeyPairs.begin(), indexKeyPairs.end());

    // Output the result
    for (auto& pair : indexKeyPairs) {
        cout << "index: " << pair.first << ", value: " << pair.second << endl;
    }

    return 0;
}
