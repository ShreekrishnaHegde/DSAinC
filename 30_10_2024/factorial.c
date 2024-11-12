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