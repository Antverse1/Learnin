//Stack Using ARRAY

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int a[MAX];
int top = -1;

void push(int num)
{
    if (top == MAX - 1)
    {
        printf("The array is full\n");
    }
    else
    {
        top++;
        a[top] = num;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("The stack is empty\n");
        return -1;
    }
    else
    {
        int temp = a[top];
        top--;
        return temp;
    }
}

void display()
{
    if (top == -1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("Printing the stack\n||");
        for (int i = 0; i <= top; i++)
            printf("%d ", a[i]);
        printf("||\n");
    }
}

int main()
{
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
            push(num);
            break;
        case 2:
            printf("Returning %d\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Somethings not right\n");
        }
    }
    return 0;
}