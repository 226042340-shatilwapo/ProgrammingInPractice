#include <stdio.h>

#define SIZE 10   

int main() {
    float budgets[SIZE];
    float total = 0, average, temp;

    for (int i = 0; i < SIZE; i++) {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
    }

    printf("\n--- Department Budgets ---\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Department %d: %.2f\n", i + 1, budgets[i]);
    }

    for (int i = 0; i < SIZE; i++) {
        total = total + budgets[i];
    }
    average = total / SIZE;

    printf("\nTotal budget:   %.2f\n", total);
    printf("Average budget: %.2f\n", average);

    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (budgets[j] > budgets[j + 1]) {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\n--- Budgets Sorted (Lowest to Highest) ---\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%.2f\n", budgets[i]);
    }

    return 0;
}