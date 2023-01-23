//Postfix Eval

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 10

int stack[MAX];
char postfix[MAX];
int top =-1, pos=0;

void push(int a)
{
    stack[++top] = a;
}

int pop()
{
    return stack[top--];
}

int operation(int op1, int op2, char op)
{
    switch(op)
    {
        case '+':return(op1+op2);
        case '-':return(op1-op2);
        case '*':return(op1*op2);
        case '/':return(op1/op2);
        case '$':return(pow(op1,op2));
        default: return -9999;
    }
}

int main()
{
    int i; char sym; int res,op1,op2;
    printf("Enter Postfix: ");
    gets(postfix);
    printf("\n");
    for(pos = 0; postfix[pos]!='\0';pos++)
    {
        sym = postfix[pos];
        if(isdigit(sym))
            push(sym-'0');
        else
        {
            op2=pop();
            printf("%d",op2);
            op1=pop();
            printf("%d",op1);
            res = operation(op1,op2,sym);
            if(res==-9999)
            {
                printf("Something went wrong\n");
                return 0;
            }
            push(res);
        }
    }
    printf("The Result is: %d",pop());
    return 0;
}