//Airline Seat Reservation Management System
#include<stdio.h>
int main(){
    int seating[10][4];
    for(int i=0;i<10;i++){
        for(int j=0;j<4;j++){
            seating[i][j] = 0;
        }
    }

    int seats,rowNum,seatNum,flag=0;
    printf("Please enter the number of seats to register: ");
    scanf("%d",&seats);
for(int i=0;i<seats;i++){
    flag = 0;
    while(flag==0){
        printf("\nPlease enter the row number: ");
        scanf("%d",&rowNum);
        while(rowNum>10||rowNum<1){
            printf("Row number must be between 1 and 10, Enter again: ");
            scanf("%d",&rowNum);
        }
        rowNum --;
        printf("Please enter the seat number: ");
        scanf("%d",&seatNum);
        while(seatNum<1||seatNum>4){
            printf("Seat number must be between 1 and 4, Enter again: ");
            scanf("%d",&seatNum);
        }
        seatNum --;
        if(seating[rowNum][seatNum]==0){
            seating[rowNum][seatNum] = 1;
            printf("Seat Booked Successfully!");
            flag = 1;
        }else printf("Seat is already booked!");
    }
    }
    printf("\n         1 2 3 4");
    for(int i=0;i<10;i++){
        if(i<9) printf("\nRow 0%d:  ",i+1);
        else printf("\nRow %d:  ",i+1);
        for(int j=0;j<4;j++){
            printf("%d ",seating[i][j]);
        }
    }
    int check=0,rowCount =0;
    
    for(int i=0;i<10;i++){
        check =0;
        for(int j=0;j<4;j++){
            if(seating[i][j]==1) check++;
        }
        if (check==4) rowCount++;
    }
    printf("\nFully Booked Rows: %d",rowCount);
}