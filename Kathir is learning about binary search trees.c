#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

// Function to create and insert nodes into the binary search tree
void append(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL) {
        root = newNode;
    } else {
        struct node* current = root;
        struct node* parent;

        while (1) {
            parent = current;

            if (data < parent->data) {
                current = current->left;

                if (current == NULL) {
                    parent->left = newNode;
                    return;
                }
            } else {
                current = current->right;

                if (current == NULL) {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
}

// Function to calculate the sum of all leaf nodes
void leafSum(struct node* root, int* sum) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        *sum += root->data;
    }

    leafSum(root->left, sum);
    leafSum(root->right, sum);
}

int main() {
    int data, sum = 0;

    do {
        scanf("%d", &data);

        if (data > 0) {
            append(data);
        }
    } while (data > 0);

    leafSum(root, &sum);

    printf("Sum of all leaf nodes are %d\n", sum);

    return 0;
}

