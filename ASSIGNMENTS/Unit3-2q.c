//Develop a C program for a Doubly Linked List representing a sequence of web pages visited by a
user. The program should insert a new page, move forward and backward, delete a specified
page, and display the pages from first-to-last and last-to-first while handling beginning and end
conditions correctly.//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char page[50];
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *current = NULL;
struct Node* createNode(char page[])
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->page, page);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertPage(char page[])
{
    struct Node *newNode, *temp;
    newNode = createNode(page);
    if (head == NULL)
    {
        head = newNode;
        current = head;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        current = newNode;
    }
    printf("Page inserted successfully.\n");
}
void moveForward()
{
    if (current == NULL)
    {
        printf("No pages available.\n");
    }
    else if (current->next == NULL)
    {
        printf("Already at the last page. Cannot move forward.\n");
    }
    else
    {
        current = current->next;
        printf("Current page: %s\n", current->page);
    }
}
void moveBackward()
{
    if (current == NULL)
    {
        printf("No pages available.\n");
    }
    else if (current->prev == NULL)
    {
        printf("Already at the first page. Cannot move backward.\n");
    }
    else
    {
        current = current->prev;
        printf("Current page: %s\n", current->page);
    }
}
void deletePage(char page[])
{
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->page, page) == 0)
        
            if (temp->prev == NULL)
            {
                head = temp->next;

                if (head != NULL)
                    head->prev = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
            }
            if (current == temp)
            {
                if (temp->next != NULL)
                    current = temp->next;
                else
                    current = temp->prev;
            }
            free(temp)
            printf("Page deleted successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Page not found.\n");
}
void displayForward()
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("No pages available.\n");
        return;
    }
    temp = head;
    printf("Pages from first to last:\n");
    while (temp != NULL)
    {
        printf("%s", temp->page);
        if (temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}
void displayBackward()
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("No pages available.\n");
        return;
    }
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Pages from last to first:\n");
    while (temp != NULL)
    {
        printf("%s", temp->page);
        if (temp->prev != NULL)
            printf(" <-> ");
        temp = temp->prev;
    }
    printf("\n");
}
int main()
{
    int choice;
    char page[50];
    while (1)
    {
        printf("\n--- Web Page History ---\n");
        printf("1. Insert Page\n");
        printf("2. Move Forward\n");
        printf("3. Move Backward\n");
        printf("4. Delete Page\n");
        printf("5. Display First to Last\n");
        printf("6. Display Last to First\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter page name: ");
                scanf("%s", page);
                insertPage(page);
                break;
            case 2:
                moveForward();
                break;
            case 3:
                moveBackward();
                break;
            case 4:
                printf("Enter page to delete: ");
                scanf("%s", page);
                deletePage(page);
                break;
            case 5:
                displayForward();
                break;
            case 6:
                displayBackward();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

//output:
--- Web Page History ---
1. Insert Page
2. Move Forward
3. Move Backward
4. Delete Page
5. Display First to Last
6. Display Last to First
7. Exit

Enter your choice: 1
Enter page name: Google
Page inserted successfully.

Enter your choice: 1
Enter page name: YouTube
Page inserted successfully.

Enter your choice: 1
Enter page name: GitHub
Page inserted successfully.

Enter your choice: 5
Pages from first to last:
Google <-> YouTube <-> GitHub

Enter your choice: 6
Pages from last to first:
GitHub <-> YouTube <-> Google

Enter your choice: 3
Current page: YouTube

Enter your choice: 4
Enter page to delete: YouTube
Page deleted successfully.

Enter your choice: 5
Pages from first to last:
Google <-> GitHub //
