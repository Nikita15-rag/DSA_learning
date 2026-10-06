// STACK TOP -> O(1) AND BOTTOM -> O(1)
// ISFULL(), ISEMPTY() -> O(1)
// POP(() -> O(1), PUSH() -> O(1)
// PEEK() -> O(1)
// push() → adds element at Top
// pop() → removes element from Top
// peek() → looks at element at Top

#include<stdio.h>
#include<stdlib.h>

// STACK_TOP and STACK_BOTTOM

struct stack{
    int top;
    int * arr;
    int size;
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

// OP - 6  
int StackTop(struct stack * s){
    return s->arr[0];
}

// OP - 7 
int StackBottom(struct stack * s){
    return s->arr[s->top];
}

int main(){
    struct stack * s = (struct stack *)malloc(s->size * sizeof(struct stack));
    s->top = -1;
    s->size = 10;
    s->arr = (int *)malloc(s->size * sizeof(int));

    printf("Pushed %d in stack \n",push(s, 12)); 
    printf("Pushed %d in stack \n",push(s, 46)); 
    printf("Pushed %d in stack \n",push(s, 56)); 
    printf("Pushed %d in stack \n",push(s, 23));
    printf("Pushed %d in stack \n",push(s, 19));
    printf("Pushed %d in stack \n",push(s, 7));


    printf("the top most element of stack is %d \n", StackTop(s));
    printf("the Bottom most element of stack is %d \n", StackBottom(s));

    return 0; 
}