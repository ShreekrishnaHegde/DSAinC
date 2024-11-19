// Solving Tower of Hanoi problem with n disks.
#include <stdio.h>
void move(int n,char from_rod,char to_rod,char via_rod){
    if(n==0)
        return;
    move(n-1,from_rod,via_rod,to_rod);
    printf("\nMove disc %d from rod %c to rod %c",n,from_rod,to_rod);
    move(n-1,via_rod,to_rod,from_rod);  
}
void main(){

    int n;
    printf("\nEnter the number of discs: ");
    scanf("%d",&n);
    move(n,'A','C','B');
}