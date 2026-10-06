#include<stdio.h>
int main()
{
    int status, pin, balance, withdraw, newBalance, Notes, remaining;
    printf("Enter Card status(1.Valid 0.Invalid): ");
    scanf("%d",&status);
    if (status){
        printf("\nEnter pin status(1.Correct 0.Incorrect): ");
        scanf("%d",&pin);
        if (pin){
            printf("\nEnter withdraw amount: ");
            scanf("%d",&withdraw);
            if (withdraw <=0) printf("\nInvalid amount!");
            else{
                printf("\nEnter account balance: ");
                scanf("%d",&balance);
                if (withdraw > balance) printf("\nInsufficient balance!");
                else if(withdraw>25000) printf("\nDaily limit exceeded!");
                else if ((balance-withdraw) < 1000) printf("\nMinimum balance must be maintained!");
                else{
                    newBalance = balance-withdraw;
                    if (withdraw > 2000){
                    Notes = withdraw / 2000;
                    remaining = withdraw % 2000;
                    if (remaining == 0){
                        Notes -=1;
                        printf("\nNotes:\n2000: %d\n500: %d\n100: %d",Notes,3,5);
                    }else{
                        
                    }
                }
                } 

            }
        }
    }
    
}