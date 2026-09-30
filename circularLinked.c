#include<stdio.h>
#include<stdlib.h>

// Circular Linked List

struct node{
    int data;
    struct node * next;
};

void linkedListTraversal(struct node * head){
    struct node * ptr = head;
    do{
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    while(ptr != head);
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




// Insertion case 1:
struct node * insertAtFirst(struct node * head, int data)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p = head->next;
    while(p->next != head)
    {
        p = p->next;
    }
    // at this point p points to the last node of CLL
    ptr->data = data;
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

// Insertion case 2:
struct node * insertAtindex(struct node * head,int data, int index){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p = head;
    int i = 0;
    while ( i < index - 1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;    
}

// Insertion case 3:
struct node * insertAtEnd(struct node * head,int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p = head->next;
    while (p->next != head){
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = head;
    return head;    
}

// Insertion case 4:
struct node * insertAtNode(struct node * head,int data,struct node * node){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = node->next;
    node->next = ptr;
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

    // link first and second nodes
    head -> data = 4;
    head-> next = second;
    // link second and third nodes
    second -> data = 3;
    second-> next = third;
    //link third and fourth node
    third -> data = 6;
    third-> next = fourth; 
    // link first and fourth node
    fourth -> data = 1;
    fourth-> next = head;

    linkedListTraversal(head); // O(n)
    printf("\n");
    // head = insertAtFirst(head, 14);
    // head = insertAtFirst(head, 34);
    // head = insertAtindex(head, 123, 2);
    // head = insertAtindex(head, 23, 3);
    // head = insertAtEnd(head, 15);
    // head = insertAtNode(head, 15,head);
    //linkedListTraversal(head); // O(n)
    
    reverse(&head); // O(n)
    linkedListTraversal(head); // O(n)
   
    return 0;
}