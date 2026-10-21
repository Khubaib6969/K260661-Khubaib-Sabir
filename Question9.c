//Employee Salary Slip Generator for a Company
#include<stdio.h>

int main() {
    int numDepartments, numEmployees;
    int totalCompanySalary = 0;

    
    printf("Enter the number of departments in the company: ");
    scanf("%d", &numDepartments);

    
    for (int dept = 1; dept <= numDepartments; dept++) {
        int deptTotalSalary = 0; 

        
        printf("\nEnter the number of employees in Department %d: ", dept);
        scanf("%d", &numEmployees);

        
        for (int emp = 1; emp <= numEmployees; emp++) {
            int daysWorked;
            int salary;

            
            printf("  Enter days worked for Department %d, Employee %d: ", dept, emp);
            scanf("%d", &daysWorked);

            
            salary = daysWorked * 500;

            
            if (daysWorked > 25) {
                salary += 2000;
            }

            
            printf("  Department %d, Employee %d: Days Worked = %d, Salary = Rs. %d\n", 
                   dept, emp, daysWorked, salary);

            
            deptTotalSalary += salary;
        }

    
        printf("\nTotal salary paid to Department %d: Rs. %d\n", dept, deptTotalSalary);
        printf("--------------------------------------------------\n");

    
        totalCompanySalary += deptTotalSalary;
    }

    
    printf("\n==================================================\n");
    printf("Total salary paid across all departments combined: Rs. %d\n", totalCompanySalary);
    printf("==================================================\n");

    
}
