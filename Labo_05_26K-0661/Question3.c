#include<stdio.h>
int main()
{
    int age, oxygen, bpm;
    printf("Please enter the oxygen level: ");
    scanf("%d",&oxygen);
    if (oxygen < 90) printf("\nCritical: Immediate attention!");
    else{
        printf("\nPlease enter heart rate: ");
        scanf("%d",&bpm);
        if (bpm > 130 || bpm < 40) printf("\nCritical: Cardiac alert!");
        else{
            printf("\nPlease enter age: ");
            scanf("%d",&age);
            if(age >= 65 && oxygen < 95) printf("\nHigh priority!");
            else if (age <= 5 && bpm > 110) printf("\nHigh priority!");
            else printf("\nLow priority!");
        }
    }
}