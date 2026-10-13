#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// traversal
void traverse(int arr[] , int size){
    for(int i=0; i < size; i++ ){
        printf("%d ", arr[i]);
    }
}



//insert at index in array
int indinsert(int arr[], int tsize, int usize, int val, int index){
    if( usize < index){
        printf("not valid");
    }
    else if(tsize < index){
        printf("not valid2");
    }
    else{
        printf("inserting element...\n");
    }
    for(int i = usize - 1; i >= index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = val;
}

//delete at index in array
void delind(int arr[], int tsize, int usize, int index){
    if( index >= usize || index > tsize){ //OR operator
        printf("can't delete\n");
    }
    else{
        printf("deleting...\n");
        for(int i = index; i <= usize-1 ; i++){
            arr[i] = arr[i+1];
        }
    }
}

// insertion and deletion
void delput(int arr[], int tsize, int usize, int index, int val){
    if(index < 0 || index >= usize || index > tsize){
        printf("can't delete");
    }
    else{
        printf("deleting and inserting...\n");
    }
    for(int i = index; i < usize ; i++){
        arr[i] = arr[index];
    }
    arr[index] = val;
}

// linear search --> sorted & unsorted
int linearsearch(int arr[],int size, int key){
    for(int i = 0; i < size; i++){
        if(arr[i] == key){
            printf("key %d found at index %d \n", arr[i], i);
            return 1;
        }
    }
    printf("key %d not found\n", key);
    return -1;     
} 

// binary search --. sorted
int binarysearch(int arr[], int size, int key){
    int low = 0;
    int high = size - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if( arr[mid] == key){
            return mid;
        }          
        if(arr[mid] < key){
            low = mid + 1;     
        }
        else{
            high = mid - 1;       
        }
    }
    return -1;
}

// reverse string HELLO --> OLLEH
char reverse(char c[20]){
    int a = 0;
    int b = strlen(c) - 1;
    char swap;
    while( a < b ){
        swap = c[a];
        c[a] = c[b];
        c[b] = swap;
        a++;
        b--;        
    }
}

// palindrome MADAM ==> MADAM
int checkpal(char p[]){
    int i = 0 , j = strlen(p) - 1;
    while( i < j){
        if(p[i] != p[j] ){
            printf("not a palindrome\n");
            return 0;
        }
        i++;j--;  
    }
    printf("is a palindrome\n");
    return 1;
}

// Linked list
struct node {
    int data;
    struct node * next;
};

void traversal(struct node * ptr){
    while(ptr != NULL){
        printf("element: %d \n",ptr->data);
        ptr=ptr->next;
    }
}

// insertion
struct node * insatfirst(struct node * head, int data){
    struct node * ptr = head;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct node * insatind(struct node * head, int data, int index){
    struct node * p = head;
    struct node * ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    int i = 0;
    while( i != index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;

}
struct node * insatend(struct node * head, int data){
    struct node * p = head;
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    while(p->next != NULL){
        p=p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
struct node * insafternode(struct node * head, int data,struct node * prev){
    struct node  * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prev->next;
    prev->next = ptr;
    return head;
}


// deletion
struct node * delatfirst(struct node * head){
    struct node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct node * delatindex(struct node * head, int index){
    struct node * p = head;
    struct node * q = head->next;
    for(int i = 0; i < index-1; i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;   
    free(q);    
    return head;
}
struct node * delatend(struct node * head){
    struct node * p = head;
    struct node * q = head->next;
    while( q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
struct node * delgivenNode(struct node * head, int val){
    struct node * p=head;
    struct node * q=head->next;
    while(q->data != val && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}


int main(){
    
        struct node * head = (struct node*)malloc(sizeof(struct node));
        struct node * second = (struct node*)malloc(sizeof(struct node));
        struct node * fourth = (struct node*)malloc(sizeof(struct node));
        struct node * third = (struct node*)malloc(sizeof(struct node));
          
        head->data = 12;
        head->next = second ;
    
        second->data = 15;
        second->next = third ;
    
        third->data = 7;
        third->next = fourth ;

        fourth->data = 6;
        fourth->next = NULL ;
    
        //traversal(head);
        //head = insatfirst(head, 122);  // 122 12 15 7
        //head = insatind(head, 122, 1);  // 12 122 15 7
        //head = insatend(head, 121);    // 12 15 7 121
        //head = insafternode(head, 11,second); // 12 15 11 7
        printf("\n");
        //head = delatfirst(head);  //  15 7
        //head = delatindex(head, 1);  //  12 7
        //head = delatend(head);  //  12 15
        //head = delgivenNode(head, 15);  //  12 15 7 6 --> 12 7 6 
        //traversal(head);

        // CLL traverse
        CLLtraverse(head);



    /*int size = 5;
    int arr[10] = {1,3,5,6,7} ;
    //traverse(arr, size);
    //indinsert(arr,10,7,23,4);
    //size += 1;
    //delind(arr, 10, 7,11);
    traverse(arr, size);
    printf("\n");
    delput(arr, 10, 5, 3, 15);
    traverse(arr, size);*/


    /*char character[20] = "HELLO";
    printf("%s\n",character);
    reverse(character);
    printf("%s", character);
    char check[20] = "MADAaM";
    printf("\n%s is ",check);
    checkpal(check);
    char check1[20] = "poop";
    printf("\n%s is ",check1);
    checkpal(check1);*/

    /*int arr[5] ={1,3,5,23,56};
    linearsearch(arr, 5, 1);
    linearsearch(arr, 5, 3);
    linearsearch(arr, 5, 24);
    linearsearch(arr, 5, 7);
    linearsearch(arr, 5, 5);*/

    /*int arr[6] = {1,3,5,7,9,70};
    int key = 70;
    int key1 = 2;
    int key2 = 7;
    int size = sizeof(arr)/ sizeof(int);
    int searchindex = binarysearch(arr, size, key);
    int searchindex1 = binarysearch(arr, size, key1);
    int searchindex2 = binarysearch(arr, size, key2);
    if( searchindex == -1){
        printf("not found %d\n", key);
    }else{
        printf("the key %d found at index %d \n",key,searchindex);
    }

    if( searchindex1 == -1){
        printf("not found %d\n", key1);
    }else{
        printf("the key %d found at index %d \n",key1,searchindex1);
    }

    if( searchindex2 == -1){
        printf("not found %d\n", key2);
    }else{
        printf("the key %d found at index %d \n",key2,searchindex2);
    }*/
   
    return 0;
}





