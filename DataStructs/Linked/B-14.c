// Doubly Linked List
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE
{
    struct NODE *next;
    int data;
    struct NODE *prev;
} node;

typedef struct LIST
{
    node *head;
    node *tail;
} list;

node *create()
{
    node *temp;
    temp = NULL;
    temp = (node *)malloc(sizeof(node));

    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void insert_front(list *l)
{
    node *temp = create();
    printf("Enter Element: ");
    scanf("%d", &temp->data);
    printf("\n");
    if (l->head == NULL)
    {
        l->head = temp;
        l->tail = temp;
    }
    else
    {
        temp->next = l->head;
        l->head->prev = temp;
        l->head = temp;
    }
}

int delete_specific(list *l)
{
    int temp;
    if (l->head == NULL)
    {
        printf("Nothing there to delete\n");
        temp = -1;
    }
    else
    {
        int ele;
        node *ptr = l->head;
        bool found = false;
        printf("Enter the element to search: ");
        scanf("%d", &ele);
        printf("\n");
        while (ptr != NULL)
        {
            if (ele == ptr->data)
            {
                found = true;
                break;
            }
            ptr = ptr->next;
        }
        if (!found)
        {
            printf("Element Doesn't Exist\n");
            return -1;
        }
        else
        {
            temp = ptr->data;
            if (l->head == l->tail)
            {
                free(ptr);
                l->head = NULL;
                l->tail = NULL;
            }
            if (ptr == l->head)
            {
                ptr->next->prev = NULL;
                l->head = ptr->next;
                free(ptr);
            }
            else if (ptr == l->tail)
            {
                ptr->prev->next = NULL;
                l->tail = ptr->prev;
                free(ptr);
            }
            else
            {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                free(ptr);
            }
            return temp;
        }
    }
}

void display(list *l)
{
    if (l->head == NULL)
    {
        printf("Nothing To print\n");
    }
    else
    {
        node *ptr;
        ptr = l->head;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n\n");
    }
}

void insert_position(list *l)
{
    node *temp = create();
    printf("Enter Element: ");
    scanf("%d", &temp->data);
    printf("\n");
    if (l->head == NULL)
    {
        printf("No Element in the list\nInserting at position 0\n");
        l->head = temp;
        l->tail = temp;
    }
    else
    {
        int position, i = 1;
        node *ptr=l->head;
        bool found = false;
        printf("Enter the position(starting 1): ");
        scanf("%d",&position);

        while (ptr != NULL)
        {
            if (i == position)
            {
                found = true;
                break;
            }
            ptr = ptr->next;
            i++;
        }
        if (!found)
        {
            printf("Position Exceeds Size\n");
        }
        else
        {
            if (ptr == l->head)
            {
                temp->next = l->head;
                l->head->prev = temp;
                l->head = temp;
            }
            else if (ptr == l->tail)
            {
                l->tail->next = temp;
                temp->prev = l->tail;
                l->tail = temp;
            }
            else
            {
                ptr->next->prev=temp;
                temp->next = ptr->next;
                ptr->next = temp;
                temp->prev = ptr;
            }
        }
    }
}

int main()
{
    list l1;
    l1.head = NULL;
    l1.tail = NULL;
    int choice;

    while (1)
    {
        printf("\nEnter:1)Insert Front 2)Delete Spec 3)Insert Position 4)Display 5)Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_front(&l1);
            break;
        case 2:
            printf("\nDeletes: %d\n", delete_specific(&l1));
            break;
        case 3:
            insert_position(&l1);
            break;
        case 4:
            display(&l1);
            break;
        case 5:
            exit(0);

        default:
            printf("\nInvalid");
        }
    }
    return 0;
}