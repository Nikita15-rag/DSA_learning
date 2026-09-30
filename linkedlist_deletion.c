#include<stdio.h>
#include<stdlib.h>

/*
case 1: deleting the 1st node
case 2: deleting a node in between
case 3: deleting the last node
case 4: deleting a node with a given value /key
*/


struct node{
    int data;
    struct node * next;
};

void linkedListTraversal(struct node * ptr){
    printf("Element:");
    while(ptr != NULL){
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
}

// case 1: deleting the 1st node
struct node * delFirstNode(struct node * head){
    struct node * ptr = head ;
    head = head->next;
    free(ptr);
    return head;
}

// case 2: deleting a node in between
struct node * delAtIndex(struct node * head, int index){
    struct node * p = head;
    struct node * q = head->next;
    int i = 0;
    for (int i = 0; i < index - 1; i++){
        p = p->next; 
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// case 3: deleting the last node
struct node * delLastNode(struct node * head){
    struct node * p = head;
    struct node * q = head->next;
    while ( q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
 
// case 4: deleting a node with a given value /key
struct node * delGivenNode(struct node * head, int value){
    struct node * p = head;
    struct node * q = head->next;
    while( q->data != value && q->next != NULL ){
        p = p->next;
        q = q->next;       
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
        printf("\nfound value. deleting....\n");
    }
    else{
        printf("\nnot found value\n");
    }
    return head;
}

int main(){

    struct node * head ;
    struct node * second ;
    struct node * third ;
    struct node * fourth ;

    // allocate memory for nodes in hlinked list in heap
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));

    // linking Nodes
    head -> data = 68;
    head-> next = second;
    second-> next = third;
    second -> data = 46;  
    third -> data = 15;
    third-> next = fourth;
    fourth->data = 92;
    fourth->next = NULL;

    //Printing the outputs
    printf("before deletion operation\n"); 
    linkedListTraversal(head); // O(n)

    // head = delFirstNode(head);
    // head = delAtIndex(head, 0);
    // head = delLastNode(head);
    head = delGivenNode(head,15);

    printf("\nafter deletion operation\n"); 
    linkedListTraversal(head); // O(n)

    return 0;
}
