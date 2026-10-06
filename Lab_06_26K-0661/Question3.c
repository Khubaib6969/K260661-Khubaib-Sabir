#include<stdio.h>
int main(){
    int stock[10]={0,1,2,3,4,5,6,7,8,9}, minimun[10]={9,8,7,6,5,4,3,2,1,0},total=0,reorder,largest=0;
    for(int i=0;i<10;i++){
        if (stock[i]<minimun[i]){
            reorder = minimun[i]-stock[i];
            total+=reorder;
            if (reorder>largest) largest = reorder;
        }
    }
    printf("Total: %d\nlargest: %d",total,largest);
}