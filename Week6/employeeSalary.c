#include <stdio.h>

#define SIZE 50

int main() {
    float salaries[SIZE];
    float total = 0, average, highest, lowest;
    float search;
    int found = 0;

    for (int i = 0; i < SIZE; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    printf("\n--- Employee Salaries ---\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }

    highest = salaries[0];
    lowest = salaries[0];

    for (int i = 0; i < SIZE; i++) {
        total = total + salaries[i];

        if (salaries[i] > highest) {
            highest = salaries[i];
        }
        if (salaries[i] < lowest) {
            lowest = salaries[i];
        }
    }

    average = total / SIZE;

    printf("\n--- Salary Report ---\n");
    printf("Total salary:   %.2f\n", total);
    printf("Average salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary:  %.2f\n", lowest);

    printf("\nEnter a salary to search for: ");
    scanf("%f", &search);

    for (int i = 0; i < SIZE; i++) {
        if (salaries[i] == search) {
            printf("Salary found for employee %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Salary not found.\n");
    }

    return 0;
}