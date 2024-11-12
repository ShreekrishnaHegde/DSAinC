//Program to sort the given integer array using insertion sort (sorting in descending order)
#include <stdio.h>
#include <string.h>
void sort(int n,char str[]){
    for(int i=0;i<n;i++){
        for(int j=i+1;j>0;j--){
            if(str[j]>str[j-1]){
                char temp=str[j-1];
                str[j-1]=str[j];
                str[j]=temp;
            }
            else
                break;
        }
    }
} 

void main(){
    char str[20];
    printf("\nEnter a string: ");
    gets(str);
    int n=strlen(str);
    printf("\nString Before Sorting: ");
    puts(str);
    sort(n,str);
    printf("String after sorting:");
    puts(str);

}