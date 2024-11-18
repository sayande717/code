#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} binaryTreeNode;

binaryTreeNode* createNode(int inData) {
    binaryTreeNode* newNode = (binaryTreeNode*)malloc(sizeof(binaryTreeNode));
    if(newNode==NULL) {
        exit(EXIT_FAILURE);
    }

    newNode->data = inData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(binaryTreeNode **root, int inData) {
    if((*root) == NULL) {
        (*root) = createNode(inData);
        return;
    }

    binaryTreeNode *currentNode = (*root);
    while (1) {
        /* Process:
            - At each step, check if new node's data is less than or equal to current node's data.
            - If less, then the node must be placed somewhere in the left sub-tree of the current node.
                - If left child is NULL, store as left child.
                - If left child is not NULL, make it current node, then re-check for the condition.
            - This function eventually places the new node at the proper order in the existing tree.
            - It is assumed that the node will eventually be placed.
        */
        if (inData < currentNode->data) {
            if (currentNode->left == NULL) {
                currentNode->left = createNode(inData);
                return;
            }
            currentNode = currentNode->left;
        } else {
            // same check as above, but for inData > currentNode->data
            if (currentNode->right == NULL) {
                currentNode->right = createNode(inData);
                return;
            }
            currentNode = currentNode->right;
        }
    }
}

void recursivePreOrder(binaryTreeNode *root) {
    // BASE Case
    if(root==NULL) {
        return;
    }
    printf("%d ",root->data);
    recursivePreOrder(root->left);
    recursivePreOrder(root->right);
}

void recursiveInOrder(binaryTreeNode *root) {
    // BASE Case
    if(root==NULL) {
        return;
    }
    recursiveInOrder(root->left);
    printf("%d ",root->data);
    recursiveInOrder(root->right);
}

void recursivePostOrder(binaryTreeNode *root) {
    // BASE Case
    if(root==NULL) {
        return;
    }
    
    recursivePostOrder(root->left);
    recursivePostOrder(root->right);
    printf("%d ",root->data);
}

int main() {
    binaryTreeNode *root = (binaryTreeNode *)malloc(sizeof(binaryTreeNode));
    root = createNode(10);
    insertNode(&root,14);
    insertNode(&root,5);
    insertNode(&root,11);
    insertNode(&root,13);
    insertNode(&root,15);
    printf("PreOrder (Recursive): "); recursivePreOrder(root); printf("\n");
    printf("InOrder (Recursive): "); recursiveInOrder(root); printf("\n");
    printf("PostOrder (Recursive): "); recursivePostOrder(root); printf("\n");
    return EXIT_SUCCESS;
}