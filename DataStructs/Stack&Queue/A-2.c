//Stack Using STRUCTURES

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct STACK{
int a[MAX];
int top;
}stack;

void push(stack *s, int num)
{
    if (s->top == MAX - 1)
    {
        printf("The array is full\n");
    }
    else
    {
        s->top++;
        s->a[s->top] = num;
    }
}

int pop(stack *s)
{
    if (s->top == -1)
    {
        printf("The stack is empty\n");
        return -1;
    }
    else
    {
        int temp = s->a[s->top];
        s->top--;
        return temp;
    }
}

void display(stack *s)
{
    if (s->top == -1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("Printing the stack\n||");
        for (int i = 0; i <= s->top; i++)
            printf("%d ", s->a[i]);
        printf("||\n");
    }
}

int main()
{   
    stack s;
    s.top = -1;
    int choice, num;
    while (1)
    {
        printf("Enter your choice: 1)Push 2)Pop 3)Display 4)Exit\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number to push: ");
            scanf("%d", &num);
            printf("\n");
            push(&s,num);
            break;
        case 2:
            printf("Returning %d\n", pop(&s));
            break;
        case 3:
            display(&s);
            break;
        case 4:
            exit(0);
        default:
            printf("Somethings not right\n");
        }
    }
    return 0;
}