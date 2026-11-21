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

// DELETION IN BINARY SEARHC TREE
// CASE 1: DELETE THE LEAF NODE

struct node * inOrderPredecessor(struct node * root){
    root = root->left;
    while( root->right != NULL){
        root = root->right;
    }
    return root;    
}

struct node * deleteNode(struct node * root, int key){
    struct node * iPre;
    // Base case for deletion
    if( root == NULL){
        return NULL;
    }
    if( root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    } 
    // Searching for node to delete
    if(key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    // Deletion strategy when the node is found
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}


int main(){
     // conatructing the nodes using function
    struct node * p  = createNode(5);
    struct node * p1 = createNode(2);
    struct node * p2 = createNode(8);
    struct node * p3 = createNode(1);
    struct node * p4 = createNode(4);
    struct node * p5 = createNode(7);
    struct node * p6 = createNode(10);

    /*
             5    after deletion      5
           /   \                    /   \
          2     8                  2     8
         / \   / \                /     / \
        1   4 7   10             1     7   10
    */

    // Linking the nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    printf("inorder traversal before insertion: \n");
    inorder(p);
    
    p = deleteNode(p, 5);

    printf("\ninorder traversal after insertion: \n");
    //printf("| data is %d for root |", p->data);
    inorder(p);

    return 0;
}