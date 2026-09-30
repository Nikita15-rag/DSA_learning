#include<stdio.h>
#include<stdlib.h>
 //  LINKED LIST INTRO & CASES OF INSERTION 
/*
struct node{
    int data;
    struct node * next;
};

void linkedListTraversal(struct node * ptr){
    while(ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main(){

    struct node * head ;
    struct node * second ;
    struct node * third ;

    // allocate memory for nodes in hlinked list in heap
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    // link first and second nodes
    head -> data = 6;
    head-> next = second;

    // link second and third nodes
    second -> data = 46;
    second-> next = third;

    //terminate the list at the third node
    third -> data = 16;
    third-> next = NULL;

    linkedListTraversal(head); // O(n)

    return 0;
}*/



// Insertion in linked list

//case 1:insertion at the beginning O(1)
//case 2:insertion in between  O(n)WC / o(1)BC 
//case 3:insertion at the end O(n) 
//case 4:insertion after a node O(1)  


struct node{  
    int data;
    struct node * next;
    };
    
void linkedlisttraversal(struct node * ptr){
    printf("Element:");
    while(ptr != NULL){
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
}

// INSERTION AT BEGINNING
struct node * insertAtBegin(struct node * head, int data){
    // 1st allocate memory for new ptr
    struct node * ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// INSERTION IN BETWEEN
struct node * insertinbetween(struct node * head, int data, int index){
    // 1st allocate memory for new ptr
    struct node * ptr ;
    struct node * p = head;
    ptr = (struct node *)malloc(sizeof(struct node));
  
    int i=0;
    while (i != index-1){
        p = p->next;
        i++;}
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// INSERTION AT THE END
struct node * insertAtEnd(struct node * head, int data){
    struct node * ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p = head;
    while( p->next != NULL ){
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// INSERTION AFTER A NODE
struct node * insertAfterNode(struct node * head,struct node * pervNode, int data){
    struct node * ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = pervNode->next;
    pervNode->next = ptr;
    return head;
}

int main(){
    struct node * new;
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;
    
    // allocate memory in linked list of heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    
    // now linking the nodes
    head->data = 13;
    head->next = second;
    second->data = 12;
    second->next = third;
    third->data = 2;
    third->next = fourth;
    fourth->data = 92;
    fourth->next = NULL;
    
    // Traversing each element
    linkedlisttraversal(head);
    // head = insertAtBegin(head, 10);
    // head = insertAtBegin(head, 190);
    // head = insertinbetween(head, 123, 3);
    // head = insertAtEnd(head, 111);
    // head = insertAfterNode(head,head,675);
    printf("\n");
    linkedlisttraversal(head);
 
    return 0;
}
