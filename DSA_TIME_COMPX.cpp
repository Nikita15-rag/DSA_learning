#include <iostream>
void func1 (int array[] , int length){
    int sum = 0;
    int product = 1;
    for (int i ; i<length ; i++)
    {
        sum+= array[i]; 
    }
    for (int i; i < length ;i++)
    {
        product *= array[i];
    }
}
int main(){
    int ar[4] = {1,3,66};
    func1(ar , 4);
    return 0;
}