//  DOUBLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int data;
    struct node * prev;
    struct node * next;
};

// DLL TRAVERSAL

void DLLtraverseFW(struct node * ptr){

    printf("Forwward traversal:");
    while(ptr != NULL){
        printf(" %d  ",ptr->data);
        ptr = ptr->next;
    }printf("\n");    

}

void DLLtraverseBW(struct node * ptr){

    printf("Backward traversal: ");
    while(ptr != NULL){
        printf("%d   ", ptr->data);
        ptr = ptr->prev;
    }printf("\n");

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
    }printf("\n");

}

int main(){
   
    //Allocate memory
    struct node *  N1 = (struct node *)malloc(sizeof(struct node));
    struct node *  N2 = (struct node *)malloc(sizeof(struct node));
    struct node *  N3 = (struct node *)malloc(sizeof(struct node));
    struct node *  N4 = (struct node *)malloc(sizeof(struct node));

    // linking nodes and assigning values
    N1->next = N2;
    N1->prev = NULL;
    N1->data = 12;

    N2->next = N3;
    N2->prev = N1;
    N2->data = 35;

    N3->next = N4;
    N3->prev = N2;
    N3->data = 16;

    N4->next = NULL;
    N4->prev = N3;
    N4->data = 23;

    // displaying list
    DLLtraverseFW(N1);
    DLLtraverseBW(N4);
    DLLtraverseBoth(N1);
    return 0;

}

