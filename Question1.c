//RECHARGING A PREPAID MOBILE NUMBER
#include<stdio.h>

void display(){
    printf("\n----RECHARGE PACKS----\n");
    printf("1. Rs.100\n2. Rs.200\n3. Rs.500\n4. Rs.1000");
}


int packNum(){
    int choice;
    printf("\nEnter a pack number(1-4): ");
    scanf("%d",&choice);
    while(choice<1||choice>4){
        printf("pack number must be between 1 and 4 (inclusive), please enter again: ");
        scanf("%d",&choice);
    }
    return choice;
}


long long mobNum(){
    long long num;
    printf("Enter your mobile number (11 digits): ");
    scanf("%lld",&num);
    while(num<10000000000||num>99999999999){
        printf("Mobile number must be 11 digits, Please enter again: ");
        scanf("%lld",&num);
    }
    return num;
}


int packAmount(int num){
    int amount;
    switch(num){
        case 1:
        amount = 100;
        break;
        case 2:
        amount = 200;
        break;
        case 3:
        amount = 500;
        break;
        case 4:
        amount = 1000;
        break;
    }
    return amount;
}

float taxAmount(int prevAmount){
    float tax;
    tax = prevAmount * 0.15;
    return tax;
}


int bonus(float amount){
    int bonusAmount;
    if (amount >= 500){
        bonusAmount = amount * 0.1;
    }else bonusAmount = 0;
    return bonusAmount;
}


void rechargeSlip(long long mobileNum,int amount, float tax, int total){
    printf("\n----RECHARGE SLIP----\n");
    printf("Mobile Number: %lld\n",mobileNum);
    printf("Amount: %d\n",amount);
    printf("Tax: %0.2f\n",tax);
    printf("Total Balance: %d",total);
    printf("\n---------------------\n");

}


int main(){
    
    int num,amount,balance;
    long long mobile_Number;
    float tax, totalAmount;

    for(int i=0;i<3;i++){
        display();
        num = packNum();
        mobile_Number = mobNum();
        amount = packAmount(num);
        tax = taxAmount(amount);
        totalAmount += amount + tax;
        balance = amount + bonus(amount);
        rechargeSlip(mobile_Number,amount,tax,balance);
    }
    printf("\nTotal Money: %0.2f",totalAmount);
}