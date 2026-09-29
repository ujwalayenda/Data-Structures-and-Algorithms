//An expression-processing application receives an arithmetic expression in infix form. Write a C
program using a stack to convert it to postfix form while correctly handling parentheses and
operator precedence for +, -, *, / and ^. Test the program using an expression containing multiple
operators and parentheses.//
  //source code://
#include <stdio.h>
#include <ctype.h>
#include <string.h>
char stack[100];
int top = -1;
void push(char ch)
{
    top++;
    stack[top] = ch;
}
char pop()
{
    char ch = stack[top];
    top--;
    return ch;
}
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}
int main()
{
    char infix[100], postfix[100];
    int i, j = 0;
    char ch;
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];
        if (isalnum(ch))
        {
            postfix[j] = ch;
            j++;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }
            pop(); 
        }
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch))
            {
                postfix[j] = pop();
                j++;
            }
            push(ch);
        }
    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
//Input:
Enter an infix expression: A+B*(C-D)/E
Output:
Postfix expression: ABCD-*E/+ //
