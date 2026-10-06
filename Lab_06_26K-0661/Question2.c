#include<stdio.h>
int main(){
    char string[25];
    int strongest=0,low=0,score=0,j=0;
    for (int x =0;x <5;x++){
        score = 0;
        printf("\nPlease enter the password: ");
        fgets(string, 25, stdin);
        for(int i =0;string[i]!='\0';i++){
            if (string[i]>='a'&&string[i]<='z')score++;
            if (string[i]>='A'&&string[i]<='Z')score +=2;
            if (string[i]>='0'&&string[i]<='9')score +=3;
            if (string[i]=='1'&&string[i+1]=='2'&&string[i+2]=='3')score-=3;
            j++;
        }
        
        if (j>=8) score +=5;
        if (score > strongest) strongest = score;
        if (score < 10) low +=1;
    }
    printf("\nStrongest: %d",strongest);
    printf("\nscore below 10: %d",low);
}