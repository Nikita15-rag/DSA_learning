#include<stdio.h>
#include<stdlib.h>

struct Node{
    int key;
    struct Node* left;
    struct Node* right;
    int height;

};


struct Node* createNode(int key){
    struct Node* node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int getHeight(struct Node * n){
    if(n == NULL){
        return 0;
    }
    return n->height;
}

// BF = height(leftST) - height(rightST)
int getBalanceFactor(struct Node * n){
    if(n == NULL){ return 0;}
    return getHeight(n->left) - getHeight(n->right);
}

/*
            y ->root                      x
          /   \       rightRotate       /   \
         x     t3     ---------->      t1    y
        / \                                 /  \
       t1  t2                              t2   t3
*/


/*
            x ->root                      y
          /   \       leftRotate        /   \
         t1    y      ---------->      x     t3
              / \                     /  \
             t2  t3                  t2   t3
*/

int max(int a, int b){
    return a > b? a : b;
}
// Left Rotate function
struct Node * Rrotate(struct Node * y){
    struct Node * x = y->left; 
    struct Node * t2 = x->right;

    x->right = y;
    y->left = t2;

    // for updating their heights
    y->height = max(getHeight(y->left) , getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left) , getHeight(x->right)) + 1;

    return x; // now x is root that's why it is returned
}

// Right Rotate function
struct Node * Lrotate(struct Node * x){
    struct Node * y = x->right; 
    struct Node * t2 = y->left;

    y->left = x;
    x->right = t2;

    // for updating their heights
    y->height = max(getHeight(y->left) , getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left) , getHeight(x->right)) + 1;

    return y; // now y is root that's why it is returned
}

// Insert function with all four cases(LL,RR,LR,RL)
struct Node * insert(struct Node* node, int key){
    if( node == NULL){
        return createNode(key);
    }
    if(key < node->key){
        node->left = insert(node->left, key);
    }
    else if(key > node->key){
        node->right = insert(node->right, key);
    }
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    

    int BF = getBalanceFactor(node);

    // LL case
    if(BF > 1 && key < node->left->key){
        return Rrotate(node);
    }
    // RR case
    if(BF < -1 && key > node->right->key){
        return Lrotate(node);
    }
    // LR case
    if(BF > 1 && key > node->left->key){
        node->left = Lrotate(node->left);
        return Rrotate(node);
    }
    // RL case
    else if(BF < -1 && key < node->right->key){
        node->right = Rrotate(node->right);
        return Lrotate(node);
    }
    return node;
}

// PREORDER TRAVERSAL
void preorder(struct Node * root){
    if(root != NULL){
        printf(" %d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    struct Node * root = NULL;
    root = insert(root,12);
    root = insert(root,33);
    root = insert(root,51);
    root = insert(root,99);
    root = insert(root,100);
    root = insert(root,2);

    preorder(root);
    return 0;
}