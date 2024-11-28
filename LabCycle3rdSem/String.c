//Program to illustre string function in c
#include <stdio.h>
#include <string.h>
void main(){
    char str1[20]="Information";
    char str2[20]="Science";
    char str3[20];

    printf("String 2 is: ");
    puts(str2);
    //String length
    printf("Size of string 1 is: %d\n",strlen(str1));
    printf("Size of string 1 is: %d\n",strlen(str2));
    //Return 0 if strings are equal.
    printf("%d\n",strcmp(str1,str2));
    //String concatenation
    strcat(str1,str2);
    puts(str1);
    //Copying contents of str1 to str3
    strcpy(str3,str1);
    puts(str3);

}