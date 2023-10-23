#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

bool searchKey(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == key) {
        return true;
    } else if (key < root->data) {
        return searchKey(root->left, key);
    } else {
        return searchKey(root->right, key);
    }
}

int main() {
    Node* root = nullptr;
    int numNodes, value, key;
    cin >> numNodes;

    for (int i = 0; i < numNodes; i++) {
        cin >> value;
        root = insertNode(root, value);
    }

    cin >> key;

    if (searchKey(root, key)) {
        cout << "The key " << key << " is found in the binary search tree" << endl;
    } else {
        cout << "The key " << key << " is not found in the binary search tree" << endl;
    }

    return 0;
}

