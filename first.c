#include<stdio.h>

int main (){
   
    //rules for variable declaration 
    int harryName ; // var declaration 
    harryName = 9;  // var initialization
    const int i = 9;
    // i = 89; will throw error 
    printf("hello");


    //  types of operators
    // Arithmetic operators
   // int a = 2, b = 9;
   // printf("\nthe sum of a and b is %d\n", a+b);
   // printf("the diff of a and b is %d\n", a-b);
   // printf("the into of a and b is %d\n", a*b);
   // printf("the division of a and b is %d\n", b/a);
   // printf("the modulo of a and b is %d\n", b%a);
   // printf("the increment of a is %d\n", a++);//2-3
   // printf("the increment of a is %d\n", a++);//3-4
   // printf("the decrement of a is %d\n", a--);//4-3
   // printf("the increment of b is %d\n", b++);
   // printf("the decrement of b is %d\n", b--);

    // Relational operators
    //int harry = 9, rohan = 78;
    //printf("%d\n" , harry == rohan);
    //printf("%d\n" , harry != rohan);
    //printf("%d\n" , harry > rohan);
    //printf("%d\n" , harry < rohan);

    // Logical operators
    //int h=0, j=0;
    //printf("the logical operator returned %d\n" , h && j );
    //printf("the logical operator returned %d\n" , h || j);
    //printf("the logical operator returned %d\n" , !h);
    //printf("the logical operator returned %d\n\n" , !j);

    // Bitwise operators
    //int A = 69, B = 14;
    //printf("the bitwise OR operator %d\n" , A|B);
    //printf("the bitwise AND operator %d\n" , A&B);
    //printf("the bitwise XOR operator %d\n" , A^B);
    //printf("the bitwise ONES operator %d\n" , ~B);
    //printf("the bitwise LEFT SHIFT operator %d\n" , A<<B);
    //printf("the bitwise RIGHT SHIFT operator %d\n" , A>>B);

    /// Assignment operators
    /// = , += , -= , *= , /= , etc
    int ha = 9;
    ha +=7;
    printf("\nha is %d\n" , ha);
    
    /// misc operators  => & , * , ?:
   // float num;
   // printf("enter your no." , num);
   // scanf("%f" , &num); // always write it as it is shown here
   // printf("you entered %f as nikkiinput" ,num);

    //int num1,num2;
    //scanf("%d", &num2);
    //scanf("%d", &num1);
    //printf("the division of num1 by num2 is %f " , (float)num1/num2);

    int index = 2;
    while (index <= 10){
        printf("the value of index is %d\n" , index);
        index++;
           }
    return 0;
}