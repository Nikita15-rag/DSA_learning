// BUBBLE SORT
/*#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {5, 2, 8, 1, 3};
    int n = 5;
    int i;

    bubbleSort(arr, n);

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}*/


// SELECTION SORT

/*#include <stdio.h>

void selectionSort(int arr[], int n)
{
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int arr[] = {5, 2, 8, 1, 3};
    int n = 5;
    int i;

    selectionSort(arr, n);

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}*/

// HEAP SORT
/*#include <stdio.h>
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i){
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);}
}

void heapSort(int arr[], int n)
{
    int i, temp;

    // Build Max Heap
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // Extract elements
    for (i = n - 1; i > 0; i--){
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {2,4,6,3,9};
    int n = 5;
    int i;

    heapSort(arr, n);

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}*/

// QUICK SORT
/*#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {3,6,1,9,10};
    int n = 5;
    int i;

    quickSort(arr, 0, n - 1);

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}*/

// LINEAR SEARCH
/*#include <stdio.h>

int linearSearch(int arr[], int n, int key)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

int main()
{
    int arr[] = {12,34,8,11,2};
    int n = 5;
    int key = 8;

    int result = linearSearch(arr, n, key);

    if (result != -1)
        printf("Element found at index %d", result);
    else
        printf("Element not found");

    return 0;
}*/

// BINARY SEARCH
/*#include <stdio.h>

int binarySearch(int arr[], int n, int key){
    int low = 0;
    int high = n - 1;

    while (low <= high){
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        else if (arr[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {1,4,5,8,10};
    int n = 5;
    int key = 5;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        printf("Element found at index %d", result);
    else
        printf("Element not found");
    return 0;
}*/