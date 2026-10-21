//Matrix Encryption Management System
#include<stdio.h>
int main()
{
    int Data[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("Enter data for cell [%d,%d]: ",i,j);
            scanf("%d",&Data[i][j]);
        }
    }
    int Key[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("Enter key for cell [%d,%d]: ",i,j);
            scanf("%d",&Key[i][j]);
        }
    }
    int Encrypted[3][3] ={0};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            Encrypted[i][j] = (Data[i][j] * Key[i][j]) + (i + j);
        }
    }
    int maximum =0,maxRow,maxColumn;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",Encrypted[i][j]);
            if(Encrypted[i][j]>maximum){ maximum = Encrypted[i][j];
            maxRow = i;
            maxColumn = j;
            }
        }printf("\n");
    }printf("Max encrypted value: %d, Position: [%d,%d]",maximum,maxRow,maxColumn);
}