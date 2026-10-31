/*#include<stdio.h>

void printArray(int A[], int n){
    for(int i = 0; i < n; i++){
        printf("%d  ", A[i]);
    }
    printf("\n");
}


// MERGING TWO SORTED ARRAYS
void mergeSort( int A[], int B[], int C[], int m, int n){
    int i,j,k;
    i = j = k = 0;
    while(i < m && j < n){
        if(A[i] < B[j]){
            C[k] = A[i];
            i++;k++;
        }
        else{
            C[k] = B[j];
            j++;k++;
        }
    }
    // Copying elements of A array
    while( i < m){
        C[k] = A[i];
        i++;k++;
    }
    // Copying elements of B array
    while( j < n){
        C[k] = B[j];
        j++;k++;
    }
}

// MERGING IN A SINGLE ARRAY
void merge( int A[], int low, int mid, int high){
    int i,j,k, B[20];
    i = low;
    j = mid + 1;
    k = low;
    while(i <= mid && j <= high){
        if(A[i] < A[j]){
            B[k] = A[i];
            i++;k++;
        }
        else{
            B[k] = A[j];
            j++;k++;
        }
    }
    // Copying elements of A array
    while( i <= mid){
        B[k] = A[i];
        k++;i++;
    }
    // Copying elements of B array
    while( j <= high){
        B[k] = A[j];
        k++;j++;
    }

    for(int i = low ; i <= high; i++){
        A[i] = B[i];
    }
}

void MergeSort(int A[], int low, int high){
    int mid ;
    if(low < high){
        mid = (low + high)/ 2;
        MergeSort(A, mid + 1, high);
        MergeSort(A, low, mid);
        merge(A, low, mid, high);
    }
}


int main(){
    // int A[5] = {7,9,18,19,22};
    // int m = 5;
    // int B[4] = {1,6,9,11};
    // int n = 4;
    // int C[15];
    // printArray(A, m);
    // printArray(B, n);
    // mergeSort(A, B, C, m, n);
    // printArray(C, 9);

    int A[7] = {9,14,4,8,7,5,6};
    int n =  7;
    int B[20];
    printArray(A, n);
    MergeSort(A, 0, 6);
    printArray(A, n);

    return 0;
}*/

//  HEAP SORT 

#include <stdio.h>

void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    int temp;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

int main() {
    int a[] = {5, 3, 8, 1, 2};
    int n = 5;

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    heapSort(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

#include <stdio.h>

int interpolationSearch(int a[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high &&
           key >= a[low] && key <= a[high]) {

        if (a[low] == a[high]) {
            if (a[low] == key)
                return low;

            return -1;
        }

        int pos = low +
            (int)(((long long)(key - a[low]) *
            (high - low)) / (a[high] - a[low]));

        if (a[pos] == key)
            return pos;

        if (a[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

int main() {
    int a[] = {10, 20, 30, 40, 50};
    int n = 5, key = 40;

    int result = interpolationSearch(a, n, key);

    if (result != -1)
        printf("Element found at index %d", result);
    else
        printf("Element not found");

    return 0;
}