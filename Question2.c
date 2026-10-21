//Sudoku Grid Validation System
#include<stdio.h>
int main(){
    int grid[3][3]={0};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("Enter a number(1-9) or 0 to represent empty cell: ");
            scanf("%d",&grid[i][j]);
        }
    }
    int temp=0,RangeFlag=0,DuplicateFlag=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i][j]>9||grid[i][j]<0) {
                printf("Invalid Grid");
                RangeFlag = 1;
                break;
            }else if(grid[i][j]!=0){
                if(grid[i][j]==temp){
                    printf("Invalid Grid");
                    DuplicateFlag=1;
                    break;
                }else temp = grid[i][j];
            }
        }
    }
    if (RangeFlag==0&&DuplicateFlag==0)printf("Vaild Grid");
}