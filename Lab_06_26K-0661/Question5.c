#include<stdio.h>
int main(){
    int notes500[5]={10,5,8,12,6},notes200[5]={20,15,10,8,14},notes100[5]={30,25,40,35,20};
    int total=0,amount;
    for (int i=0;i<5;i++){
        total += (notes100[i]*100) + (notes200[i]*200) + (notes500[i]*500);
    }
    printf("Please enter the withdrawal amount: ");
    scanf("%d",&amount);
    if (amount>total) printf("\nInsufficient Funds");
    else if(amount%100 != 0) printf("\nInvalid amount");
    else printf("\nTransaction Approved");
}