//  SELECTION SORT

#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n)
{
    int indexOfminO, swap;
    printf("Running selection sort.....\n");
    for (int i = 0; i < n - 1; i++)
    { // for no. of passes(n-1)
        indexOfminO = i;
        for (int j = i + 1; j < n; j++)
        { // for comparison of each element
            if (A[j] < A[indexOfminO])
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

// QUICK SORT

int partition(int  A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivot) 
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    // swap A[low] & A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quicksort(int  A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {   partitionIndex = partition(A, low, high);
        printArray(A, 9);
        quicksort(A, low, partitionIndex - 1);  // sort left subarray
        quicksort(A, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    //     0,  1,  2,  3,  4
    //     2,  4,  1, 89, 44
    // int A[] = {2, 4, 1, 89, 44};
    // int n = 5;
    // printArray(A, n);
    // selectionSort(A, n);
    // printArray(A, n);

    //int A[] = {2,4,3,9,1,4,8,7,5,6};
    // int n = 10;
    // printArray(A, n);
    //quicksort(A, 0, n-1);
    // printArray(A, n);
    int A2[] = {2,4,1,9,12,24,5,1,33};
    int n = 9;
    quicksort(A2, 0, n-1);
    return 0;
}
