#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct Queue *q)
{
    if (q->f == q->r)
    {
        printf("\nqueue is Empty.\n");
        return 1;
    }
    return 0;
}

int isFull(struct Queue *q)
{
    if (q->r == q->size - 1)
    {
        printf("\nqueue is Full.\n");
        return 1;
    }
    return 0;
}

// Enqueue OP - 1
int enQueue(struct Queue *q, int val)
{

    // first check if it is full
    if (q->r == q->size - 1)
    {
        printf("\nQueue Overflow !! can't insert.\n");
        return -1;
    }
    else
    {
        q->r = q->r + 1;
        q->arr[q->r] = val;
    }
}

// Dequeue OP - 2
int deQueue(struct Queue *q)
{
    int a = -1; // points that dequeue failed

    // checks if it is empty
    if (q->f == q->r)
    {
        printf("\nQueue underflow !! can't remove.\n");
    }
    else
    {
        q->f = q->f + 1;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    // Initializing Queue
    struct Queue  q;
    q.size = 100;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size*(sizeof(int)));

    // BFS Implementation
    int node;
    int i = 2;
    int visited[6] = {0,0,0,0,0,0};
    int a [6][6] = {
        {0,1,1,1,0,0},
        {1,0,1,0,0,0},
        {1,1,0,1,1,0},
        {1,0,1,0,1,0},
        {0,0,1,1,0,1},
        {0,0,0,1,0,0}
    };

    printf("%d ",i);
    visited[i] = 1;
    enQueue(&q, i); // Enqueue i for exploration

    while(!isEmpty(&q)){
        int node = deQueue(&q);
        for (int j = 0; j < 6; j++)
        {
            if(a[node][j] == 1 && visited[j] == 0){
                printf(" %d ",j);
                visited[j] = 1;
                enQueue(&q, j);
            }
        }        
    }

    return 0;
}