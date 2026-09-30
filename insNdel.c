// insertion and deletion operation in array simultaneously
#include<stdio.h>

int delput(int arr[], int size, int element, int capacity, int index){
    if (size >= capacity ){
        return -1;
    }

    for(int i = index ; i >= size-1; i++){
        arr[i] = arr[i+1];
    }
    arr[index] = element;
    return 1;
}

void display(int arr[],int size){
    for(int i = 0; i < size ; i++){
        printf("%d   " , arr[i]);
    }
}

int main(){
    int arr[10] = {1,3,5,7,9,11};
    int size = 6, element =233, index = 2;
    display(arr, size);
    printf("\n");
    delput(arr, size, 233, 10, index);
    display(arr, size);

}



// deletion operation in array
/*#include <stdio.h>

int indeletion(int arr[], int size, int index, int capacity)
{
    if (index >= size)
    {
        printf("deletion failed \n");
        return -1;
    }
    else if (size >= capacity)
    {
        return -1;
    }
    else
    {  
        printf("deletion is done successfully\n");
    }
    
    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return 1;
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}

int main()
{
    int arr[10] = {1,3,5,7,9,11};
    int size = 6, index =4;
    display(arr, size);
    printf("\n");
    indeletion(arr, size, index, 10);
    size -= 1;
    display(arr, size);
    return 0;
}*/