#include<stdio.h>
int main(){
    int transfers[10] = {5000, 50, 12000, 500000, 20, 8000, 25000, 300, 450000, 15000};
    int highest=0,flag=0,total;
    float average;
    for(int i=0;i<10;i++){
        if(transfers[i]<100) flag ++;
        else if(transfers[i]>200000) flag++;
        else total += transfers[i];
        if (transfers[i]>highest) highest = transfers[i];
    }
    average = total/10.0;
    printf("flagged: %d\nHighest: %d\nAverage: %0.2f",flag,highest,average);
}