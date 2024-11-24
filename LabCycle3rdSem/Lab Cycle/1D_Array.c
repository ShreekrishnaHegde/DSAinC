//Program to show insertion and deletion operarion in 1D Array.
#include <stdio.h>

void insertion(int arr[],int n,int index,int value){
    printf("Array before insertion: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    for(int i=n-1;i>=index;i--)
        arr[i+1]=arr[i];
    arr[index]=value;
    printf("\n");
    printf("\nArray after insertion: ");
    for(int i=0;i<n+1;i++)
        printf(" %d",arr[i]);
}  

void deletion(int arr[],int n,int index){
    printf("Array before deletion: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    for(int i=index;i<n;i++)
        arr[i]=arr[i+1];
    printf("\n");
    printf("Array after deletion: ");
    for(int i=0;i<n-1;i++)
        printf("%d ",arr[i]); 
}

void main(){
    int n,arr[15],choice,pos,value;
    printf("\nEnter the number of elements in the array: ");
    scanf("%d",&n);
    printf("\nEnter the elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nEnter your choice(1->insertion 2->deletion): ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("\nEnter the index and the element for insertion: ");
        scanf("%d%d",&pos,&value);
        insertion(arr,n,pos,value);
        break;
    case 2:
        printf("\nEnter the index: ");
        scanf("%d",&pos);
        deletion(arr,n,pos);
        break;
    default:
        printf("Invalid Choice");
        break;
    }
}