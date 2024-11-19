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
    printf("\nEnter two integers: ");
    scanf("%d%d",&a,&b);
    printf("\nGCD : %d",gcd(a,b));
}

/*
Pseudo-code:

gcd(a, b):
    if a = b:
        return a
    if a > b:
        return gcd(a – b, b)
    else:
        return gcd(a, b – a)

Time Complexity: O(min(a,b))
Auxiliary Space: O(min(a,b)) 
*/