//Bus Tickets
#include<stdio.h>


void display(){
    printf("\n++++++++BUS TICKETS+++++++\n");
    printf("Route 1 (Karachi to Hyderabad): Rs.800\n");
    printf("Route 2 (Karachi to Sukkur): Rs.2200\n");
    printf("Route 3 (Karachi to Multan): Rs.3500\n");
}


int routeNum(){
    int num;
    printf("Please enter the route (1-3): ");
    scanf("%d",&num);
    while(num <1 || num > 3){
        printf("Route must be between 1 and 3 inclusive, Please enter again: ");
        scanf("%d",&num);
    }
    return num;
}


int numSeats(){
    int seats;
    printf("Please enter the number of seats (1-6): ");
    scanf("%d",&seats);
    while(seats < 1|| seats > 6){
        printf("Number of seats must be between 1 and 6 inclusive, Please enter again: ");
        scanf("%d",&seats);
    }
    return seats;
}


int seatFare(int route){
    int fare;
    switch (route){
        case 1:
        fare = 800;
        break;
        case 2:
        fare = 2200;
        break;
        case 3:
        fare = 3500;
        break;
    }
    return fare;
}


int totalFare(int fare, int seats){
    int total;
    total = fare * seats;
    return total;
}


char seatType(int *total){
    char Type;
    printf("Select seat Type (E. Economy, B. Business): ");
    scanf(" %c",&Type);
    while(Type!='E'&&Type!='B'){
        printf("Please enter E or B only: ");
        scanf(" %c",&Type);
    }
    if (Type == 'B'){
        *total *= 1.3;
    }
    return Type;
}


void displayTicket(int route, int seats, char Type, int total){
    printf("\n+++++TICKET+++++\n");
    switch(route){
        case 1:
        printf("Route: Karachi to Hyderabad\n");
        break;
        case 2:
        printf("Route: Karachi to Sukkur\n");
        break;
        case 3:
        printf("Route: Karachi to Multan\n");
        break;
    }
    printf("Seats: %d\n",seats);
    printf("Seat Type: %c\n",Type);
    printf("Final fare: %d\n",total);
}


int main(){
    int route,seat,Fare,total,totalCharges=0;
    char Type;
    for(int i =0;i<2;i++){
        display();
        route = routeNum();
        seat = numSeats();
        Fare = seatFare(route);
        total = totalFare(Fare,seat);
        Type = seatType(&total);
        displayTicket(route,seat,Type,total);
        totalCharges += total;
    }
    printf("\nTotal Earnings: %d",totalCharges);
}