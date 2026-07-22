#include <stdio.h>
int main() {
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
    float totalSalary;

    printf("Enter your basic salary:\n");
    scanf("%f", &basicSalary);
    
    printf("Enter housing allowance:\n");
    scanf("%f", &housingAllowance);

    printf("Enter your transport allowance:\n");
    scanf("%f", &transportAllowance);

    totalSalary=basicSalary+housingAllowance+transportAllowance;

    printf("\n-------SALARY CALCULATION-------\n");
    printf("Basic slary:%.2f\n", basicSalary);
    printf("Housing allowance:%.2f\n", housingAllowance);
    printf("Transport allowance:%.2f\n", transportAllowance);
    printf("Total salary:%.2f\n", totalSalary);
    printf("\n---------------------------------\n");
    return 0;
}


