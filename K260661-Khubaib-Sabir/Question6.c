#include<stdio.h>
int main(){
int category,order;
printf("Choose a category(1.Greeting 2.Query 3.Complaint 4.Feedback): ");
scanf("%d",&category);
if(category != 1 && category != 2 && category != 3 && category !=4) printf("\nInvalid selection");
else {
int subtype;
switch(category){
    case 1://Greeting
    printf("\nChoose a sub-type(1.Morning 2.Evening): ");
    scanf("%d",&subtype);
    if (subtype == 1)printf("\nGood Morning!");
    else printf("\nGood Evening!");
    break;
    case 2://Query
    printf("\nChoose a sub-type(1.Product 2.Billing 3.Technical): ");
    scanf("%d",&subtype);
    if (subtype == 1)printf("\nRedirected to Product department");
    else if(subtype == 2)printf("\nRedirected to Billing department");
    else printf("\nRedirected to technical department");
    break;
    case 3://Complaint
    printf("\nChoose a sub-type(1.Delivery 2.Quality): ");
    scanf("%d",&subtype);
    if (subtype == 1){
        printf("\nPress 1 if order was delayed, else press 0: ");
        scanf("%d",&order);
        if (order == 1)printf("\nSorry for the delay");
        else printf("\nSorry for the bad experience");
    }else printf("\nRedirecting to quality complain department.");
    break;
    case 4://Feedback
    printf("\nChoose a sub-type(1.Positive 2.Negative): ");
    scanf("%d",&subtype);
    if (subtype==1)printf("\nThanks for the Positive feedback!");
    else printf("\nFeedback noted");
    break;
    default:
    printf("\nInvalid selection");
}
}   
}
