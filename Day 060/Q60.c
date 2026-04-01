#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int isMinHeap(struct Node* root) {
    if(root == NULL)
        return 1;

    if(root->left != NULL && root->data > root->left->data)
        return 0;

    if(root->right != NULL && root->data > root->right->data)
        return 0;

    return isMinHeap(root->left) && isMinHeap(root->right);
}

int main() {
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 1;
    root->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct Node*)malloc(sizeof(struct Node));
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;

    if(isMinHeap(root))
        printf("The binary tree is a min-heap.\n");
    else
        printf("The binary tree is not a min-heap.\n");

    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
