#include<stdio.h>
int main(){
    int permission,read;
    printf("Enter permission value(0-7): ");
    scanf("%d",&permission);
    if (permission<0 || permission >7)printf("\nInvalid integer!");
    else{
        if((permission & 4) == 4) printf("\nAccess granted: Full Control");
        else if((permission & 3) == 3){
            printf("\nAccess granted: read and write");            
        }else if((permission & 1)==1)printf("\nAccess granted: read only");
        else if((permission&1) == 0)printf("\nAccess denied");
    }
}