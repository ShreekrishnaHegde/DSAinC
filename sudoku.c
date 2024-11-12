//Backtracking for sudoku
#include <stdio.h>
#include <stdbool.h>
#define m 9
#define n 9
int board[9][9] ={
                {3, 0, 6, 5, 0, 8, 4, 0, 0},
                {5, 2, 0, 0, 0, 0, 0, 0, 0},
                {0, 8, 7, 0, 0, 0, 0, 3, 1},
                {0, 0, 3, 0, 1, 0, 0, 8, 0},
                {9, 0, 0, 8, 6, 3, 0, 0, 5},
                {0, 5, 0, 0, 9, 0, 6, 0, 0},
                {1, 3, 0, 0, 0, 0, 2, 5, 0},
                {0, 0, 0, 0, 0, 0, 0, 7, 4},
                {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
void display();
bool solve();
bool isValid(int row,int col,int number);
void main(){
    
    if(solve())
        display(board);
    else
        printf("\nCannot Solve sudoku");
}
bool isValid(int row,int col,int number){
    //Check if number is in the row or not
    for(int i=0;i<n;i++){
        if(board[row][i]==number)
            return false;
    }
    //Check if number is in the same colomn or not
    for(int i=0;i<n;i++){
        if(board[i][col]==number)
            return false;
    }
    //to find whether number is present in the same block or not
    int rowStart=row-row%3;
    int colStart=col-col%3;
    for(int i=rowStart;i<rowStart+3;i++){
        for(int j=colStart;j<colStart+3;j++){
            if(board[i][j]==number)
                return false;
        }
    }
    //Otherwise the number is valid
    return true;
    
}
bool solve(){
    //To keep track of unknown elements
    int row=-1;
    int col=-1;
    bool flag=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==0){
                row=i;
                col=j;
                flag=false;
                break;
            }
        }
        if(!flag)
            break;
    }
    //Sudoku is solved
    if(flag)
        return true;
    for(int number=1;number<=9;number++){
        if(isValid(row,col,number)){
            board[row][col]=number;
            if(solve())
                return true;
            else
                board[row][col]=0;
        }
    }
    return false;
}
void display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            printf("%d ",board[i][j]);
        printf("\n");
    }
}