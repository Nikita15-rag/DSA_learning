//   BUBBLE SORT
/*#include<stdio.h>

void printArray(int * A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int * A, int n){
    int temp;
    for(int i = 0; i < n - 1; i++)  // for no. of passes (n-1)
    {
        printf("working on pass no. %d\n", i+1);
        for(int j = 0; j < n-1-i; j++) // for comparisons of each pass
        {
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int * A, int n){
    int temp;
    int isSorted = 0;
    for(int i = 0; i < n - 1; i++)  // for no. of passes (n-1)
    {
        printf("working on pass no. %d\n", i+1);
        isSorted = 1;
        for(int j = 0; j < n-1-i; j++) // for comparisons of each pass
        {
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){ return; }
    }
}

int main(){
    //int A[] = {1, 2, 3, 18, 19};
    int A[] = {1, 2, 3, 23, 18};
    int n = 5;

    printArray(A, n); // printing array before sorting
     bubbleSort(A, n); // Function to sort array
     printArray(A, n); // printing array after sorting
    // bubbleSortAdaptive(A, n); // Function to sort array
    // printArray(A, n); // printing array after sorting

    return 0;
}*/



// INSERTION SORT

/*#include<stdio.h>

void printArray(int * A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int * A, int n){
    int key, j;
    for(int i = 1; i <= n-1; i++){
        key = A[i];   // index of elem to move in sorted array
        j = i - 1;    // elem of array to move
        while( key < A[j] && j >= 0 ){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

 int main(){
    //     0,  1,  2, 3, 4,  5
    //    12, 54, 65, 7, 23, 9
    int A[] = {12,54,65,7,23,9};
    int n = 6;
    printArray(A, n);
    insertionSort(A, n);
    printArray(A, n);
    return 0;
 }*/





// logic building questions for practice
//#include<stdio.h>
//#include<stdlib.h>
//#include <limits.h>
//
//int main(){
//    /*int sum = 0;
//    for(int i = 2;i < 11; i += 2){
//        sum += i;
//    }
//    printf(" Sum of even no. : %d", sum);*/
//
//
//    /*int num , count = 0;
//    printf("Enter number : ");
//    scanf("%d" , &num);
//    printf("the no. of digits in %d is ", num);
//    while(num > 0){
//        count++ ;
//        num = num / 10;
//    }
//    printf("%d ", count);*/
//    
//
//    /*int  n;
//    int rev = 0;
//    printf("Enter no. : ");scanf("%d", &n);printf("%d ", n);
//    while( n != 0){    
//        rev = rev * 10 + n % 10; 
//        n = n / 10;        
//    }
//    printf("%d ", rev);*/
//
//    int arr[5] = {12, 23, 14, 9, 40};
//    int n = 5;
//    int lar = INT_MIN ;
//    int SecLar = INT_MIN ;
//    for(int i = 0; i < n; i++){
//        if(arr[i] > lar){
//            SecLar = lar;
//            lar = arr[i];
//        }
//        else if(arr[i] > SecLar && arr[i] != lar){
//            SecLar = arr[i];
//        }
//    }
//
//    if( SecLar == INT_MIN){
//        printf("second largest no does not exist");
//    }
//    else{
//        printf(" the second largest no.  is : %d.", SecLar);
//    }
//
//    return 0;
//}
