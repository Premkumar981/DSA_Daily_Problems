#include <iostream>
using namespace std;

// Define the structure of a binary tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the binary search tree
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to perform post-order traversal and display items in the cart
void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    // Recursively traverse left and right subtrees
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    // Print the value of the current node
    cout << root->value << " ";
}

int main() {
    TreeNode* root = nullptr;
    int productId;
    
    // Read product IDs until -1 is entered and insert them into the binary search tree
    while (true) {
        cin >> productId;
        if (productId == -1) {
            break;
        }
        root = insert(root, productId);
    }
    
    // Perform post-order traversal and display items in the cart
    cout << "Post order Traversal: ";
    postOrderTraversal(root);
    cout << endl;
    
    return 0;
}

