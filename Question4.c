//TAXI FARE
#include<stdio.h>


void display(){
    printf("\n-----TAXI FARE-----\n");
    printf("Base Fare: Rs.150\n");
    printf("First 10 KM: Rs.60/KM\n");
    printf("After 10 KM: Rs.45/KM\n");
}


int distance(){
    int x;
    printf("Enter distance in KM (more than 0, up to 200): ");
    scanf("%d",&x);
    while(x<=0||x>200){
        printf("Distance MUST be more than zero, up to 200; Please enter again: ");
        scanf("%d",&x);
    }
    return x;
}


int time(){
    int waiting;
    printf("Please enter the waiting time in minutes (0 to 120): ");
    scanf("%d",&waiting);
    while(waiting<0||waiting>120){
        printf("Waiting time MUST be between 0 and 120 inclusive, Please enter again: ");
        scanf("%d",&waiting);
    }
    return waiting;
}


int distanceCharge(int distanceKM){
    int charge=150;
    if(distanceKM>10){
        charge += 600;
        distanceKM -=10;
        charge += (distanceKM * 45);
    }else{
        charge += (distanceKM*60);
    }
    return charge;
}


int waitingCharge(int waiting){
    int charge=0;
    if (waiting>5){
        charge = (waiting-5)*10;
    }
    return charge;
}


int nightCharge(int prevFare){
    int hour,newFare;
    printf("Please enter the hour of the trip (0-23): ");
    scanf("%d",&hour);
    while(hour<0||hour>23){
        printf("hour MUST be between 0 and 23 inclusive, Please enter again: ");
        scanf("%d",&hour);
    }
    if(hour<6||hour>=22){
        newFare = prevFare * 1.25;
    }else newFare = prevFare;
    return newFare;
}


void displayReceipt(int dis, int waiting, int total){
    printf("\n-----RECEIPT-----\n");
    printf("Distance: %d\n",dis);
    printf("Waiting time: %d\n",waiting);
    printf("Final Fare: %d\n",total);
}


int main(){
    int dist,waiting,distCharge,waitCharge,night,fare,total=0,highest=0;
    for(int i=0;i<3;i++){
        display();
        dist = distance();
        waiting = time();
        distCharge = distanceCharge(dist);
        waitCharge = waitingCharge(waiting);
        fare = distCharge + waitCharge;
        night = nightCharge(fare);
        fare = night;
        displayReceipt(dist,waiting,fare);
        total += fare;
        if (fare>highest) highest = fare;
    }
    printf("\nTotal Earnings: %d\nHighest fare of the day: %d",total,highest);
}