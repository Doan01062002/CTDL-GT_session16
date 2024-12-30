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

void preOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);         
    preOrderTraversal(root->left);    
    preOrderTraversal(root->right);   
}

void inOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);     
    printf("%d ", root->data);        
    inOrderTraversal(root->right);    
}

void postOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);   
    postOrderTraversal(root->right);  
    printf("%d ", root->data);       
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Duyet PreOrder: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Duyet InOrder: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Duyet PostOrder: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}

