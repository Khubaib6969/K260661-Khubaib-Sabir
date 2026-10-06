#include<stdio.h>
int main(){
    int last,first,seats[15],booked=0,available[15]={0},empty;
    
    for(int i=0;i<15;i++){
        printf("Please enter 1 for booked and 0 for empty: \n");
        scanf("%d",&seats[i]);
    }
    
    for(int i =0;i<15;i++){
        if(seats[i] == 0){
            first = i+1;
            break;
        } 
    }
    for(int i =0;i<15;i++){
        if (seats[i]== 0) available[i]=i+1;
        else booked++;
    }
    empty = 15 - booked;
    printf("\nBooked: %d\nEmpty: %d",booked,empty);
    for(int i=14;i>0;i--){
        if (available[i]!=0){
            last = available[i];
            break;
        }
    }
    int x=0;
    for(int i=0;i<15;i++){
        if ((available[i]!=0)&&(x<3)){
            seats[available[i]-1] = 1;
            x ++;
        }
    }
    printf("\nUpdated seating: ");
    for(int i=0;i<15;i++) printf("%d)%d\n",i+1,seats[i]);
    
}