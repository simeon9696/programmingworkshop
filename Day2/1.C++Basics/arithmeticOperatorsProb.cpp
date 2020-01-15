#include<stdio.h>
 // source: https://overiq.com/1c-programming-101/arithmetic-operators-in-c/
int main()
{
    // Declare and initialize variable a and b
    int a = 7, b = 7;
 
    printf("a + b = %d\n", a+b);  // 142
 
    printf("a - b = %d\n", a-b);  //128
 
    printf("a * b = %d\n", a*b);  //??
 
    printf("a / b = %d\n", a/b); 
    // because both operands are integer result will be an integer
 
    printf("a %% b = %d\n", a%b);  //??? 
    // % operator returns the remainder of 11/4 i.e 3
 
    // We want to find what a not equal to be using the operator: !=
    printf("a != b = %d\n", a != b);
    printf("a == b = %d\n", a == b);
    printf("a && b = %d\n", a && b);
    printf("a & b = %d\n", a & b);


    printf("a *= b  %d\n", a *= b);
    printf("a =  %d\n", a );
    printf("b =  %d\n", b );

    
    // Signal to operating system everything works fine
    return 0;
}