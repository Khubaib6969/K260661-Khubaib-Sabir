#include<stdio.h>
int main(){
    int amount=0,input=1,transaction=0;
    while (input!=0){
        printf("\nPlease enter the withdrawal amount: ");
        scanf("%d",&input);
        if(input!=0){
            transaction++;
            amount+=input;
        }  
    }
    printf("SUMMARY:\nTotal Transactions: %d\nTotal Amount: %d",transaction,amount);
}