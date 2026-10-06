#include <stdio.h>
#include <stdlib.h>

struct L
{
    int data;
    struct L *next;
};

// Using f_ptr and b_ptr globally
struct L *f = NULL;  // node pointer 
struct L *b = NULL;  // node pointer

// EnQueue OP 1
int EnQueue(int val)
{
    // check if Queue is full
    struct L *n = (struct L *)malloc(sizeof(struct L));
    if (n == NULL)
    {
        printf("Queue is full.");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        // SPECIAL CASE if f and b both are NULL
        if (f == NULL)
        {
            f = b = n; //  pointing front_ptr & back_ptr to new node n
        }
        else
        {
            b->next = n;
            b = n; // pointing back_ptr to new node n
        }
        return val;
    }
}

// DeQueue OP 2
int deQueue()
{
    int val = -1;
    struct L *ptr = f;
    // check if queue is empty
    if (f == NULL)
    {
        printf("Queue is empty.");
    }
    else
    {
        f = f->next;     // pointing f_ptr to next node
        val = ptr->data; // pointing ptr towards previous f_ptr
        free(ptr);       // to remove the empty space
    }
    return val;
}

int main()
{   //  FIFO PRINCIPLE
    printf("the DeQueued value is: %d\n", deQueue());

    // inserting elements in LL Queue
    printf("the enQueued value is: %d\n", EnQueue(12));
    printf("the enQueued value is: %d\n", EnQueue(7));
    printf("the enQueued value is: %d\n", EnQueue(6));

    printf("the DeQueued value is: %d\n", deQueue()); // 1st 12 will get deleted
    printf("the DeQueued value is: %d\n", deQueue()); // 2nd 7 will get deleted
    printf("the DeQueued value is: %d\n", deQueue()); // 3rd 6 will get deleted

    return 0;
}
