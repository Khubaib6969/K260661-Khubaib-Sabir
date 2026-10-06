#include<stdio.h>
int main(){
    int length=0,num,reversed=0,digit;
    printf("Enter the number: ");
    scanf("%d",&num);
    int temp = num;
    while(temp>0){
        temp/=10;
        length ++;
    }
    temp = num;
    for (int i=0;i<length;i++){
        digit = temp%10;
        reversed = reversed*10 +digit;
        temp/=10;
    }printf("%d",reversed);
    if(reversed-num == 0) printf("\n%d is a palindrome",num);
    else printf("\n%d is not a palindrome",num);

}