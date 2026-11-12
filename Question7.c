#include <stdio.h>

#define N 10

int findMax(int *p, int n) {
    int max = *p;
    for (int i = 1; i < n; i++)
        if (*(p + i) > max)
            max = *(p + i);
    return max;
}

int findMin(int *p, int n) {
    int min = *p;
    for (int i = 1; i < n; i++)
        if (*(p + i) < min)
            min = *(p + i);
    return min;
}

double findAverage(int *p, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += *(p + i);
    return (double)sum / n;
}

int countAbove(int *p, int n, double avg) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (*(p + i) > avg)
            count++;
    return count;
}

void reverseArray(int *p, int n) {
    int *start = p;
    int *end = p + n - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

/* Returns the index (0-based) of key, or -1 if not found */
int searchMark(int *p, int n, int key) {
    for (int i = 0; i < n; i++)
        if (*(p + i) == key)
            return i;
    return -1;
}

void printArray(int *p, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", *(p + i));
    printf("\n");
}

int main(void) {
    int marks[N];

    /* Input with validation (0 to 100) */
    for (int i = 0; i < N; i++) {
        do {
            printf("Enter marks of student %d (0-100): ", i + 1);
            scanf("%d", &marks[i]);
            if (marks[i] < 0 || marks[i] > 100)
                printf("Invalid! Marks must be between 0 and 100.\n");
        } while (marks[i] < 0 || marks[i] > 100);
    }

    double avg = findAverage(marks, N);

    printf("\n--- Class Report ---\n");
    printf("Highest mark : %d\n", findMax(marks, N));
    printf("Lowest mark  : %d\n", findMin(marks, N));
    printf("Average      : %.2f\n", avg);
    printf("Students above average: %d\n", countAbove(marks, N, avg));

    /* Search */
    int key;
    printf("\nEnter a mark to search: ");
    scanf("%d", &key);
    int pos = searchMark(marks, N, key);
    if (pos == -1)
        printf("Mark %d not found.\n", key);
    else
        printf("Mark %d found at position %d (roll no. %d).\n", key, pos, pos + 1);

    /* Pass count (40 or more) */
    int pass = 0;
    for (int i = 0; i < N; i++)
        if (marks[i] >= 40)
            pass++;

    /* Print before and after reversing */
    printf("\nBefore reversing: ");
    printArray(marks, N);
    reverseArray(marks, N);
    printf("After reversing : ");
    printArray(marks, N);

    printf("\nPass count (40 or more): %d\n", pass);

    return 0;
}