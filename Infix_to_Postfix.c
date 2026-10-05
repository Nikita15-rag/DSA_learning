#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
    int size;
    int top;
    char * arr;
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

// OP 3
int push(struct stack * ptr, char value){
    if(isFull(ptr)){
        printf("\nStack overflow!! cannot push %d to stack\n",value);
    }
    else {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        return value;
    }    
}

// OP 4
char pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("\nStack underflow!! Cannot pop from stack\n");
        return -1;
    }
    else {
        char value = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        printf("popped value %c \n", value) ;
        return value;
    }     
}

// StackTop
int stackTop(struct stack * sp){
    return sp->arr[sp->top];
}

// Precedence function
int prec(char a){
    if(a == '/' || a == '*'){
        return 3;
    }
    else if(a == '+' || a == '-'){
        return 2;
    }
    else{
        return 0;
    }
}

// IsOperator
int isOperator(char op){
    if(op == '/' || op == '*' || op == '-' || op == '+'){
        return 1;
    }
    else{
        return 0;
    }
}


// INFIX TO POSTFIX
char * InfixToPostfix(char * infix){
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char * postfix  = (char *)malloc((strlen(infix) + 1)* sizeof(char));
    int i = 0; // Track infix traversal
    int j = 0; // Track postfi addition
    while( infix[i] != '\0')
    {
        if( !(isOperator(infix[i]))){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if( prec(infix[i]) > prec(stackTop(sp)) ){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while( !isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    // this function does not tell the validity of expressions 
    char * infix = "a+b/c-d*a";
    printf("the postfix is %s \n\n", InfixToPostfix(infix));

    char * infix1 = "x-y/z-k*d";
    printf("the postfix is %s \n", InfixToPostfix(infix1));
   return 0;
}