#include<stdio.h>
int main(){
    int stream,interest;
    printf("Enter your stream(1.Science 2.Commerce 3.Arts): ");
    scanf("%d",&stream);
    if (stream != 1 && stream != 2 && stream != 3)printf("\nInvalid choice!");
    else{
        switch(stream){
            case 1://Science
            printf("\nEnter your interest(1.Biology 2.Physics 3.Chemistry): ");
            scanf("%d",&interest);
            if (interest != 1 && interest != 2 && interest != 3)printf("\nInvalid choice!");
            else{
                if(interest == 1){//Biology
                    printf("\nInterest in medicine(1.Yes 0.No): ");
                    scanf("%d",&interest);
                    (interest == 1)?printf("\nRecommended: MBBS"):printf("\nRecommended: Biotechnology");
                }else if(interest == 2){//Physics
                    printf("\nRecommended: BS Physics");
                }else printf("\nRecommended: BS Chemistry");
            }
            break;
            case 2://Commerce
            printf("\nEnter your interest(1.Economics 2.Business 3.Accounting): ");
            scanf("%d",&interest);
            if (interest != 1 && interest != 2 && interest != 3)printf("\nInvalid choice!");
            else{
                if (interest ==1)printf("\nRecommended: BS Economics");
                else if(interest ==2)printf("\nRecommended: BS BA");
                else printf("Recommended: BS in Accounting and Finance");
            }
            break;
            case 3://Arts
            printf("\nEnter your interest(1.Arts 2.Humanities 3.Social Sciences): ");
            scanf("%d",&interest);
            if (interest != 1 && interest != 2 && interest != 3)printf("\nInvalid choice!");
            else{
                if (interest==1)printf("\n");
                else if(interest==2)printf("\n");
                else printf("\n");
            }
        }
    }
}