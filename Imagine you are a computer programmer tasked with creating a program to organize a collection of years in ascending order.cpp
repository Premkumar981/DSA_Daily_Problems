#include <iostream>
#include <string>
using namespace std;

// Function to swap two years
void swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

// Function to partition the array of years
int partition(string arr[], int low, int high) {
    string pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Function to perform Quick Sort on the array of years
void quickSort(string arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to perform recursive Quick Sort
void recursiveQuickSort(string arr[], int n) {
    quickSort(arr, 0, n - 1);
}

int main() {
    int n;
    cin >> n;
    string years[n];
    for (int i = 0; i < n; i++) {
        cin >> years[i];
    }
    recursiveQuickSort(years, n);
    
    for (int i = 0; i < n; i++) {
        cout << years[i] << " ";
    }
    
    return 0;
}
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

