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


struct Node* LCA(struct Node* root, int n1, int n2) {
    while(root != NULL) {
        if(n1 < root->data && n2 < root->data)
            root = root->left;
        else if(n1 > root->data && n2 > root->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

int main() {
    struct Node* root = createNode(20);
    root->left = createNode(10);
    root->right = createNode(30);
    root->left->left = createNode(5);
    root->left->right = createNode(15);
    root->right->left = createNode(25);
    root->right->right = createNode(35);

    int n1 = 5, n2 = 15;
    struct Node* lca = LCA(root, n1, n2);
    if(lca != NULL)
        printf("LCA of %d and %d is %d\n", n1, n2, lca->data);
    else
        printf("LCA does not exist\n");

    return 0;
}
