#include <stdio.h>
int main() {
    float salary;
    float totalSalary;
    float highSalary;
    float lowSalary;
    float average;

  for (int i = 1; i <= 50; i++) { 
 
        printf("Enter salary for employee %d: ", i); 
        scanf("%f", &salary); 
 
        totalSalary = totalSalary + salary; 
 
        if (i == 1) { 
            highSalary = salary; 
            lowSalary = salary; 
        } 
 
 
        if (salary > highSalary) { 
            highSalary = salary; 
        } 
 
        if (salary < lowSalary) { 
            lowSalary = salary; 
        } 
    } 
 
    average = totalSalary / 50; 
 
    printf("\n--- Salary Report ---\n"); 
    printf("Average salary: %.2f\n", average); 
    printf("Highest salary: %.2f\n", highSalary); 
    printf("Lowest salary: %.2f\n", lowSalary); 
 
    return 0; 
} 
 