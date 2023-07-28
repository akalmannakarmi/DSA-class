#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data= data;
    node->left=NULL;
    node->right=NULL;
    return (node);
}
// postoder traversal
void printPostorder(struct node* node){
    if(node==NULL){
        return;
    }
    // first traversal on left sub tree
    printPostorder(node->left);
    // then traverse on right sub tree
    printPostorder(node->right);
    // now deal with the node
    printf("%d\t",node->data);
}

// inorder
void printInorder(struct node* node){
    if(node == NULL){
        return;
    }
    printInorder(node->left);
    printf("%d\t",node->data);
    printInorder(node->right);
}

// preorder

void printPreorder(struct node* node){
    if(node == NULL){
        return;
    }
    printf("%d\t",node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

// Main
int main(){
    struct node* root = newNode(1);
    root->left= newNode(2);
    root->right= newNode(3);
    root->left->left= newNode(4);
    root->left->right= newNode(5);
    printf("\nPreorder traversal or binary tree is \n");
    printPreorder(root);
    printf("\nInorder traversal or binary tree is \n");
    printInorder(root);
    printf("\nPostorder traversal or binary tree is \n");
    printPostorder(root);
    getchar();
    return 0;
}

