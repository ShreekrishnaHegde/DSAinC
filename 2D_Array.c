#include<stdio.h>
void read(int m,int n,int (*p)[])
{
    printf("Enter the elements of the array : ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        scanf("%d",(*(p+i)+j));
    }
}
int main()
{
    int n,m;
    printf("Enter the number of rows and columns : ");
    scanf("%d%d",&n,&m);
    int arr[10][10];
    int (*ptr)[m]=arr;
    read(n,ptr,m);
    // printf("Enter the inputs : ");
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     scanf("%d",(*(ptr+i)+j));
    // }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     printf("%d",((ptr+i)+j));
    // }
    return 0;
}