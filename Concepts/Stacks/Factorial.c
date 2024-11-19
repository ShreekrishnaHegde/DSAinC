//Program to find the factorial of a number using recursion
#include <stdio.h>
int fact(int n){
    if(n==0 || n==1)
        return 1;
    return n*fact(n-1);
}
void main(){
    int n;
    printf("\nEnter an integer: ");
    scanf("%d",&n);
    printf("%d",fact(n));
}
/*
Algorithm

Create a function factorial() that takes the number N as argument.
If N is 0 or 1, return 1.
Otherwise, return N multiplied by the factorial (N-1).

Time Complexity: O(N)
Auxiliary Space: O(N),

*/