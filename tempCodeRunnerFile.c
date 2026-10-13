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