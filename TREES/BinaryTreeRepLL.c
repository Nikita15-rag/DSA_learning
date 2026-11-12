// LINKED REPRESENTATION OF BINARY TREE //
#include<stdio.h>
#include<stdlib.h>

// creating node
struct node{
    int data;
    struct node * left;
    struct node * right;
};

// creating a func to create internal nodes
struct node * createNode(int data){
    struct node * n;  // creating  a node pointer
    n = (struct node *)malloc(sizeof(struct node));  // Allocating memory in the heap
    n->data = data; // setting data
    n->left = NULL;  // setting left and right child to NULL
    n->right = NULL;
    return n; // finally returning the created node
}


int main(){
    // conatructing the nodes using function
    struct node * p = createNode(2);
    struct node * p1 = createNode(3);
    struct node * p2 = createNode(44);
  //  struct node * p3 = createNode(12);

    // Linking the nodes
    p->left = p1;
    p->right = p2;

    return 0;
}

