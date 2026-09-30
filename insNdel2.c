/* #include<stdio.h>
#include<stdlib.h>
struct myarray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createmyarray(struct myarray *a,  int tsize, int usize)
{
    //(*a).total_size = tsize;
    //(*a).used_size = usize;
    //(*a).ptr = (int*) malloc(tsize * sizeof(int));

    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize * sizeof(int));
}

void setval(struct myarray * a)
{  int n;
    for(int i = 0; i < a->used_size; i++)
    {
        printf("enter element %d" , i);
        scanf("%d" , &n);
        (a->ptr)[i] = n;
    }
   
}


void show(struct myarray * a){
    for(int i = 0; i < a->used_size; i++){
        printf("%d\n" , (a->ptr)[i]);
    }
}

int main(){

    struct myarray marks;
   createmyarray(&marks ,10, 4);
   printf("we are running setval now\n");
   setval(&marks);
   printf("we are running show now\n");
   show(&marks);
    return 0;
}*/


#include <stdio.h>

/// TRAVERSAL OPERATION IN ARRAY
void display(int arr[], int n)
{
    for(int i = 0; i < n; i++){
        printf("%d  " , arr[i]);
    }
}

/// INSERTION OPERATION IN ARRAY
int indInsertion(int arr[], int size , int element/*to add the new element*/ , int capacity, int index/*to put it at given index*/){
    if (size < index){
        printf("insertion failed\n");
        return -1;
    }
    else if(size >= capacity)
    {
        return -1;
    }
    else{
        printf("\nthe insertion is done successfully\n");
    }
    for(int  i = size - 1; i >= index ; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main(){
    int arr[100] = {7, 8, 12, 28, 88}; //
    int size = 5 , element =34 ,index = 4 ;
    display(arr , size);
    printf("\n");
    indInsertion(arr, size , element , 100, index);
    size += 1;
    display(arr , size);
    return 0;
}