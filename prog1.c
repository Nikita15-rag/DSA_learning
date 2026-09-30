#include <stdio.h>
void func1 (int array[] , int length){
    int sum = 0;
    int product = 1;
    for (int i ; i<length ; i++)
    {
        sum+= array[i];               // O(n) time complexity
        printf("%d\n" , sum);
    }
    for (int i; i < length ;i++)
    {
        product *= array[i];
        printf("%d\n" , product);
    }
}
int main(){
    int ar[4] = {1,3,66,89};
    func1(ar , 4);
    return 0;
}

/*
#include <stdio.h>
void func(int n)
{
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d , %d\n", i,j);  // O(n^2) time complexity
        }
    }
}

int main(){
    int n = 3;
    func(n);
    return 0;
} */