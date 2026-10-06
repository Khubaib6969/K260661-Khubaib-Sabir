#include<stdio.h>
int main(){
    int generation[10];
    generation[0] = 1;
    generation[1] = 1;
    for (int i =2;i<10;i++){
        generation[i] = generation[i-2] + generation[i-1];
    }
    for (int i=0;i<10;i++) printf("%d\n",generation[i]);
}