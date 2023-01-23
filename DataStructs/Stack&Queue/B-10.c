// Infix To Postfix
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

char stack[MAX], infix[MAX], postfix[MAX];
int top = -1, pos = 0;
bool success = false;

int preced(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '$')
        return 3;
    else if(ch=='(' || ch == ')')
        return 0;
    else
        return -1;
}

bool isfull()
{
    if (top == MAX - 1)
        return true;
    else
        return false;
}

bool isempty()
{
    if (top == -1)
        return true;
    else
        return false;
}

void push(char a)
{
    if (isfull())
    {
        printf("Full\n");
        return;
    }
    top++;
    stack[top] = a;
}

char pop()
{
    if (isempty())
    {
        printf("Nothing to return\n");
        return -1;
    }

    return stack[top--];
}

void convertion()
{
    if (infix[0] == '\0')
    {
        printf("Invalid Input\n");
        return;
    }
    int i;
    char symbol, temp;
    for (i = 0; infix[i] != '\0'; i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while ((temp = pop()) != '(')
                postfix[pos++] = temp;
            break;
        case '+':
        case '-':
        case '/':
        case '*':
        case '$':
            while (!isempty() && preced(stack[top]) >= preced(symbol) && preced(symbol) != -1)
            {
                temp = pop();
                postfix[pos++] = temp;
            }
            push(symbol);
            break;
        default:
            if (!isalpha(symbol))
            {
                printf("Something is not right\n");
                success = false;
                return;
            }
            else
            {
                postfix[pos++] = symbol;
                success = true;
                break;
            }
        }
    }
    while (!isempty())
    {
        temp = pop();
        postfix[pos++] = temp;
    }
}

int main()
{
    printf("Enter the infix expression\n");
    gets(infix);
    convertion();
    if (success)
    {
        printf("The postfix expression is\n");
        puts(postfix);
    }
    return 0;
}