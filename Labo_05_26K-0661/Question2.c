#include<stdio.h>
int main()
{
    int marks, attendance, income;
    printf("Enter marks (0-100): ");
    scanf("%d",&marks);
    if (marks < 0 || marks > 100) printf("\nInvalid Marks!");
    else {
        printf("\nEnter attendance (0-100): ");
        scanf("%d",&attendance);
        if (attendance < 0 || attendance > 100) printf("\nInvalid Attendance!");
        else{
            printf("\nPlease enter Family income: ");
            scanf("%d",&income);
            if (marks < 50) printf("\nNot eligible! Marks too low");
            else if (attendance<75) printf("\nNot eligible! Attendance too low");
            else if(income > 800000) printf("\nNot eligible! Income too high");
            else{
                if (marks >=90 && attendance >=90) printf("\nFull Scholarship!");
                else if(marks >=75 && attendance >=85) printf("\nHalf Scholarship!");
                else printf("\n Quarter Scholarship");
            }
        }

    }
}