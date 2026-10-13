#include<stdio.h>
#include<stdlib.h>

// CLL
// traversal
/*struct node {
    int data;
    struct node * next;
};
void CLLtraverse(struct node * head){
    struct node * ptr = head;
    do{
        printf("element : %d \n" , ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}
// insertion
struct node * insatfirst(struct node * head, int data){
    struct node * ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p = head->next ;
    do{
        p = p->next;
    }while(p->next != head);

    ptr->data = data;
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;    
}

void reverse(struct node **head){
    struct node * prev = NULL;
    struct node * current = *head;
    struct node * next ;
    do{
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;;

    }while(current != *head);
    printf("\n");

    (*head)->next = prev;
    *head = prev;
}

int main(){
    struct node * head = (struct node*)malloc(sizeof(struct node));
    struct node * second = (struct node*)malloc(sizeof(struct node));
    struct node * third = (struct node*)malloc(sizeof(struct node));
    struct node * fourth = (struct node*)malloc(sizeof(struct node));

    head->data = 12;
    head->next = second ;

    second->data = 15;
    second->next = third ;

    third->data = 7;
    third->next = fourth ;

    fourth->data = 6;
    fourth->next = head ;
    CLLtraverse(head); 
    printf("\n");
    //head = insatfirst(head, 122);
    //head = insatfirst(head, 9);
    //head = insatfirst(head, 13);
    reverse(&head);
    CLLtraverse(head);
    return 0;
}
*/
/*
// DOUBLE LINKED LIST 
struct node {
    int data;
    struct node * prev;
    struct node * next;
};

// traverse
void forward(struct node * ptr){
    printf("forward:  ");
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
void backward(struct node * ptr){
    printf("backward:  ");
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->prev;
    }
}

void DLLtraverseBoth(struct node * ptr){

    printf("Both:  ");
    // forward traversal
    while( ptr->next != NULL){
        printf("%d  ",ptr->data);
        ptr = ptr->next;
    }

    // backward traversal
    while(ptr !=NULL ){
        printf(" %d  ", ptr->data);
        ptr = ptr->prev;
        
    }
}
    
int main(){
    struct node * N1 = (struct node*)malloc(sizeof(struct node));
    struct node * N2 = (struct node*)malloc(sizeof(struct node));
    struct node * N3 = (struct node*)malloc(sizeof(struct node));

    N1->prev= NULL ;
    N1->data = 12;
    N1->next = N2 ;

    N2->prev= N1 ;
    N2->data = 6;
    N2->next = N3 ;

    N3->prev= N2 ;
    N3->data = 7;
    N3->next = NULL ;
 
    forward(N1);printf("\n");
    backward(N3);printf("\n");
    DLLtraverseBoth(N1);
    return 0;
}*/

// STACK AND OPERATIONS

struct stack {
    int top;
    int size;
    int * arr;
};

int isfull(struct stack * sp){
    if(sp->top == sp->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isempty(struct stack * sp){
    if(sp->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int push(struct stack * sp,int val){
    if(sp->top == sp->size - 1){
        return 1;
    }
    else{
        return 0;
    }
    sp->top +=1;
    sp->arr[sp->top] = val;
}
int main(){
    struct stack * s;
    s->top = -1;
    s->size = 10;
    s->arr = (int*)malloc(s->size * sizeof(int));
    printf("%d ", isfull(s));
    printf("%d ", isempty(s));
    printf("%d ", push(s,12));

    return 0;
}