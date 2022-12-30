#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct bank
{
    char name[50]; //name of the person
    int accno; //account no.
    float bal; //balance
    float dep; //deposit
};

void Creation(struct bank *s, int *f);
void Deposit(struct bank *s);
void Withdraw(struct bank *s);

int main()
{   
    int fun, re, i=0, a=0, j;
    struct bank s[a];
    printf("\nWelcome to ABC bank");
    printf("\nWhat would you like to do today?");
rerun:
    printf("\n1) Create new account.\n2) Deposit into account.\n3) Withdraw from account");
    printf("\nEnter the number of the function like '1' or '2' or '3' \n");
    scanf("%d",&fun);
    switch (fun)
    {
    case 1:
        printf("\nCreating a new account");
        s[a].bal=0;
        Creation(&s[a],&a);
        a++;
        break;

    case 2:
        printf("\nDepositing money into account");
        printf("\nEnter your account number: \n");
        scanf("%d", &i);
        i = i - 1000;
        if(i<0 || i>a)
        {
            printf("\nEntered Account number does not exits please retry");
            break;
        }
        printf("Account Name is %s\nCurrent Balance is %f",s[i].name, s[i].bal);
        Deposit(&s[i]);
        printf("New Balance is %f",s[i].bal);
        break;

    case 3:
        printf("\nWithdrawing money from account");
        printf("\nEnter your account number: \n");
        scanf("%d", &i);
        i = i - 1000;
        if(i<0 || i>a)
        {
            printf("\nEntered Account number does not exits please retry");
            break;
        }

        printf("Account Name is %s\nCurrent Balance is %f",s[i].name, s[i].bal);
        Withdraw(&s[i]);
        printf("\nPost operation Balance is %f",s[i].bal);
        break;
    
    default:
        printf("Entered option is invalid");
        break;
    }

    printf("\nDo you wish to do more operations? If YES, press 1. If NO, press 0.\n");
    scanf("%d",&re);
    if(re==1)
        goto rerun;
    else
        printf("\nThank you for using our services");

    return 0;

}

void Creation(struct bank *s, int *f)
{
    printf("\nEnter your name: ");
    scanf("%s",s->name);
    printf("\nAssigning account number......\n");
    Sleep(3000);
    s->accno = 1000+*f;
    printf("Your account number is %d",s->accno);
    printf("\nTo create an account your must deposit a minimum balance of Rs.500\n");
    Deposit(&s[*f]);
}

void Deposit(struct bank *s)
{
minbal:
    s->dep = 0;
    printf("\nEnter the amount you are depositing\n");
    scanf("%f",&s->dep);
    s->bal= s->bal + s->dep;
    if(s->bal<500)
    {
        printf("Balance is less than Rs.500 Please add %f more.",500-s->bal);
        goto minbal;
    }
}

void Withdraw(struct bank *s)
{
    float w;
    if(s->bal<500)
    {
        printf("\nWithdrawl is not possible as balance is less that Rs.500. Please deposit before continuing.");
    }
    else
    {
        printf("\nEnter the amount you are withdrawing\n");
        scanf("%f",&w);
        s->bal= s->bal - w;
    }
}