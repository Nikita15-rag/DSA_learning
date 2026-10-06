// CIRCULAR QUEUE

#include<stdio.h>
#include<stdlib.h>

struct Circular_queue {
    int f;
    int b;
    int size;
    int * arr;
};

// Enqueue OP 1
int enQueue(struct Circular_queue * q,int val){
    // checks whether queue is full
    if(((q->b+1) % q->size) == q->f){
        printf("Queue is Overflow !!\n");
        return -1;
    }
    else{
        q->b = ((q->b+1) % q->size);
        q->arr[q->b] = val;
        printf("the enQueued value is: %d\n", val);
        return val;
    }
}

// dequeue OP 2
int deQueue(struct Circular_queue * q){
    int val = -1;
    // checks whether queue is empty
    if(q->f == q->b){
        printf("Queue is Underflow !!\n");
    }
    else{
        q->f = ((q->f+1) % q->size);
        val = q->arr[q->f];
        printf("the deQueued value is: %d\n", val);
        return val;
    }
    return val;
}

int main(){
    struct Circular_queue * q = (struct Circular_queue *)malloc(sizeof(struct Circular_queue));
    q->f = q->b = 0;
    q->size = 5;
    q->arr = (int*)malloc(q->size * sizeof(int));

    // inserting values in queue
    enQueue(q,12);
    enQueue(q,13);
    enQueue(q,14);
    enQueue(q,15);
    enQueue(q,16);
    printf("\n");
    // Removing values from the queue
    deQueue(q);
    deQueue(q);
    printf("\n");
    enQueue(q,16);
    enQueue(q,17);

    return 0;
}