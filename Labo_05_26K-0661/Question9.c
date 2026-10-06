#include<stdio.h>
int main(){
    int permission;
    printf("Enter Integer permission(0-16): ");
    scanf("%d",&permission);
    if (permission<0 || permission>16) printf("\nInvalid input");
    else{
        if ((permission&31)==16) printf("\nFull access: admin");
        else if((permission&31)==10) printf("\nAccess: delete and write");
        else if((permission&31)==4) printf("\nAccess: execute only");
        else if((permission&31)==1) printf("\nAccess: read only");
        else if((permission&31)==0) printf("\nAccess denied");
        else printf("\nAccess: custom permissions");
    }
}   