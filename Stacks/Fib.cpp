#include <iostream>
using namespace std;

int fib(int n){
    if(n<=1)
        return n;
    return fib(n-1)+fib(n-2);
}

int main(){
    int n,result;
    cout<<"\nEnter the number: ";
    cin>>n;
    result=fib(n);
    cout<<"\nThe "<<n<<"th Fibonacci number is: "<<result;
    return 0;
}

// Time Complexity: O(2^n)
// Auxiliary Space: O(n)