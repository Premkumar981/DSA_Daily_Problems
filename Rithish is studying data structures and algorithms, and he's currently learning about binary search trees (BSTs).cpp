#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    } else {
        Node* cur;
        if (data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
        } else {
            cur = insert(root->right, data);
            root->right = cur;
        }
        return root;
    }
}

void postOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    // Recursively traverse left subtree
    postOrder(root->left);
    // Recursively traverse right subtree
    postOrder(root->right);
    // Print current node's data
    cout << root->data << " ";
}

int getHeight(Node* root) {
    if (root == nullptr) {
        return -1; // Height of an empty tree is -1
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    Node* root = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    cout << "Post-order traversal: ";
    postOrder(root);
    cout << endl;

    int height = getHeight(root);
    cout << "Height of the tree: " << height << endl;

    return 0;
}

