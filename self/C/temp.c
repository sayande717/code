#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} node;

int height(node* head) {
    if(head==NULL) {
        return EXIT_FAILURE;
    }
    int left_height = height(head->left);
    int right_height = height(head->right);
    if(left_height>right_height) {
        return(left_height+1);
    } else {
        return(right_height+1);
    }
}

int main() {
    int data;
    printf("Enter data: "); scanf("%d",&data);
    node* head = create_node(data);
    print_nodes(head);
    
    free(head);
    printf("\n");
    return EXIT_SUCCESS;
}