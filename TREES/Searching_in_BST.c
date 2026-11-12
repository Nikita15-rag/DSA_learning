#include<stdio.h>
#include<stdlib.h>

struct node {
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

// recursive searching code in bst 
struct node * search(struct node * root, int key){
    // this means no node is there
    if(root == NULL){ return NULL;}  

    // this means key is equals to the data of root
    if(key == root->data){ return root;} 

    // this checks if key is lesser than root data 
    // then it will check in left subtree
    else if( key < root->data)
    {
        return search(root->left, key);
    }

    // this checks if key is greater than root data 
    // then it will check in right subtree
    else 
    {
        return search(root->right, key);
    }
}

// display function
void display(struct node * root, int key){
    if(!search(root, key)){
    printf("the key %d not found in the BST.",key);
   }
   else{
    printf("the key %d found in BST.", key);
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

    search(p, 3);
    display(p, 3);

    search(p, 44);
    display(p, 44);
    return 0;
}