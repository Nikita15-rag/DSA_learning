//stack is like a container and implementation happens in LIFO order
//fixed size array creatoin , top element

// STACK 

/*#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int * arr;
};

// OP 1
int isEmpty(struct stack *ptr){
    if (ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

// OP 2
int isFull(struct stack *ptr){
    if (ptr->top == ptr->size -1){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){
     struct stack s; //stack
    // struct stack * s; //pointer

    s.size = 5;
    s.top = -1;
    s.arr = (int *)malloc(s.size*sizeof(int));
   // s.arr[0] = 2;s.top++;
   // s.arr[1] = 4;s.top++;
   // s.arr[2] = 7;s.top++;
   // s.arr[3] = 9;s.top++;
   // s.arr[4] = 10;s.top++;

   for (int i = 0; i < s.size; i++){
       printf("Enter the value: ");
       scanf("%d", &s.arr[i]);

       s.top++;
    }

    printf("the values in Stack are: ");

    for (int i = 0; i <= s.top; i++){
        printf("%d  ", s.arr[i]);
    }

    // check if stack is empty
    if(isEmpty(&s)){
        printf("\nThe stack is empty.");
    }
    else{
        printf("\nthe stack is not empty.");
    }
    
    // check if stack is Full 
    if(isFull(&s)){
        printf("\nThe stack is full.");
    }
    else{
        printf("\nThe stack is not full.");
    }
 
    free(s.arr);
    return 0;
}*/



// OPERATIONS ON STACK

#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int * arr;
};

// OP 1
int isEmpty(struct stack * ptr){
    if (ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

// OP 2
int isFull(struct stack * ptr){
    if (ptr->top == ptr->size -1){
        return 1;
    }
    else{
        return 0;
    }
}

// OP 3
int push(struct stack * ptr, int value){
    if(isFull(ptr)){
        printf("\nStack overflow!! \n");
    }
    else {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        return value;
    }    
}

// OP 4
int pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("\nStack underflow!!\n");
    }
    else {
        int value = ptr->arr[ptr->top];
        ptr->arr[ptr->top] ;
        ptr->top = ptr->top-1;
        printf("poped value %d \n", value) ;
    }     
}   
    
// OP 5
int peek(struct stack * p, int i){
    if( (p->top - i + 1) < 0){
        printf("invalid!!");
        return -1;
    }
    else{
        return p->arr[p->top - i + 1];
    }
} 

  
int main(){
    // memory me allocate krane ke liye
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 4;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    printf("%d \n", isFull(s));
    printf("%d \n", isEmpty(s));
    printf("Pushed %d in stack \n",push(s, 12)); 
    printf("Pushed %d in stack \n",push(s, 46)); 
    printf("Pushed %d in stack \n",push(s, 56)); 
    printf("Pushed %d in stack \n",push(s, 23));
    printf("%d\n", isFull(s));
    printf("%d\n\n", isEmpty(s));


   /*printf("%d\n", isFull(s));
    printf("%d\n", isEmpty(s));
    pop(s);  // Last in first out!
    pop(s);  // Last in first out!
    pop(s);  // Last in first out!
    pop(s);  // Last in first out!
    printf("%d\n", isFull(s));
    printf("%d\n", isEmpty(s));*/

    // LIFO method followed 
    for(int j = 1; j <= s->top + 1; j++){
    printf("the value at position %d is %d\n ",j,peek(s,j));
    }
    
    return 0;
}    




