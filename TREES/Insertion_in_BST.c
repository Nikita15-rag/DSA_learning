#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

// creating a func to create internal nodes
struct node * createNode(int data){
    struct node * n; 
    n = (struct node *)malloc(sizeof(struct node)); 
    n->data = data;  
    n->left = NULL;  
    n->right = NULL;
    return n; 
}

// INORDER TRAVERSAL
void inorder(struct node * root){
    if(root != NULL){
        inorder(root->left);
        printf(" %d ", root->data);
        inorder(root->right);
    }
}

//  INSERTION CODE IN BST 
void insertion(struct node * root, int key){
    struct node * prev = NULL;
    while( root != NULL){
        prev = root;
        if(key == root->data){
            printf("\nCannot insert key %d , already in tree.\n", key);
            return;
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node * newPtr = createNode(key);
    if(key < prev->data){
        prev->left = newPtr;
    }
    else{
        prev->right = newPtr;
    }

}

int main(){
    // conatructing the nodes using function
    struct node * p  = createNode(5);
    struct node * p1 = createNode(2);
    struct node * p2 = createNode(8);
    struct node * p3 = createNode(1);
    struct node * p4 = createNode(4);

    /*
            5    after insertion     5
           /  \                    /   \
          2    8                  2     8
         / \                     / \   / \
        1   4                   1   4 7   10
    */

    // Linking the nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    printf("inorder traversal before insertion: ");
    inorder(p);

    insertion(p, 7);
    insertion(p, 1);
    insertion(p, 10);
    //printf("%d \n", p->right->left->data);
    printf("inorder traversal after insertion: ");
    inorder(p);

    return 0;
}
