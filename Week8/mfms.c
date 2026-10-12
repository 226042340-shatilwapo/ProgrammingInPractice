#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 5
#define LEN 100
#define VAT_RATE 0.15f

/* Supplier data (from Week 7), shared by the supplier functions */
char names[MAX_SUPPLIERS][LEN];
char emails[MAX_SUPPLIERS][LEN];
char phones[MAX_SUPPLIERS][LEN];
char towns[MAX_SUPPLIERS][LEN];
int supplierCount = 0;

/* ---------- Function prototypes ---------- */
void displayWelcome();
void displayMenu();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);

void salaryOption();
void vatOption();
void budgetOption();
void employeeSearchOption();

void supplierMenu();
void addSupplier();
void displaySupplier();
void searchSupplier();

void clearInput();
void readLine(const char *prompt, char *dest, int size);

/* ---------- main ---------- */
int main()
{
    int choice;

    displayWelcome();

    do
    {
        displayMenu();
        choice = 0;
        scanf("%d", &choice);
        clearInput();

        switch (choice)
        {
            case 1: salaryOption();         break;
            case 2: vatOption();            break;
            case 3: budgetOption();         break;
            case 4: employeeSearchOption(); break;
            case 5: supplierMenu();         break;
            case 6: printf("Goodbye.\n");   break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}

/* ---------- Menu and welcome ---------- */
void displayWelcome()
{
    printf("Welcome to the Municipal Financial Management System\n");
}

void displayMenu()
{
    printf("\n============================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("1. Calculate Employee Salary\n");
    printf("2. Calculate VAT\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Supplier Management\n");
    printf("6. Exit\n");
    printf("\nEnter choice: ");
}

/* ---------- Calculation functions ---------- */
float calculateVAT(float amount)
{
    return amount * VAT_RATE;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;   
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

int searchEmployee(int id, int ids[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }
    return -1;
}

void salaryOption()
{
    float basic, housing, transport;

    printf("Basic salary: ");
    scanf("%f", &basic);
    printf("Housing allowance: ");
    scanf("%f", &housing);
    printf("Transport allowance: ");
    scanf("%f", &transport);
    clearInput();

    printf("\nGross salary: %.2f\n", calculateSalary(basic, housing, transport));
}

void vatOption()
{
    float amount;

    printf("Enter amount: ");
    scanf("%f", &amount);
    clearInput();

    printf("\nVAT: %.2f\n", calculateVAT(amount));
}

void budgetOption()
{
    float revenue, expenses, balance;

    printf("Enter total revenue: ");
    scanf("%f", &revenue);
    printf("Enter total expenses: ");
    scanf("%f", &expenses);
    clearInput();

    balance = calculateBudget(revenue, expenses);
    printf("\nBalance: %.2f\n", balance);

    if (balance > 0)
    {
        printf("SURPLUS\n");
    }
    else if (balance < 0)
    {
        printf("DEFICIT\n");
    }
    else
    {
        printf("BALANCED\n");
    }
}

void employeeSearchOption()
{
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int size = sizeof(employeeIDs) / sizeof(employeeIDs[0]);
    int id, position;

    printf("Enter employee ID: ");
    scanf("%d", &id);
    clearInput();

    position = searchEmployee(id, employeeIDs, size);

    if (position == -1)
    {
        printf("Employee not found.\n");
    }
    else
    {
        printf("Employee found at position %d.\n", position);
    }
}


void supplierMenu()
{
    int choice;

    do
    {
        printf("\n--- SUPPLIER MANAGEMENT ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back to main menu\n");
        printf("\nEnter choice: ");

        choice = 0;
        scanf("%d", &choice);
        clearInput();

        switch (choice)
        {
            case 1: addSupplier();      break;
            case 2: displaySupplier();  break;
            case 3: searchSupplier();   break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 4);
}

void addSupplier()
{
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier list is full (%d suppliers).\n", MAX_SUPPLIERS);
        return;
    }

    readLine("Enter supplier name: ", names[supplierCount], LEN);
    readLine("Enter email: ", emails[supplierCount], LEN);
    readLine("Enter phone: ", phones[supplierCount], LEN);
    readLine("Enter town: ", towns[supplierCount], LEN);
    supplierCount++;
    printf("Supplier added.\n");
}

void displaySupplier()
{
    int i;

    if (supplierCount == 0)
    {
        printf("No suppliers stored yet.\n");
        return;
    }

    for (i = 0; i < supplierCount; i++)
    {
        printf("\n--- SUPPLIER %d DETAILS ---\n", i + 1);
        printf("Name : %s\n", names[i]);
        printf("Email: %s\n", emails[i]);
        printf("Phone: %s\n", phones[i]);
        printf("Town : %s\n", towns[i]);
    }
}

void searchSupplier()
{
    char searchName[LEN];
    int i;

    readLine("Enter supplier name to search: ", searchName, LEN);

    for (i = 0; i < supplierCount; i++)
    {
        if (strcmp(searchName, names[i]) == 0)
        {
            printf("Supplier found.\n");
            printf("Email: %s | Phone: %s | Town: %s\n",
                   emails[i], phones[i], towns[i]);
            return;
        }
    }
    printf("Supplier not found.\n");
}

void clearInput()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void readLine(const char *prompt, char *dest, int size)
{
    printf("%s", prompt);
    fgets(dest, size, stdin);
    dest[strcspn(dest, "\n")] = '\0';
}