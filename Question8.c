#include <stdio.h>
#include <stdlib.h>

/* Print every item in stock (positions start at 1) */
void displayStock(int *p, int n) {
    if (n == 0) {
        printf("Stock is empty.\n");
        return;
    }
    for (int i = 0; i < n; i++)
        printf("Item %d: %d\n", i + 1, *(p + i));
}

/* Print total stock and the item with the lowest stock */
void printSummary(int *p, int n) {
    if (n == 0) {
        printf("Total stock: 0 | No items left.\n");
        return;
    }
    int total = 0, minPos = 0;
    for (int i = 0; i < n; i++) {
        total += *(p + i);
        if (*(p + i) < *(p + minPos))
            minPos = i;
    }
    printf("Total stock: %d | Lowest stock: item %d (%d)\n",
           total, minPos + 1, *(p + minPos));
}

/* Update stock of one item; position is checked for validity */
void updateStock(int *p, int n) {
    int pos, value;
    printf("Enter position (1-%d): ", n);
    scanf("%d", &pos);
    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return;
    }
    printf("Enter new stock value: ");
    scanf("%d", &value);
    *(p + pos - 1) = value;
    printf("Stock updated.\n");
    printSummary(p, n);
}

/* Insert: new array one bigger, copy old values, add new one, free old */
void insertItem(int **p, int *n) {
    int pos, value;
    printf("Enter position to insert at (1-%d): ", *n + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > *n + 1) {
        printf("Invalid position!\n");
        return;
    }
    printf("Enter stock value of new item: ");
    scanf("%d", &value);

    int *newArr = (int *)malloc((*n + 1) * sizeof(int));
    if (newArr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    int idx = pos - 1;
    for (int i = 0; i < idx; i++)
        *(newArr + i) = *(*p + i);
    *(newArr + idx) = value;
    for (int i = idx; i < *n; i++)
        *(newArr + i + 1) = *(*p + i);

    free(*p);
    *p = newArr;
    (*n)++;
    printf("Item inserted.\n");
    printSummary(*p, *n);
}

/* Delete: new array one smaller, copy all except deleted, free old */
void deleteItem(int **p, int *n) {
    if (*n == 0) {
        printf("Nothing to delete.\n");
        return;
    }
    int pos;
    printf("Enter position to delete (1-%d): ", *n);
    scanf("%d", &pos);
    if (pos < 1 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }

    int *newArr = NULL;
    if (*n > 1) {
        newArr = (int *)malloc((*n - 1) * sizeof(int));
        if (newArr == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        int k = 0;
        for (int i = 0; i < *n; i++) {
            if (i == pos - 1)
                continue;
            *(newArr + k) = *(*p + i);
            k++;
        }
    }
    free(*p);
    *p = newArr;
    (*n)--;
    printf("Item deleted.\n");
    printSummary(*p, *n);
}

/* Bubble sort (ascending) using pointers */
void sortStock(int *p, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(p + j) > *(p + j + 1)) {
                int temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;
            }
        }
    }
    printf("Stock sorted in ascending order.\n");
    printSummary(p, n);
}

int main(void) {
    int n;

    do {
        printf("Enter starting size n (3 to 8): ");
        scanf("%d", &n);
        if (n < 3 || n > 8)
            printf("Invalid! n must be between 3 and 8.\n");
    } while (n < 3 || n > 8);

    int *stock = (int *)malloc(n * sizeof(int));
    if (stock == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter stock of item %d: ", i + 1);
        scanf("%d", stock + i);
    }

    int choice;
    do {
        printf("\n===== MENU =====\n");
        printf("1. Display stock\n");
        printf("2. Update stock of one item\n");
        printf("3. Insert a new item\n");
        printf("4. Delete an item\n");
        printf("5. Sort stock\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: displayStock(stock, n); break;
            case 2: updateStock(stock, n);  break;
            case 3: insertItem(&stock, &n); break;
            case 4: deleteItem(&stock, &n); break;
            case 5: sortStock(stock, n);    break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    free(stock);   /* free memory before the program ends */
    stock = NULL;
    return 0;
}