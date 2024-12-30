#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findMax(struct Node* root) {
    if (root == NULL) {
        return -1e9; 
    }

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    int maxValue = root->data;
    if (leftMax > maxValue) {
        maxValue = leftMax;
    }
    if (rightMax > maxValue) {
        maxValue = rightMax;
    }
    return maxValue;
}

int main() {
    struct Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->left = createNode(60);
    root->right->right = createNode(70);

    int maxValue = findMax(root);
    printf("Gia tri lon nhat trong cay la: %d\n", maxValue);

    return 0;
}

