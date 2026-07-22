#include <stdio.h>
int main()
{
    float waterRevenue;
    float electricityRevenue;
    float propertyTax;
    float totalRevenue;

    printf("Enter water revenue:\n");
    scanf("%f", &waterRevenue);

    printf("Enter electricity revenue:\n");
    scanf("%f", &electricityRevenue);

    printf("Enter property tax revenue:\n");
    scanf("%f", &propertyTax);

    totalRevenue=waterRevenue+electricityRevenue+propertyTax;

    printf("\n-------MUNICIPAL REVENUE REPORT-------\n");
    printf("Water revenue:%.2f\n", waterRevenue);
    printf("Electricity revenue:%.2f\n", electricityRevenue);
    printf("Property tax revenue:%.2f\n", propertyTax);
    printf("Total revenue:%.2f\n", totalRevenue);
    printf("\n---------------------------------------\n");
    return 0;
}