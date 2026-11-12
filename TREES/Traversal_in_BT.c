// TRAVERSAL IN A BINARY TREE //
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


// PREORDER TRAVERSAL
void preorder(struct node * root){
    if(root != NULL){
        printf(" %d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// POSTORDER TRAVERSAL
void postorder(struct node * root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf(" %d ", root->data);
    }
}

// INORDER TRAVERSAL
void inorder(struct node * root){
    if(root != NULL){
        inorder(root->left);
        printf(" %d ", root->data);
        inorder(root->right);
    }
}

int main(){
    // conatructing the nodes using function
    struct node * p = createNode(2);
    struct node * p1 = createNode(3);
    struct node * p2 = createNode(44);
    struct node * p3 = createNode(12);
    struct node * p4 = createNode(26);
    
    // tree representtaion of BT
    //       2
    //      / \
    //     3   44
    //    / \  
    //   12  26  
    
   
   // Linking the nodes
   p->left = p1;
   p->right = p2;
   p1->left = p3;
   p1->right = p4;
   
   printf("preOrder traversal: ");
   preorder(p);  // 2  3  12  26  44 

   printf("\n");
   
   printf("postOrder traversal: ");
   postorder(p); // 12  26  3  44  2 
   printf("\n");
   
   printf("inOrder traversal: ");
   inorder(p);   // 12  3  26  2  44 
   printf("\n");

    return 0;
}

