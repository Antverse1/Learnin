// Circular Doubly Linked List

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE
{
    struct NODE *left;
    int data;
    struct NODE *right;
} node;

typedef struct
{
    node *head;
} list;

node *create()
{
    node *temp;
    temp = NULL;
    temp = (node *)malloc(sizeof(node));

    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert_top(list *l)
{
    node *temp = create();
    printf("Enter element: \n");
    scanf("%d", &temp->data);
    if (l->head == NULL)
    {
        l->head = temp;
        temp->left = l->head;
        temp->right = l->head;
    }
    else
    {
        temp->right = l->head;
        temp->left = l->head->left;
        l->head->left->right = temp;
        l->head->left = temp;
        l->head = temp;
    }
}

int delete_rear(list *l)
{
    if (l->head == NULL)
    {
        printf("Nothing to delete\n");
        return -1;
    }
    else if (l->head->right == l->head)
    {
        int temp = l->head->data;
        free(l->head);
        l->head = NULL;
        return temp;
    }
    else
    {
        node *ptr;
        ptr = l->head->left;
        int temp = ptr->data;
        ptr->left->right = ptr->right;
        ptr->right->left = ptr->left;
        free(ptr);

        return temp;
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
        while (ptr->right != l->head)
        {
            printf("%d ", ptr->data);
            ptr = ptr->right;
        }
        printf("%d", ptr->data);
    }
}

void insert_right(list *l)
{
    if (l->head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        int key;
        node *ptr = l->head;
        printf("Enter the key: ");
        scanf("%d", &key);
        bool found = false;
        while (1)
        {
            if (key == ptr->data)
            {
                found = true;
                break;
            }
            if (ptr->right == l->head)
                break;
            ptr = ptr->right;
        }
        if (!found)
        {
            printf("The Key is not Found\n");
            return;
        }
        else
        {
            node *temp = create();
            printf("Enter element: \n");
            scanf("%d", &temp->data);
            temp->right = ptr->right;
            ptr->right->left = temp;
            temp->left = ptr;
            ptr->right = temp;
        }
    }
}

int main()
{
    list l1;
    l1.head = NULL;
    int choice;

    while (1)
    {

        printf("\nEnter:\n1)Adding Top \n2)Delete Rear \n3)Insert Right \n4)Display \n5)Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_top(&l1);
            break;
        case 2:
            printf("\nDeletes: %d\n", delete_rear(&l1));
            break;
        case 3:
            insert_right(&l1);
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