#include <stdio.h>
int main()
{
    char initial;
    int age;
    double salary;
    int yearsOfservice;

    printf("Enter initial:\n");
    scanf("%c", &initial);

    printf("Enter age:\n");
    scanf("%d",&age);

    printf("Enter salary:\n");
    scanf("%lf", &salary);

    printf("Enter years of service:\n");
    scanf("%d", &yearsOfservice);
printf("\n-------EMPLOYEE INFORMATION-------\n");
printf("Employee initial:%c\n", initial);
printf("Age:%d\n", age);
printf("Salary:%.2lf\n", salary);
printf("Years of service:%d\n", yearsOfservice);
return 0;
}
