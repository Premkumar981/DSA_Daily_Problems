#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderTraversal(TreeNode* root, vector<int>& inorder) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right, inorder);
}

int minSwaps(vector<int>& inorder) {
    vector<pair<int, int>> arrWithIndex;
    int n = inorder.size();

    for (int i = 0; i < n; i++) {
        arrWithIndex.push_back({inorder[i], i});
    }

    sort(arrWithIndex.begin(), arrWithIndex.end());

    vector<bool> visited(n, false);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || arrWithIndex[i].second == i) {
            continue;
        }

        int cycle_size = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;
            j = arrWithIndex[j].second;
            cycle_size++;
        }

        if (cycle_size > 0) {
            ans += (cycle_size - 1);
        }
    }

    return ans;
}

// Function to build an unordered binary tree
TreeNode* buildTree(vector<int>& values, int& index) {
    if (index >= values.size() || values[index] == -1) {
        index++;
        return NULL;
    }

    TreeNode* root = new TreeNode(values[index++]);
    root->left = buildTree(values, index);
    root->right = buildTree(values, index);

    return root;
}

int main() {
    int n;
    cin >> n;

    vector<int> values(n);

    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int index = 0;
    TreeNode* root = buildTree(values, index);

    vector<int> inorder;
    inorderTraversal(root, inorder);

    int swaps = minSwaps(inorder);
    cout << swaps << endl;

    return 0;
}

