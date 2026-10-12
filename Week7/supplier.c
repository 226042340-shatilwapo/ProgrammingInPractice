#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 5
#define LEN 100

void readLine(const char *prompt, char *dest, int size)
{
    printf("%s", prompt);
    fgets(dest, size, stdin);
    dest[strcspn(dest, "\n")] = '\0';
}

int main()
{
    char names[MAX_SUPPLIERS][LEN];
    char emails[MAX_SUPPLIERS][LEN];
    char phones[MAX_SUPPLIERS][LEN];
    char towns[MAX_SUPPLIERS][LEN];

    char searchName[LEN];
    char backup[LEN];
    char description[300];

    int count = 0;
    int choice, i, found, c;

    do
    {
        printf("\n================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");
        printf("\nEnter choice: ");

        choice = 0;
        scanf("%d", &choice);
        while ((c = getchar()) != '\n' && c != EOF);   /* clear leftover input */

        switch (choice)
        {
            case 1:
                if (count >= MAX_SUPPLIERS)
                {
                    printf("Supplier list is full (%d suppliers).\n", MAX_SUPPLIERS);
                }
                else
                {
                    readLine("Enter supplier name: ", names[count], LEN);
                    readLine("Enter email: ", emails[count], LEN);
                    readLine("Enter phone: ", phones[count], LEN);
                    readLine("Enter town: ", towns[count], LEN);
                    count++;
                    printf("Supplier added.\n");
                }
                break;

            case 2:
                if (count == 0)
                {
                    printf("No suppliers stored yet.\n");
                }
                for (i = 0; i < count; i++)
                {
                    printf("\n--- SUPPLIER %d DETAILS ---\n", i + 1);
                    printf("Name : %s\n", names[i]);
                    printf("Email: %s\n", emails[i]);
                    printf("Phone: %s\n", phones[i]);
                    printf("Town : %s\n", towns[i]);

                    /* strcpy: copy the name into a backup array */
                    strcpy(backup, names[i]);
                    printf("Backup copy of name: %s\n", backup);

                    /* strcat: build a sentence from pieces */
                    strcpy(description, names[i]);
                    strcat(description, " operates in ");
                    strcat(description, towns[i]);
                    strcat(description, ".");
                    printf("%s\n", description);
                }
                break;

            case 3:
                readLine("Enter supplier name to search: ", searchName, LEN);
                found = 0;
                for (i = 0; i < count; i++)
                {
                    if (strcmp(searchName, names[i]) == 0)
                    {
                        printf("Supplier found.\n");
                        printf("Email: %s | Phone: %s | Town: %s\n",
                               emails[i], phones[i], towns[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    printf("Supplier not found.\n");
                }
                break;

            case 4:
                if (count == 0)
                {
                    printf("No suppliers stored yet.\n");
                }
                for (i = 0; i < count; i++)
                {
                    printf("\nSupplier %d\n", i + 1);
                    printf("Supplier name length: %d\n", (int)strlen(names[i]));
                    printf("Email length: %d\n", (int)strlen(emails[i]));
                    printf("Town length: %d\n", (int)strlen(towns[i]));
                }
                break;

            case 5:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}