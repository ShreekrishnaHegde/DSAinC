/*
-------------------------GCD of two numbers using recursion and Eclid's algorithm by subtraction-------------------------
Psuedo Code:
gcd(a, b):
    if a = b:
        return a
    if a > b:
        return gcd(a – b, b)
    else:
        return gcd(a, b – a)
*/

#include <stdio.h>
int gcd(int a,int b){
    if(a==0)
        return b;
    if(b==0)
        return a;
    if(a==b)
        return a;
    if(a>b)
        return gcd(a-b,b);
    return gcd(a,b-a);
}

void main(){
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);
    printf("GCD of %d and %d is %d",a,b,gcd(a,b));

}