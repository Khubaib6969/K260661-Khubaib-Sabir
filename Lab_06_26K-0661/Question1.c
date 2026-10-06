#include<stdio.h>
int main(){
    int average,total=0,num, cars[12];
    int i;
    for(i=0;i<12;i++){
        printf("\nPlease enter the number of cars waiting at signal %d: ",i+1);
        scanf("%d",&num);
        cars[i] = num;
        total = total + num;
    }
    average = total/12;
    int L_signal,lowest,H_signal,highest=0,overloaded=0;
    for(i=0;i<12;i++){
        if (cars[i]>average) overloaded++;
        if (cars[i]>highest) {highest = cars[i];
        H_signal = i+1;
        }
        if (cars[i]<lowest){
            lowest = cars[i];
            L_signal = i+1;
        }
    }
    printf("\nAverage number of cars per signal: %d",average);
    printf("\nNumber of overloaded signals: %d",overloaded);
    printf("\nSignal with the highest cars: %d",highest);
    printf("\nSignal with the lowest cars: %d",lowest);
    printf("\nHighest number of cars in a signal: %d",H_signal);
    printf("\nLowest number of cars in a signal: %d",L_signal);
}