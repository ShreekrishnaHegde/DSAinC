//Program to generate fibonnaci numbers using recursion
#include <stdio.h>

int fib(int n){
    if(n==1 || n==0)
        return n;
    return fib(n-1)+fib(n-2);
}

void main(){
    int n;
    printf("\nEnter a number: ");
    scanf("%d",&n);
    printf("%d",fib(n));
}
/*
Base case: F(n) = n, when n = 0 or n = 1
Recursive case: F(n) = F(n-1) + F(n-2) for n>1
*/