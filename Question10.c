// School Exam Result Summary Generator
#include <stdio.h>
int main() {
    int numClasses, numStudents;
    float totalSchoolMarks = 0;
    int totalSchoolSubjectsCount = 0;

    
    printf("Enter the number of classes in the school: ");
    scanf("%d", &numClasses);

    
    for (int c = 1; c <= numClasses; c++) {
        float totalClassMarks = 0;
        int totalClassSubjectsCount = 0;

        
        printf("\nEnter the number of students in Class %d: ", c);
        scanf("%d", &numStudents);

        
        for (int s = 1; s <= numStudents; s++) {
            int numSubjects;
            float studentTotalMarks = 0;
            int hasFailed = 0;

            
            printf("  Enter the number of subjects studied by Class %d, Student %d: ", c, s);
            scanf("%d", &numSubjects);

            
            for (int sub = 1; sub <= numSubjects; sub++) {
                float marks;

                
                printf("    Enter marks for Subject %d: ", sub);
                scanf("%f", &marks);

                
                studentTotalMarks += marks;

                
                if (marks < 40.0) {
                    hasFailed = 1;
                }
            }

            
            float studentAverage = studentTotalMarks / numSubjects;

            
            printf("  -> Class %d, Student %d: Total Marks = %.2f, Average = %.2f, Result = %s\n",
                   c, s, studentTotalMarks, studentAverage, (hasFailed ? "Fail" : "Pass"));

            
            totalClassMarks += studentTotalMarks;
            totalClassSubjectsCount += numSubjects;
        }

        
        float classAverage = (totalClassSubjectsCount > 0) ? (totalClassMarks / totalClassSubjectsCount) : 0;
        printf("\n--------------------------------------------------\n");
        printf("Class %d Summary: Total Marks = %.2f, Class Average Marks per Subject = %.2f\n", 
               c, totalClassMarks, classAverage);
        printf("--------------------------------------------------\n");

        
        totalSchoolMarks += totalClassMarks;
        totalSchoolSubjectsCount += totalClassSubjectsCount;
    }

    
    float schoolAverage = (totalSchoolSubjectsCount > 0) ? (totalSchoolMarks / totalSchoolSubjectsCount) : 0;
    printf("\n==================================================\n");
    printf("SCHOOL-WIDE SUMMARY:\n");
    printf("Total Marks Across All Classes: %.2f\n", totalSchoolMarks);
    printf("Overall School Average Marks per Subject: %.2f\n", schoolAverage);
    printf("==================================================\n");
}