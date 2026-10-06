#include <stdio.h>
#include <string.h>

#define SIZE 3

int main() {
    char registrations[SIZE][20];
    char search[20];
    int found = 0;

    for (int i = 0; i < SIZE; i++) {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }


    printf("\n--- Vehicle Registrations ---\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d. %s\n", i + 1, registrations[i]);
    }

    printf("\nEnter a registration number to search for: ");
    scanf("%19s", search);

    for (int i = 0; i < SIZE; i++) {
        if (strcmp(registrations[i], search) == 0) {
            printf("Registration found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Registration not found.\n");
    }

    return 0;
}