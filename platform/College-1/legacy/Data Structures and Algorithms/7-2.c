#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *left, *right;
};

// initializing a new node and returning it to the caller
struct node* newNode(char data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int height(struct node* node) {
    if (node == NULL) {
        return EXIT_FAILURE;
    } else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if (leftHeight > rightHeight) {
            return (leftHeight + 1);
        } else {
            return (rightHeight + 1);
        }
    }
    return -1;
}

void printCurrentLevel(struct node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%c ", root->data);
    } else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printLevelOrder(struct node* root) {
    int h = height(root);
    for (int iter = 1; iter <= h; iter++) {
        printCurrentLevel(root, iter);
    }
}

int main() {
    char* name = (char*)malloc(sizeof(7));
    printf("Enter name: "); scanf("%s",name);
    struct node *root = newNode(name[0]);
    root->left = newNode(name[1]);
    root->right = newNode(name[2]);
    root->left->left = newNode(name[3]);
    root->left->right = newNode(name[4]);
    root->left->left->left = newNode(name[5]);
    root->left->left->right= newNode(name[6]);
    printLevelOrder(root);
    return EXIT_SUCCESS;
}
