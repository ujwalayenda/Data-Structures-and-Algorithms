//A teacher wants to arrange student marks in ascending order and also measure how much
rearrangement is necessary. Write a C program using Insertion Sort that accepts n marks, displays
the array after every pass, counts the total number of element shifts, and displays the final sorted
list and shift count.//
 // source code://
#include <stdio.h>
int main()
{
    int a[100], n;
    int i, j, key;
    int shifts = 0;
    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Enter student marks:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            shifts++;
            j--;
        }
        a[j + 1] = key;
        printf("After pass %d: ", i);
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
    printf("\nFinal sorted list: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nTotal number of shifts = %d\n", shifts);
    return 0;
}
?/input:
Enter number of students: 5
Enter student marks:
45 20 35 10 50
  output:
After pass 1: 20 45 35 10 50
After pass 2: 20 35 45 10 50
After pass 3: 10 20 35 45 50
After pass 4: 10 20 35 45 50

Final sorted list: 10 20 35 45 50
Total number of shifts = 6 //
