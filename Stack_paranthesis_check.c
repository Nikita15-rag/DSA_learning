/*

// SINGLE TYPE PARANTHESIS MATCHING

#include<stdio.h>
#include<stdlib.h>

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
    }
    else {
        char value = ptr->arr[ptr->top];
        ptr->top = ptr->top-1;
        printf("popped value %c \n", value) ;
    }     
}

// OP 5
int paranthesisMatch(char * exp){

    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
   
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for(int i = 0; exp[i] != '\0';i++)
    {
        if(exp[i] == '(')
        {
            push(sp,'(');
        }
        else if(exp[i] == ')')
        {
            if(isEmpty(sp)){ return 0; }
            else{ pop(sp); }
        }
    }

    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;;
    }
}

int main(){
    // this function does not tell the validity of expressions 
    char * exp = "((2) * (9))";
    if(paranthesisMatch(exp)){
        printf("the paranthesis is matching");
    }
    else{
        printf("the paranthesis is not matching");
    }
   return 0;
} */




// MULTIPLE PARANTHESIS MATCHING

#include<stdio.h>
#include<stdlib.h>

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
    }
    else {
        char value = ptr->arr[ptr->top];
        ptr->top = ptr->top-1;
        printf("popped value %c \n", value) ;
        return value;
    }     
}

// MATCH FUNCTION

char match(char a, char b){
    if(a == '}' && b == '{'){
        return 1;
    }
    if(a == ')' && b == '('){
        return 1;
    }
    if(a == ']' && b == '['){
        return 1;
    }
    return 0;
}



// OP 5
int paranthesisMatch(char * exp){

    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
   
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;

    for(int i = 0; exp[i] != '\0';i++)
    {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{' )
        {
            push(sp,exp[i]);
        }
        else if(exp[i] == ')' ||  exp[i] == ']' || exp[i] == '}'  )
        {
            if(isEmpty(sp))
            { 
                return 0; 
            }

            popped_ch = pop(sp); 

            if( !match( exp[i] , popped_ch ))
            {
                return 0;
            }
        }
    }

    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;;
    }
}

int main(){
    // this function does not tell the validity of expressions 
    char * exp = "{2 * [(3 - 6) + 9]}";
    
    if(paranthesisMatch(exp)){
        printf("the paranthesis is matching\n");
    }
    else{
        printf("the paranthesis is not matching\n");
    }
    
    char * exp1 = "{2 * [3 - 6) + 9]}";
    if(paranthesisMatch(exp1)){
        printf("the paranthesis is matching\n");
    }
    else{
        printf("the paranthesis is not matching\n");
    }
   return 0;
}