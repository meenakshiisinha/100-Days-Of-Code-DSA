/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// Define the structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to build the binary tree from level-order input
struct TreeNode* buildTree(int* arr, int n) {
    if (n == 0) return NULL;
    struct TreeNode* root = createNode(arr[0]);
    struct TreeNode** queue = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        struct TreeNode* current = queue[front++];
        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }
    free(queue);
    return root;
}
// Function to perform vertical order traversal
void verticalOrderTraversal(struct TreeNode* root, int hd, int* minHd, int
*maxHd) {
    if (root == NULL) return;
    if (hd < *minHd) *minHd = hd;
    if (hd > *maxHd) *maxHd = hd;
    verticalOrderTraversal(root->left, hd - 1, minHd, maxHd);
    verticalOrderTraversal(root->right, hd + 1, minHd, maxHd);
}
void printVerticalOrder(struct TreeNode* root, int hd, int targetHd) {
    if (root == NULL) return;
    if (hd == targetHd) printf("%d ", root->data);
    printVerticalOrder(root->left, hd - 1, targetHd);
    printVerticalOrder(root->right, hd + 1, targetHd);
}
int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct TreeNode* root = buildTree(arr, n);
    free(arr);
    int minHd = INT_MAX, maxHd = INT_MIN;
    verticalOrderTraversal(root, 0, &minHd, &maxHd);
    for (int hd = minHd; hd <= maxHd; hd++) {
        printVerticalOrder(root, 0, hd);
        printf("\n");
    }
    return 0;
}
