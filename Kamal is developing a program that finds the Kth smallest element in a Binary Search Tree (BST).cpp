#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Morris Traversal to find the Kth smallest element
int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    int kthSmallest = -1;

    TreeNode* current = root;
    while (current) {
        if (!current->left) {
            count++;
            if (count == k) {
                kthSmallest = current->val;
                break;
            }
            current = current->right;
        } else {
            TreeNode* predecessor = current->left;
            while (predecessor->right && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (!predecessor->right) {
                predecessor->right = current;
                current = current->left;
            } else {
                predecessor->right = nullptr;
                count++;
                if (count == k) {
                    kthSmallest = current->val;
                    break;
                }
                current = current->right;
            }
        }
    }

    return kthSmallest;
}

// Function to insert a value into the BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

int main() {
    TreeNode* root = nullptr;
    int val;

    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        root = insert(root, val);
    }

    int k;
    cin >> k;

    int kthSmallestValue = kthSmallest(root, k);

    cout << "Smallest kth value " << kthSmallestValue << endl;

    return 0;
}

