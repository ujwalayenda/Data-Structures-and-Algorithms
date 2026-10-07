//A system stores unique integer identification numbers using a Binary Search Tree. Write a C
program to insert n values, display inorder, preorder and postorder traversals, search for a
specified value, and report whether it exists. Use the output to explain why inorder traversal
produces sorted values.//
  
#include <stdio.h>
#include <stdlib.h>
// Structure of a BST node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Insert a value into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
// Inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
// Preorder traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
// Postorder traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
// Search for a value
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}
int main() {
    struct Node* root = NULL;
    int n, value, searchValue;
    int i;
    printf("Enter the number of values: ");
    scanf("%d", &n);
    printf("Enter %d unique integer values:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("\nInorder traversal: ");
    inorder(root);
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);
    printf("\n\nEnter value to search: ");
    scanf("%d", &searchValue);
    if (search(root, searchValue) != NULL) {
        printf("%d exists in the Binary Search Tree.\n", searchValue);
    }
    else {
        printf("%d does not exist in the Binary Search Tree.\n", searchValue);
    }
    return 0;
}

//Sample Input:
7
50 30 70 20 40 60 80
60
Sample Output:

Enter the number of values: 7
Enter 7 unique integer values:

Inorder traversal: 20 30 40 50 60 70 80
Preorder traversal: 50 30 20 40 70 60 80
Postorder traversal: 20 40 30 60 80 70 50

Enter value to search: 60
60 exists in the Binary Search Tree.//
