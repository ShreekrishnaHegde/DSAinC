/*
->We are going to select an element and place it in the right place , hence the name selection sort.
->Select the largest element and place it in the last position by swapping.
->Then select 2nd largest element place it in the last-1 position by swapping.
->Repeat this process
->Time Complexity: Worst Case-O(n2)
->Space Complexity: O(1).
-<Not stable sorting algorithm
-performs well on small data.*/
#include <stdio.h>
#include <string.h>

void sort(int n,char str[]){
    for(int i=0;i<n;i++){
        int last=n-i-1;
        int max='0';
        //Finding the max element in current array
        for(int j=0;j<=last;j++){
            if(str[j]>str[max])
                max=j;
        }
        //Swapping
        char temp=str[last];
        str[last]=str[max];
        str[max]=temp;

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