//Class Performance Management System
#include<stdio.h>
int main(){
    int classes=2, students=3, subjects=3, school[classes][students][subjects];
    for (int i =0;i<classes;i++){
        for(int j=0;j<students;j++){
            for(int k=0;k<subjects;k++){
                printf("Enter marks for class %d, student %d, for subject %d: ",i,j,k);
                scanf("%d",&school[i][j][k]);   
            }
        }
    }
    printf("\n\n");
    int TotalMarks[2][3] = {0};
    for(int i=0;i<classes;i++){
        for(int j=0;j<students;j++){
            for(int k=0;k<subjects;k++){
                TotalMarks[i][j] += school[i][j][k];
            }
        }
    }
    int classTopper, schoolTopper, Highest =0, schoolHighest =0,topperClass;
    for(int i=0;i<classes;i++){
        Highest =0;
        for(int j=0;j<students;j++){
            if(TotalMarks[i][j]>Highest){ Highest = TotalMarks[i][j];
                classTopper = j;
            }
        }printf("Top Performer of Class %d: Student %d with %d marks\n",i,classTopper,Highest);
        if (Highest>schoolHighest){
            schoolHighest = Highest;
            schoolTopper = classTopper;
            topperClass = i;
        }
    }printf("School topper is student %d from class %d with %d marks\n",schoolTopper,topperClass,schoolHighest);
}