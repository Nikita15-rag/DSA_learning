//  BINARY SEARCH TREE 
// It is a type of binary tree!
// properties of BST
// all nodes of leftsub tree are lesser
// all nodes of rightsub tree are greater
// L and R subtrees are also BST
// there are no duplicate nodes
// inorder traversal of a BST gives an ascending sorted array


//   EXPANATION FOR isBST CODE
/*
prev stores address of previously visited node,
initially null bcuz no node has been visited yet
 
    if(root != NULL)
This checks whether the current node exists.
- If the node exists, continue.
- If the node is NULL, return 1.

   if(!isBST(root->left)){
    return 0;
}
This checks the left subtree first.
-Remember, ! means NOT.
-If the left subtree is not a BST, 
-the function immediately returns 0.


    if(prev != NULL && root->data <= prev->data){
    return 0;
}
This is the MOST IMPORTANT condition.
It checks two things:
1. prev != NULL: A previous node must exist.
2. root->data <= prev->data: Current node's
value must be greater than the previous node's value.
If the current value is smaller than or 
equal to the previous value, the tree is not a BST.

    prev = root;
Now the current node becomes the previous node
for the next comparison.

    return isBST(root->right);
After checking the current node, the 
function checks its right subtree.

    else{
    return 1;
    }
If the root is NULL, return 1 because an empty
subtree is considered a valid BST.
*/

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

// INORDER TRAVERSAL
void inorder(struct node * root){
    if(root != NULL){
        inorder(root->left);
        printf(" %d ", root->data);
        inorder(root->right);
    }
}


// CHECKING IF THE TREE IS BST OR NOT 
int isBST(struct node * root){
    static struct node * prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
/*
       5
      / \
     3   7
    / \
   1   4  

*/
int main(){
    // conatructing the nodes using function
    struct node * p  = createNode(5);
    struct node * p1 = createNode(3);
    struct node * p2 = createNode(2);
    struct node * p3 = createNode(1);
    struct node * p4 = createNode(4);

    // Linking the nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

   printf("inOrder traversal: ");
   inorder(p);   // 1 3 4 5 7
   printf("\n");
   
   printf("%d", isBST(p));

    return 0;
}
