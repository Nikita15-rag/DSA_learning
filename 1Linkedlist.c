#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node * next;
};

void LLtraversal (struct node * ptr){
    while(ptr != NULL){
    printf("%d  ", ptr->data); // 3  4  5
    ptr = ptr->next;
    }
}


int main(){
    struct node * head;
    struct node * second;
    struct node * third;

    //Allocate memory for nodes in LL in heap
    head = (struct node *)malloc(sizeof (struct node));
    second = (struct node *)malloc(sizeof (struct node));
    third = (struct node *)malloc(sizeof (struct node));

    //link 1st and 2nd
    head->data = 3;
    head->next = second;

    //link 2nd and 3rd
    second->data = 4;
    second->next = third;

    //terminate teh node
    third->data = 5;
    third->next = NULL;

    LLtraversal(head);
    return 0;
}
