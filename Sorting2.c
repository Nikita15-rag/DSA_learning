//  SELECTION SORT 

#include<stdio.h>

void printArray(int * A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort (int * A, int n){
    int indexOfminO , swap;
    printf("Running selection sort.....\n");
    for(int i = 0; i < n-1 ; i++){  // for no. of passes(n-1)
        indexOfminO = i;
        for(int j = i+1 ; j < n ; j++){ // for comparison of each element
            if ( A[j]  <  A[indexOfminO] )
            {
                indexOfminO = j;
            }
        }
        // Swapping the assumed mini no. with actual mini no. 
        swap = A[i];
        A[i] = A[indexOfminO];
        A[indexOfminO] = swap; 
    }
}

/*
 DRY RUN OF SELECTION SORT ALGO
    (There will be total n-1 passes. 5-1 = 4 in this case!)
     Input Array 
      00  01  02  03  04
     |03, 05, 02, 13, 1
    
     After first pass
      00  01  02  03  04
      02,|05, 03, 13, 1
    
     After second pass
     00  01  02  03  04
     02, 03,|05, 13, 1
    
     After third pass
     00  01  02  03  04
     02, 03, 05,|13, 1
    
     After fourth pass
     00  01  02  03  04
     02, 03, 05, 12,|13
*/

 int main(){
    //     0,  1,  2,  3,  4
    //     2,  4,  1, 89, 44
    int A[] = {2, 4, 1, 89, 44};
    int n = 5;
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);
    return 0;
 }
