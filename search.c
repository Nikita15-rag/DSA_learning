// searching of array --. linear and binary 
/*#include<stdio.h>

int linearSearch(int arr[], int size, int element){
    for( int i = 0; i < size; i++ ){
        if( arr[i] == element ){
            return i;
        }
    }
    return -1;
}

int main(){

    int arr[] = {1,3,66,33,41,2,78,11,56,456};
    int size = sizeof(arr)/sizeof(int);
    int element;
    printf(" enter the element to search in the array \n");
    scanf("%d", &element);  
    //int element = 6;
    int searchindex = linearSearch(arr, size, element);
    if (searchindex == -1){
        printf("the element %d is not found in the array\n", element);
    }
    else{
        printf("the element %d is found at index %d \n", element, searchindex);
    }
    return 0;
}*/


#include<stdio.h>

int binarySearch(int arr[], int size , int element){
    int low =0 , high = size - 1, mid;
    while(low <= high){
    mid = (low + high)/2;
     if (arr[mid] == element){
            return mid;
        }
        else if( arr[mid] < element){
            low = mid +1;
        }
        else{
         high = mid -1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,3,5,7,9,11,13,15,17,19};
    int size = sizeof(arr)/sizeof(int);
    int element;     //int element = 6;
    printf(" enter the element to search in the array ");
    scanf("%d", &element);  
    
    int searchindex = binarySearch(arr, size, element);
    if (searchindex == -1)
    {printf("the element %d is not found in the array\n", element);}
    else
    {printf("the element %d is found at index %d \n", element, searchindex);}
    return 0;
}