//HOSPITAL BILING
#include<stdio.h>


void display(){
    printf("\n=====ABC HOSPITAL=====\n");
    printf("General ward: Rs.1500/day\nSemi-Private: Rs.3500/day\nPrivate: Rs.6000/day\n");

}


int roomType(){
    int room;
    printf("Please enter room type(1-3): ");
    scanf("%d",&room);
    while(room>3||room<1){
        printf("Room type must be between 1-3 inclusive, please enter again: ");
        scanf("%d",&room);
    }
    return room;
}


int numDays(){
    int stay;
    printf("Please enter the number of days stayed(1-30): ");
    scanf("%d",&stay);
    while(stay>30||stay<1){
        printf("Number of days stayed must be between 1 and 30 inclusive: ");
        scanf("%d",&stay);
    }
    return stay;
}


int roomCharges(int type, int days){
    int charges;
    switch(type){
        case 1:
        charges = 1500 * days;
        break;
        case 2:
        charges = 3500* days;
        break;
        case 3:
        charges = 6000*days;
        break;
    }
    return charges;
}


float medCharge(){
    int medbill;
    float totalBill;
    printf("Enter the medicine bill: ");
    scanf("%d",&medbill);
    totalBill = medbill * 1.05;
    return totalBill;
}


float discount(int days, int bill){
    float discountAmount=0.0;
    if (days>=7){
        discountAmount = bill *0.08;
    }
    return discountAmount;
}


void displayBill(int room, int days, int charges, float medbill, float finalAmount){
    
    printf("\n=====Final Bill=====\n");
    switch(room){
        case 1:
        printf("Room Type: General Ward\n");
        break;
        case 2:
        printf("Room Type: Semi-Private\n");
        break;
        case 3:
        printf("Room Type: Private\n");
        break;
    }
    printf("Stay: %d\n",days);
    printf("Room Charges: %d\n",charges);
    printf("Medicine Charges: %0.2f\n",medbill);
    printf("Final Amount: %0.2f",finalAmount);
}


int main(){
    int room,stay,charges;
    float medBill,total,discountAmount;
    char citizen;
    display();
    room = roomType();
    stay = numDays();
    charges = roomCharges(room,stay);
    medBill = medCharge();
    total = charges + medBill;
    discountAmount = discount(stay,total);
    total = total - discountAmount;
    printf("Is the patient a senior citizen ? (y/n): ");
    scanf(" %c",&citizen);
    while(citizen != 'y' && citizen != 'n'){
        printf("Please type 'y' if patient is a senior citizen else type 'n' (case sensitive): ");
        scanf(" %c",&citizen);
    }
    if (citizen == 'y'){
        total -= 1000;
    }
    if (total < 0){
        total = 0;
    }
    displayBill(room,stay,charges,medBill,total);
}