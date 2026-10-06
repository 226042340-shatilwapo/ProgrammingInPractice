#include <stdio.h>

#define SIZE 50   /* change to 3 while testing, then back to 50 */

int main() {
    float salaries[SIZE];
    float total, average, highest, lowest, search, temp;
    int choice;
    int captured = 0;   /* 0 = no salaries yet, 1 = captured */
    int found;

    do {
        printf("\n===== Employee Salary Management System =====\n");
        printf("1. Capture salaries\n");
        printf("2. Display all salaries\n");
        printf("3. Total salary expenditure\n");
        printf("4. Average salary\n");
        printf("5. Highest salary\n");
        printf("6. Lowest salary\n");
        printf("7. Search for a salary\n");
        printf("8. Sort salaries (lowest to highest)\n");
        printf("9. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        /* options 2 to 8 need data first */
        if (choice >= 2 && choice <= 8 && !captured) {
            printf("\nPlease capture salaries first (option 1).\n");
            continue;
        }

        switch (choice) {

            case 1:
                for (int i = 0; i < SIZE; i++) {
                    printf("Enter salary for employee %d: ", i + 1);
                    scanf("%f", &salaries[i]);
                }
                captured = 1;
                printf("\nSalaries captured.\n");
                break;

            case 2:
                printf("\n--- All Salaries ---\n");
                for (int i = 0; i < SIZE; i++) {
                    printf("%d. %.2f\n", i + 1, salaries[i]);
                }
                break;

            case 3:
                total = 0;
                for (int i = 0; i < SIZE; i++) {
                    total = total + salaries[i];
                }
                printf("\nTotal salary expenditure: %.2f\n", total);
                break;

            case 4:
                total = 0;
                for (int i = 0; i < SIZE; i++) {
                    total = total + salaries[i];
                }
                average = total / SIZE;
                printf("\nAverage salary: %.2f\n", average);
                break;

            case 5:
                highest = salaries[0];
                for (int i = 1; i < SIZE; i++) {
                    if (salaries[i] > highest) {
                        highest = salaries[i];
                    }
                }
                printf("\nHighest salary: %.2f\n", highest);
                break;

            case 6:
                lowest = salaries[0];
                for (int i = 1; i < SIZE; i++) {
                    if (salaries[i] < lowest) {
                        lowest = salaries[i];
                    }
                }
                printf("\nLowest salary: %.2f\n", lowest);
                break;

            case 7:
                printf("\nEnter a salary to search for: ");
                scanf("%f", &search);
                found = 0;
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
                break;

            case 8:
                /* bubble sort */
                for (int i = 0; i < SIZE - 1; i++) {
                    for (int j = 0; j < SIZE - i - 1; j++) {
                        if (salaries[j] > salaries[j + 1]) {
                            temp = salaries[j];
                            salaries[j] = salaries[j + 1];
                            salaries[j + 1] = temp;
                        }
                    }
                }
                printf("\n--- Salaries Sorted (Lowest to Highest) ---\n");
                for (int i = 0; i < SIZE; i++) {
                    printf("%.2f\n", salaries[i]);
                }
                break;

            case 9:
                printf("\nGoodbye.\n");
                break;

            default:
                printf("\nInvalid option. Choose 1 to 9.\n");
        }

    } while (choice != 9);

    return 0;
}