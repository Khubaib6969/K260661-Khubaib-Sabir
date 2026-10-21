//Pattern Generation
#include<stdio.h>
int main(){
    int n=5;
    printf("\nStar Pattern 1:\n");
    //Star Pattern 1:
     int j;
     for(int i=n+1;i>1;i--){
         j=i-2;
        while(j!=0){
            printf("  ");
            j--;
        }
        
        j = n-i+2;
        while(j!=0){
            printf(" *");
            j--;
        }printf("\n");
    }
    printf("\nStar Pattern 2:\n");
    //Star Pattern 2:
    int i;
    
    for(i=n+1;i>1;i--){
        j = i-2;
        while(j!=0){
            printf("  ");
            j--;
        }
        
        j =(2*(n-i+2))-1;
        while(j!=0){
            printf(" *");
            j--;
        }printf("\n");
    }
    printf("\nNumber Pattern 1:\n");
    //Number pattern 1:
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%d ",j);
        }printf("\n");
    }
    printf("\nNumber Pattern 2:\n");
    //Number pattern 2:
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            printf("  ");
        }
        for(int j=1;j<=(2*i-1);j++){
            printf(" %d", j);
        }printf("\n");
    }
    printf("\nAlphabet Pattern 1:\n");
    //Alphabet pattern 1:
    for(int i=1;i<=n;i++){
        char alphabet = 'A';
        for(int j=1;j<=i;j++){
            printf("%c ",alphabet);
            alphabet++;
        }printf("\n");
    }
    printf("\nAlphabet Pattern 2:\n");
    //Alphabet Pattern 2:
    for(int i=1;i<=n;i++){
        char alphabet = 'A';
        for(int j=1;j<=n-i;j++){
            printf("  ");
        }
        for(int j=1;j<=(2*i-1);j++){
            printf(" %c", alphabet);
            alphabet++;
        }printf("\n");
    }
}   