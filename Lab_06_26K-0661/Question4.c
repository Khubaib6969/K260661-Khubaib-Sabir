#include<stdio.h>
int main(){
    int marks[15]={65,34,99,67,98,45,1,89,66,55,89,23,44,44,15},total = 0,count=0,highest=0,lowest=100,range;
    for(int i=0;i<15;i++){
        if ((marks[i]+5)>100) marks[i]=100;
        else marks[i]+=5;
        total += marks[i];
        if (marks[i]==100) count ++;
        if (marks[i]>highest) highest =marks[i];
        if (marks[i]<lowest) lowest = marks[i];
    }
    range = highest-lowest;
    float average = total/15.0;
    printf("Average: %0.2f\n100 marks: %d\nRange: %d\nHighest: %d\nLowest: %d",average,count,range,highest,lowest);
}   