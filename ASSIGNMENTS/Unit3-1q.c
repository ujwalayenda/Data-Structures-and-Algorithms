//A department maintains student roll numbers dynamically. Write a C program using a Singly
Linked List to create the list, insert at the beginning and end, search for a specified roll number,
delete a specified roll number, and display the updated list after each operation. Handle the case
when a requested roll number is not available.//
  
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int roll;
    struct Node *next;
};
struct Node *head = NULL;
struct Node* createNode(int roll)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->roll = roll;
    newNode->next = NULL;
    return newNode;
}
void insertBeginning(int roll)
{
    struct Node *newNode;
    newNode = createNode(roll);
    newNode->next = head;
    head = newNode;
    printf("Roll number %d inserted at beginning.\n", roll);
}
void insertEnd(int roll)
{
    struct Node *newNode, *temp;
    newNode = createNode(roll);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Roll number %d inserted at end.\n", roll);
}
void search(int roll)
{
    struct Node *temp;
    int position = 1;
    temp = head;
    while (temp != NULL)
    {
        if (temp->roll == roll)
        {
            printf("Roll number %d found at position %d.\n",
                   roll, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Roll number %d is not available in the list.\n", roll);
}
void deleteNode(int roll)
{
    struct Node *temp, *prev;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (head->roll == roll)
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("Roll number %d deleted successfully.\n", roll);
        return;
    }
    temp = head;
    while (temp != NULL && temp->roll != roll)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Roll number %d is not available. Cannot delete.\n",
               roll);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Roll number %d deleted successfully.\n", roll);
}
void display()
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    printf("Student Roll Numbers: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->roll);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int n, i, roll, choice;
    printf("Enter number of students to create: ");
    scanf("%d", &n);
    printf("Enter roll numbers:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &roll);
        insertEnd(roll);
    }
    printf("\nInitial List:\n");
    display();
    while (1)
    {
        printf("\n--- Singly Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertBeginning(roll);
                display();
                break;
            case 2:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertEnd(roll);
                display();
                break;
            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &roll);
                search(roll);
                break;
            case 4:
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);
                deleteNode(roll);
                display();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
//output:
Enter number of students to create: 3
Enter roll numbers:
101
102
103

Initial List:
Student Roll Numbers: 101 -> 102 -> 103 -> NULL

--- Singly Linked List ---
1. Insert at Beginning
2. Insert at End
3. Search
4. Delete
5. Display
6. Exit
Enter your choice: 1
Enter roll number: 100
Roll number 100 inserted at beginning.
Student Roll Numbers: 100 -> 101 -> 102 -> 103 -> NULL

Enter your choice: 2
Enter roll number: 104
Roll number 104 inserted at end.
Student Roll Numbers: 100 -> 101 -> 102 -> 103 -> 104 -> NULL

Enter your choice: 3
Enter roll number to search: 102
Roll number 102 found at position 3.

Enter your choice: 4
Enter roll number to delete: 102
Roll number 102 deleted successfully.
Student Roll Numbers: 100 -> 101 -> 103 -> 104 -> NULL

Enter your choice: 4
Enter roll number to delete: 999
Roll number 999 is not available. Cannot delete.
Student Roll Numbers: 100 -> 101 -> 103 -> 104 -> NULL //
