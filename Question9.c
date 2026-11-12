#include <stdio.h>
#include <string.h>

#define STUDENTS 5

/* Reads 3 marks (0 to 100) and sends them back to main() */
void readMarks(int *m1, int *m2, int *m3) {
    int *marks[3] = {m1, m2, m3};
    for (int i = 0; i < 3; i++) {
        do {
            printf("  Enter mark %d (0-100): ", i + 1);
            scanf("%d", marks[i]);
            if (*marks[i] < 0 || *marks[i] > 100)
                printf("  Invalid! Marks must be between 0 and 100.\n");
        } while (*marks[i] < 0 || *marks[i] > 100);
    }
}

/* Gives back four results: total, average, highest and lowest */
void calculateStats(int m1, int m2, int m3, int *total, double *average,
                    int *highest, int *lowest) {
    *total = m1 + m2 + m3;
    *average = *total / 3.0;
    *highest = m1;
    *lowest = m1;
    if (m2 > *highest) *highest = m2;
    if (m3 > *highest) *highest = m3;
    if (m2 < *lowest)  *lowest = m2;
    if (m3 < *lowest)  *lowest = m3;
}

/* Swaps two marks */
void swapMarks(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Sorts the 3 marks from highest to lowest using swapMarks */
void sortMarks(int *m1, int *m2, int *m3) {
    if (*m1 < *m2) swapMarks(m1, m2);
    if (*m1 < *m3) swapMarks(m1, m3);
    if (*m2 < *m3) swapMarks(m2, m3);
}

/* Adds grace marks (max 5) only if mark is 35-39, never going above 40 */
void addGraceMarks(int *mark, int grace) {
    if (*mark >= 35 && *mark <= 39) {
        if (grace > 5) grace = 5;
        if (*mark + grace > 40) grace = 40 - *mark;
        *mark += grace;
    }
}

/* Gives back both a grade and a remark */
void findGrade(double avg, char *grade, char *remarks) {
    if (avg >= 80) {
        *grade = 'A';
        strcpy(remarks, "Excellent");
    } else if (avg >= 60) {
        *grade = 'B';
        strcpy(remarks, "Good");
    } else if (avg >= 40) {
        *grade = 'C';
        strcpy(remarks, "Needs Improvement");
    } else {
        *grade = 'F';
        strcpy(remarks, "Needs Improvement");
    }
}

/* Comparison demo functions */
void incrementByValue(int x) {
    x = x + 1;      /* changes only the local copy */
}

void incrementByReference(int *x) {
    *x = *x + 1;    /* changes the original variable through its address */
}

int main(void) {
    int total[STUDENTS], highest, lowest;
    double average[STUDENTS];
    char grade[STUDENTS];
    char remarks[STUDENTS][20];

    for (int s = 0; s < STUDENTS; s++) {
        int m1, m2, m3;
        printf("\nStudent %d:\n", s + 1);
        readMarks(&m1, &m2, &m3);

        /* Grace marks for students who are only 1 to 5 marks short */
        addGraceMarks(&m1, 5);
        addGraceMarks(&m2, 5);
        addGraceMarks(&m3, 5);

        /* Sort the 3 marks from highest to lowest */
        sortMarks(&m1, &m2, &m3);
        printf("  Sorted marks: %d %d %d\n", m1, m2, m3);

        calculateStats(m1, m2, m3, &total[s], &average[s], &highest, &lowest);
        printf("  Highest: %d, Lowest: %d\n", highest, lowest);

        findGrade(average[s], &grade[s], remarks[s]);
    }

    /* Result table */
    printf("\n%-8s %-8s %-10s %-7s %s\n",
           "Student", "Total", "Average", "Grade", "Remark");
    printf("-------------------------------------------------------\n");
    for (int s = 0; s < STUDENTS; s++) {
        printf("%-8d %-8d %-10.2f %-7c %s\n",
               s + 1, total[s], average[s], grade[s], remarks[s]);
    }

    /* Comparison demo */
    int num = 10;
    printf("\n--- Comparison demo ---\n");
    printf("Original value: %d\n", num);
    incrementByValue(num);
    printf("After incrementByValue: %d\n", num);
    incrementByReference(&num);
    printf("After incrementByReference: %d\n", num);
    /* By value, the function gets a copy of num, so the original stays 10.
       By reference, it gets num's address, so it changes the original to 11. */

    return 0;
}