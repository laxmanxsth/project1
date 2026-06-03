#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at Beginning
void insertBeg()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;
        while(temp->next != head)
            temp = temp->next;

        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
}

// Insert at End
void insertEnd()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;
        while(temp->next != head)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = head;
    }
}

// Delete at Beginning
void deleteBeg()
{
    struct node *temp, *last;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        last = head;
        while(last->next != head)
            last = last->next;

        temp = head;
        head = head->next;
        last->next = head;

        free(temp);
    }
}

// Delete at End
void deleteEnd()
{
    struct node *temp, *prev;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        while(temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        free(temp);
    }
}

// Traverse
void trav()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("\n");
}

int main()
{
    int ch;

    do
    {
        printf("\n1.Insert Beginning");
        printf("\n2.Insert End");
        printf("\n3.Delete Beginning");
        printf("\n4.Delete End");
        printf("\n5.Traverse");
        printf("\n6.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: insertBeg(); break;
            case 2: insertEnd(); break;
            case 3: deleteBeg(); break;
            case 4: deleteEnd(); break;
            case 5: trav(); break;
            case 6: break;
            default: printf("Invalid Choice\n");
        }
    } while(ch != 6);

    return 0;
}

