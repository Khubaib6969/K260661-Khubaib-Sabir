#include<stdio.h>
int main(){
    int cooking, time, motion, light, room;
    printf("\nEnter time(0-23): ");
    scanf("%d",&time);
    printf("\nMotion(0-1): ");
    scanf("%d",&motion);
    printf("\nEnter light time(0-100): ");
    printf("\nSelect room:\n1.Living Room\n2.Bedroom\n3.Kitchen\nEnter your choice: ");
    scanf("%d",&room);
    switch(room){
        case 1://Living room
        case 2://Bedroom
        if((time>=6 && time <= 18) && motion == 1)printf("\nDaymode: Lights ON");
        else if((time>=18 && time <= 23) && motion == 1)printf("\nEvening mode: dim lights");
        else if (time>=23 && time <= 6) printf("\nNight mode: Lights Off");
        else printf("\nAway mode: All OFF");
        break;
        case 3:
        printf("\nSelect cooking status(1.cooking 0.not cooking): ");
        scanf("%d",&cooking);
        if (cooking)printf("\nTurn on Exhaust");
        if((time>=6 && time <= 18) && motion == 1)printf("\nDaymode: Lights ON");
        else if((time>=18 && time <= 23) && motion == 1)printf("\nEvening mode: dim lights");
        else if (time>=23 && time <= 6) printf("\nNight mode: Lights Off");
        else printf("\nAway mode: All OFF");
        break;               
    }
}