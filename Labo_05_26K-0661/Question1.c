#include<stdio.h>
int main()
{
    int type, member, hours;
    float fee;
    printf("Please enter vehicle type(1.Bike 2.Car 3.Truck): ");
    scanf("%d",&type);
    printf("\nPlease enter membership status(1.Member 0.Non-member): ");
    scanf("%d",&member);
    printf("\nPlease enter the duration of stay in hours: ");
    scanf("%d",&hours);
    if (type != 1 && type != 2 && type !=3) printf("\nInvalid Vehicle type");
    else if (hours<=0) printf("\nInvalid Duration"); 
    else {
        switch(type){
            case 1: //bike
            fee = 20*hours;
            break;
            case 2: //car
            if (hours <= 2) fee =50;
            else fee = 50 + 30*(hours-2);
            break;
            case 3: //truck
            if (hours <= 3) fee =100;
            else fee = 100 + 50*(hours -3);
            break;
        }
        if (member && fee > 200) fee *=0.85;
        printf("\n%0.2f",fee);
    }    
}