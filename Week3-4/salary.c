#include <stdio.h>

int main()
{
    // ---------- LAB 1: EMPLOYEE SALARY CALCULATOR ----------
    float basicSalary, housing, transport, tax;
    float grossSalary, netSalary;

    printf("EMPLOYEE SALARY CALCULATOR\n");
    printf("---------------------------\n");

    printf("Enter basic salary: ");
    scanf("%f", &basicSalary);

    printf("Enter housing allowance: ");
    scanf("%f", &housing);

    printf("Enter transport allowance: ");
    scanf("%f", &transport);

    printf("Enter tax: ");
    scanf("%f", &tax);

    grossSalary = basicSalary + housing + transport;
    netSalary = grossSalary - tax;

    printf("\nGross Salary: %.2f\n", grossSalary);
    printf("Net Salary: %.2f\n", netSalary);

    if (netSalary >= 20000)
    {
        printf("Income Category: High Income\n");
    }
    else
    {
        printf("Income Category: Standard Income\n");
    }

    return 0;
}