#include <stdio.h>
#include <stdlib.h>

// BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new Node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into a BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Function to compare two BSTs
int areIdentical(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;
    return (root1->data == root2->data) && areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right);
}

int main() {
    struct Node* root1 = NULL;
    struct Node* root2 = NULL;

    // Build the first BST (root1)
    int data;
    while (1) {
        scanf("%d", &data);
        if (data == -1)
            break;
        root1 = insert(root1, data);
    }

    // Build the second BST (root2)
    while (1) {
        scanf("%d", &data);
        if (data == -1)
            break;
        root2 = insert(root2, data);
    }

    // Compare the two BSTs
    if (areIdentical(root1, root2))
        printf("Both vehicle fleets are identical\n");
    else
        printf("Vehicle fleets are not identical\n");

    return 0;
}

