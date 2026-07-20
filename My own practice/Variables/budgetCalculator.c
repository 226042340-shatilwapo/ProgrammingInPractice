#include <stdio.h>
int main()
{
float revenue;
float expenses;
float difference;

printf("Enter revenue:\n");
scanf("%f", &revenue);

printf("Enter expenses:\n");
scanf("%f", &expenses);

difference= revenue-expenses;
printf("\n-------BUDGET.CALCULATED-------\n");
printf("Revenue:%.2f\n", revenue);
printf("Expenses:%.2f\n", expenses);
printf("Difference:%.2f\n", difference);
return 0;
}

