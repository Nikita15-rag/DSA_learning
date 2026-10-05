// QUEUE USING ARRAY

#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int f;
    int b;
    int * arr;
};

int isEmpty(struct Queue * q){
    if(q->f == q->b){
        printf("queue is Empty.\n");
        return 1;
    }
}

int isFull(struct Queue * q){
    if(q->b == q->size - 1){
        printf("queue is Full.\n");
        return 1;
    }
}

// Enqueue OP - 1
int enQueue(struct Queue * q, int val){

    // first check if it is full
    if(q->b == q->size - 1){
        printf("Queue Overflow !! can't insert.\n");
        return -1;
    }
    else{
        q->b = q->b+1;
        q->arr[q->b] = val;
        printf("EnQueue operation : %d \n", val);
        //return val;
    }
}

// Dequeue OP - 2
int deQueue(struct Queue * q){
    int a = -1; // points that dequeue failed

    // checks if it is empty
    if(q->f == q->b){
        printf("Queue underflow !! can't remove.\n");
    }
    else{
        q->f = q->f+1;
        a = q->arr[q->f];
        printf("DeQueue Operation : %d \n", a);

    }
    return a;
}

int main(){
    // FIFO
    struct Queue * q1 = (struct Queue *)malloc(sizeof(struct Queue));
    q1->f = -1;
    q1->b = -1;
    q1->size = 3;
    q1->arr = (int *)malloc(q1->size * sizeof(int));

    // Inserting values in the end of array
    enQueue(q1, 11);
    enQueue(q1, 15);
    enQueue(q1, 7);
    //enQueue(q1, 6);

    printf("\n");
    isEmpty(q1);
    isFull(q1);
    printf("\n");
    
    // Removing values from the front of array
    deQueue(q1);
    deQueue(q1);
    deQueue(q1);
    isEmpty(q1);
    free(q1);

    return 0;
}