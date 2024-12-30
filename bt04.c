#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool search(struct Node* root, int target) {
    if (root == NULL) {
        return false; 
    }
    if (root->data == target) {
        return true;
    }
    return search(root->left, target) || search(root->right, target);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int target;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &target);

    if (search(root, target)) {
        printf("Gia tri %d duoc tim thay trong cay.\n", target);
    } else {
        printf("Gia tri %d không ton tai trong cay.\n", target);
    }

    return 0;
}

