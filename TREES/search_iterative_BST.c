#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

// creating a func to create internal nodes
struct node * createNode(int data){
    struct node * n; 
    n = (struct node *)malloc(sizeof(struct node)); 
    n->left = NULL;  
    n->right = NULL;
    return n; 
}

// iterative searching in BST
struct node * IterSearch(struct node * root, int  key){
    while(root!= NULL){
        if(key == root->data){
            return root;
        }   
        else if( key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}

// display function
void display(struct node * root, int key){
    if(!IterSearch(root, key)){
    printf("the key (%d) not found in the BST.",key);
   }
   else{
    printf("the key (%d) found in BST.", key);
   }
   printf("\n");
}

int main(){
    // constructing the nodes using function
    struct node * p  = createNode(5);
    struct node * p1 = createNode(3);
    struct node * p2 = createNode(6);
    struct node * p3 = createNode(1);
    struct node * p4 = createNode(4);

    // Linking the nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    IterSearch(p, 22);
    display(p, 22);
    IterSearch(p, 4);
    display(p, 4);
    return 0;
}