#include<stdio.h>
#include<stdlib.h>

// create a structure
struct DEQueue{
    int f;
    int b;
    int size;
    int * arr;
};

// Traversal of DEQueue using Array
void traverse(struct DEQueue *q){
    printf("Elements : ");
    for(int i = 0; i <= q->b; i++){
        printf("%d, ", q->arr[i]);
    }
    printf("\n\n");
}

// OP - 1 EnQueue from backend
int enQueueB(struct DEQueue * q, int val){
    // check if queue is full
    if(q->b == q->size-1){
        printf("Queue is full, can not insert from back side.");
        return 1;
    }
    else{
        q->b++;
        q->arr[q->b] = val;
        return q->arr[q->b];
    }

}

// OP - 1.2 EnQueue from frontside
int enQueueF(struct DEQueue * q, int val){

    // check if queue is full
    if(q->f == -1){
        printf("Queue is full, can not insert from front side.");
        return 1;
    }
    else{
        q->arr[q->f] = val;
        q->f--;
        return  val;
    }
}

// OP - 2 DeQueue from frontside
int deQueueF(struct DEQueue * q){
    int val = -1;
    // check if queue is empty 
    if(q->f == q->b){
        printf("Queue is empty, can not delete front value.");
        return 1;
    }
    else{
        q->f++;
        val =  q->arr[q->f];
        printf("DeQueued element : %d\n", val);
        return val;
    }
    return val;
}

// OP - 2.2 DeQueue from backside
int deQueueB(struct DEQueue * q){
    int val = -1;
    // check if queue is empty 
    if(q->f == q->b){
        printf("Queue is empty, can not delete front value.");
        return 1;
    }
    else{
        val =  q->arr[q->b];
        q->b--;
        printf("DeQueued element : %d\n", val);
        return val;
    }
    return val;
}

int main(){
    struct DEQueue * q1 = (struct DEQueue *)malloc(sizeof(struct DEQueue));
    q1->f = -1;
    q1->b = -1;
    q1->size = 5;
    q1->arr = (int *)malloc(q1->size * sizeof(int));

    // Inserting value from back 
    printf("Enqueuing element from back: %d\n", enQueueB(q1,11));
    printf("Enqueuing element from back: %d\n", enQueueB(q1,9));
    printf("Enqueuing element from back: %d\n", enQueueB(q1,90));
    printf("Enqueuing element from back: %d\n", enQueueB(q1,7));
    printf("Enqueuing element from back: %d\n", enQueueB(q1,6));
    traverse(q1);

    // Deleting element from front side
    deQueueF(q1);
    deQueueF(q1);
    
    // Inserting value from front
    printf("Enqueuing element from front: %d\n", enQueueF(q1,12));
    printf("Enqueuing element from front: %d\n", enQueueF(q1,13));
    traverse(q1);

    // Deleting element from back side
    deQueueB(q1);
    traverse(q1);

    return 0;
}