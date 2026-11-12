//Weather Station
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    
    do {
        printf("Enter the number of days (1 to 10): ");
        if (scanf("%d", &n) != 1) {
            printf("Invalid input.\n");
            while(getchar() != '\n'); 
            n = 0;
        }
        if (n < 1 || n > 10) {
            printf("Please enter a value between 1 and 10.\n");
        }
    } while (n < 1 || n > 10);

    
    double *temp = (double *)malloc(n * sizeof(double));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
    }

    
    printf("\nEnter temperature readings for %d day(s):\n", n);
    for (int i = 0; i < n; i++) {
        double inputTemp;
        do {
            printf("Day %d (-10 to 55): ", i + 1);
            if (scanf("%lf", &inputTemp) != 1) {
                printf("Invalid input.\n");
                while(getchar() != '\n');
                inputTemp = -99;
            }
            if (inputTemp < -10.0 || inputTemp > 55.0) {
                printf("Invalid temperature! Please enter a value between -10 and 55.\n");
            }
        } while (inputTemp < -10.0 || inputTemp > 55.0);
        
        temp[i] = inputTemp;
    }

        printf("\n--- Recorded Temperatures & Memory Addresses ---\n");
    for (int i = 0; i < n; i++) {
        printf("Day %d: %.1f at address %p\n", i + 1, temp[i], (void*)&temp[i]);
    }

    
    double *ptr = temp;
    double hottest = *ptr;
    double coldest = *ptr;

    for (int i = 0; i < n; i++) {
        if (*ptr > hottest) {
            hottest = *ptr;
        }
        if (*ptr < coldest) {
            coldest = *ptr;
        }
        ptr++;
    }

    printf("\nHottest temperature: %.1f \n", hottest);
    printf("Coldest temperature: %.1f \n", coldest);

    
    int countHotterThan40 = 0;
    ptr = temp; 
    for (int i = 0; i < n; i++) {
        if (*ptr > 40.0) {
            countHotterThan40++;
        }
        ptr++;
    }

    printf("Number of days hotter than 40 : %d\n", countHotterThan40);

    
    free(temp);
    temp = NULL;

    
    printf("\nMemory is successfully released and pointer set to NULL.\n");

}