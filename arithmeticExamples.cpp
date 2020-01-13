#include<stdio.h>
 
int main()
{
    // Declare and initialize variable a and b
    int a = 11, b = 4;
 
    printf("a + b = %d\n", a + b); // add a to b
 
    printf("a - b = %d\n", a - b); // minus b from a
 
    printf("a * b = %d\n", a * b); // multiply a by b
 
    printf("a / b = %d\n", a / b); // divide a by b
    // because both operands are integer result will be an integer
 
    printf("a %% b = %d\n", a % b); // the a divide by b
    // % operator returns the remainder of 11/4 i.e 3
 
    // Signal to operating system everything works fine
    return 0;
}