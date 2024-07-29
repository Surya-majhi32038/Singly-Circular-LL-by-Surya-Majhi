#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
int size = 0;
void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

int main()
{
    int choice = 0;
    while (1)
    {
        printf("\n....Main Menu....\n");

        printf("\nChoose one option from the following list...\n");
        printf("\nl.Insert in begining\n2.Insert at last\n3. Random insert an element \n4.Delete from last\n5. Delete from Beginning\n6.Random Delete  \n7.Search  \n 8.Dispaly \n 9. EXIT \n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice); // choice=3
        switch (choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            randominsert();
            break;
        case 4:
            last_delete();
            break;
        case 5:
           begin_delete();
            break;
        case 6:
           random_delete();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}
int isEmpty()
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}
void randominsert()
{
    
    int pos;
    printf("\n Enter the positoin :");
    scanf("%d", &pos);
    if (pos == 1)
    {
        beginsert();
    }
    else if (pos == size+1)
    {
        lastinsert();
    }
    else if((pos >=2) && (pos <= size) )
    {
        struct node *temp,*ptr;
        ptr = (struct node *)malloc(sizeof(struct node));
        int value;
        printf("\n Enter the value :");
        scanf("%d",&value);
        ptr->data = value;
        temp = head;
        while (pos < size - 1)
        {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
    else 
    {
        printf("\n Enterd Invailed Input ");
    }
}
void random_delete()
{
    if (isEmpty())
    {
        printf("\n UNDERFLOW");
        return;
    }
    
    int pos;
    printf("\n Enter the positoin :");
    scanf("%d", &pos);
    if (pos == 1)
    {
        begin_delete();
    }
    else if (pos == size)
    {
        last_delete();
    }
    else if((pos >=2)&&(pos < size))
    {
        struct node *temp,*ptr;
        temp = head;
        while (pos < size - 1)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        temp->next = ptr->next;
        printf("\n Deleted element %d",ptr->data);
        free(ptr);
    }
    else 
    {
        printf("\n Enterd invailed input ");
    }
}
void lastinsert()
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\n Linked list is full ");
        return;
    }
    int value;
    printf("\n Enter the data :");
    scanf("%d", &value);
    ptr->data = value;
    if (head == NULL)
    {
        head = ptr;
        ptr->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = head;
    }
    printf("\n Element add :%d", head->data);
    size++;
}
void begin_delete()
{
    if (isEmpty())
    {
        printf("\n UNDERFLOW");
        return;
    }
    struct node *temp;
    temp = head;
    // when it has one element

    while (temp->next != head)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        printf("\n deleted element = %d", head->data);
        size--;
        free(temp);
        head = NULL;
    }
    else
    {
        temp->next = head->next;
        printf("\n deleted element at first = %d", head->data);
        size--;
        free(head);
        head = temp->next;
    }
}
void last_delete()
{
    if (isEmpty())
    {
        printf("\n UNDERFLOW");
        return;
    }
    struct node *ptr, *pre_ptr;
    ptr = head;
    while (ptr->next != head)
    {
        pre_ptr = ptr;
        ptr = ptr->next;
    }
    // only when has a one node
    if (ptr == head)
    {
        printf("\n deleted element = %d", head->data);
        size--;
        free(ptr);
        head = NULL;
    }
    else
    {
        pre_ptr->next = ptr->next;
        printf("\n deleted element at last = %d", ptr->data);
        size--;
        free(ptr);
    }
}
void search()
{
    if (isEmpty())
    {
        printf("\n UNDERFLOW");
        return;
    }
    printf(" \n SHOW ALL ELEMENT \n");
    display();
    int se;
    printf("\n Enter the searched element :");
    scanf("%d", &se);
    // when we have a one element in the circular singly linked list

    if (head->data == se)
    {
        printf("\n Element found at 1 position ");
        return;
    }
    struct node *ptr = head;
    int counter = 0;
    while (ptr->next != head)
    {
        counter++;
        if (ptr->data == se)
        {
            printf("\n Element found at %d ", counter);
            return;
        }
        ptr = ptr->next;
    }
    // it is for last pointer
    counter++;
    if (ptr->data == se)
    {
        printf("\n Element found at %d ", counter);
        return;
    }

    printf("\n element is not found ");
}
void display()
{
    if (isEmpty())
    {
        printf("\n UNDERFLOW");
        return;
    }
    struct node *ptr;
    ptr = head;
    printf("Element are :");
    printf(" %d", ptr->data);
    while (ptr->next != head)
    {
        ptr = ptr->next;
        printf(" %d", ptr->data);
    }
    printf("\n %d", size);
}
void beginsert()
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\n Linked list is full ");
        return;
    }
    int value;
    printf("\n Enter the data :");
    scanf("%d", &value);
    ptr->data = value;
    if (head == NULL)
    {
        head = ptr;
        ptr->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = head;
        head = ptr;
    }
    printf("\n Element add :%d", head->data);
    size++;
}