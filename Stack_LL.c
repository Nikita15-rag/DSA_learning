// STACK USING LINKED LIST

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int top;
    struct node * next;
};

// Traversal
int LinkedListTraversal(struct node * top){
    struct node * ptr = top;
    printf("Elements : ");
    while(ptr != NULL){
        printf("%d , ",ptr->data);
        ptr = ptr->next;
    }
}

// OP - 1
int isEmpty(struct node * top){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

// OP - 2
int isFull(struct node * top){
    struct node * p ;
    p = (struct node*)malloc(sizeof(struct node));
    if(p == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

// OP - 3
int pop(struct node ** top){
    if (isEmpty(*top)){
        printf("Stack Underflow \n");
    }
    else{
        struct node * n = (*top) ;
        (*top) = (*top)->next;
        int x = (n)->data ;
        free(n);
        return x;
    }
}

// OP - 4
struct node * push(struct node * top,int value){
    if(isFull(top)){
        printf("Stack Overflow !!\n");
    }
    else{
        struct node * n = (struct node *)malloc(sizeof(struct node));
        int x = value;
        n->data = x;
        n->next = top;
        top = n;
    }
    return top;
}

// OP - 5
int peek(struct node * top, int pos){
    struct node * ptr = top;
    for(int i = 0; (i < pos-1 && ptr != NULL); i++){
        ptr = ptr->next;
    }
    if(ptr != NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}

// OP - 6
int StackTop(struct node * top){
    return top->data;
}

// OP - 7
int StackBottom(struct node * top){
    struct node * ptr = top;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    return ptr->data;
}

int main(){
    struct node* top  = NULL;
    printf("PUSH \n");
    top = push(top, 23);
    top = push(top, 16);
    top = push(top, 7);
    top = push(top, 6);
    LinkedListTraversal(top);
    printf("\n");

    
    printf("\nPOP \n");
    int element = pop(&top);
    printf("the popped element is : %d\n", element);
    LinkedListTraversal(top);
    printf("\n");

    printf("\nPEEK \n");
    printf("the value at postion 1 is : %d \n",peek(top, 1));
    printf("the value at postion 2 is : %d \n",peek(top, 2));
    printf("the value at postion 3 is : %d \n",peek(top, 3));
    printf("\n");
  
    printf("STCAKTOP \n");
    int st = StackTop(top);
    printf("the value at top of the LL is %d\n",st);
    printf("\n");
    
    printf("STCAKBOTOM \n");
    int sb = StackBottom(top);
    printf("the value at bottom of the LL is %d\n",sb);
    printf("\n");

    return 0;
}