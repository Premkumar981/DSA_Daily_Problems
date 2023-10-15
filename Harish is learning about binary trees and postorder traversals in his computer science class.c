#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int ans[MAX_NODES];
int idx = 0;

struct TreeNode* createNode(int x) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void postorder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // Recursively traverse left subtree
    postorder(root->left);

    // Recursively traverse right subtree
    postorder(root->right);

    // Visit the current node and store its value in the ans array
    ans[idx++] = root->val;
}

void fillArray(struct TreeNode* root) {
    postorder(root);
}

int* postorderTraversal(struct TreeNode* root) {
    fillArray(root);
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Create the binary tree based on the input array
    struct TreeNode* root = createNode(arr[0]);
    struct TreeNode* nodes[n];
    nodes[0] = root;

    for (int i = 1; i < n; i++) {
        struct TreeNode* node = createNode(arr[i]);
        nodes[i] = node;

        // Determine the parent of the current node and attach it
        struct TreeNode* parent = nodes[(i - 1) / 2];
        if (i % 2 == 1) {
            parent->left = node;
        } else {
            parent->right = node;
        }
    }

    // Perform postorder traversal and store the result in ans
    postorder(root);

    // Print the postorder traversal
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}

