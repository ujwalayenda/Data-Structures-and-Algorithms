//A company stores employee IDs in ascending order. Write a C program that accepts n employee
IDs, searches for a required ID using Binary Search, displays its position when found, reports
when it is absent, and counts the number of comparisons. Test the program for both successful
and unsuccessful searches.//
//source code://
#include <stdio.h>
int main()
{
    int a[100], n, key;
    int low, high, mid;
    int comparisons = 0;
    int found = 0;
    int i;
    printf("Enter number of employee IDs: ");
    scanf("%d", &n);
    printf("Enter employee IDs in ascending order:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter employee ID to search: ");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        comparisons++;
        if (a[mid] == key)
        {
            found = 1;
            break;
        }
        else if (key < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (found == 1)
    {
        printf("Employee ID %d found at position %d\n", key, mid + 1);
    }
    else
    {
        printf("Employee ID %d is not found\n", key);
    }
    printf("Number of comparisons = %d\n", comparisons);
    return 0;
}
//output1:
Enter number of employee IDs: 6
Enter employee IDs in ascending order:
101 105 110 115 120 125
Enter employee ID to search: 120

Employee ID 120 found at position 5
Number of comparisons = 2
output2:
Enter number of employee IDs: 6
Enter employee IDs in ascending order:
101 105 110 115 120 125
Enter employee ID to search: 118

Employee ID 118 is not found
Number of comparisons = 3 //
