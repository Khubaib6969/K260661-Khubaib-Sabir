#include<stdio.h>
int main(){
    int accuracy,confidence,dataset,role,status;
    float model,min;
    printf("Enter accuracy(0-100): ");
    scanf("%d",&accuracy);
    printf("\nEnter Confidence score(0-100): ");
    scanf("%d",&confidence);
    printf("\nEnter dataset size: ");
    scanf("%d",&dataset);
    printf("\nEnter role(1.Intern 2.Engineer 3.Admin): ");
    scanf("%d",&role);
    printf("\nEnter status flags(0-8): ");
    scanf("%d",&status);
    if ((dataset/1000)>10) min = 10;
    else min = dataset/1000;
    model = (accuracy*0.5) + (confidence*0.5) + min;
    printf("\nModel Score: %0.2f",model);
    if((status&8)==1) printf("\nRejected: model deprecated");
    else if((status&1)==0) printf("\nRejected: not trained");
    else if((status&2)==0) printf("\nRejected: not validated");
    else if((status&4)==0) printf("\nPending: awaiting approval");
    else if(accuracy <70 || confidence<60) printf("\nRejected: performance too low");
    else if(dataset<5000) printf("\nRejected: dataset too small");
    else if(role == 1) printf("\nRejected: Interns cannot deploy");
    else if(role == 2 && model<80) printf("\nRejected: Engineers need higher score");
    else printf("\napproved for deployment");
    printf("\nSize of accuracy: %d",sizeof accuracy);
    printf("\nSize of confidence: %d",sizeof confidence);
    printf("\nSize of dataset: %d",sizeof dataset);
    printf("\nSize of role: %d",sizeof role);
    printf("\nSize of status: %d",sizeof status);
    printf("\nSize of Model score: %f",sizeof model);
    if (model > ((accuracy+confidence)/2)) printf("\nModel score is greater than the average of accuracy and confidece score");
    else printf("\nAverage of accuracy and confidence score is greater than model score");
    
}