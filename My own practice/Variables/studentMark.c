#include <stdio.h>
int main() 
{
    int test1;
    int test2;
    int assignmentMark;
    float averageMark;

    printf("Enter test 1 mark:\n");
    scanf("%d", &test1);

    printf("Enter test 2 mark:\n");
    scanf("%d", &test2);

    printf("Enter assignment mark:\n");
    scanf("%d", &assignmentMark);
   averageMark=(test1+test2+assignmentMark)/3.0;

    printf("\n-------STUDENT.MARK REPORT-------\n");
    printf("Test 1 mark:%d\n", test1);
    printf("Test 2 mark:%d\n", test2);
    printf("Assignment mark:%d\n", assignmentMark);
    printf("Average:%.2f\n", averageMark);
    printf("\n--------------------------------\n");
    return 0;
}


