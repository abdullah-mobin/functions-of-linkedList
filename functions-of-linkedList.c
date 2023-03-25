#include <stdio.h>
#include <stdlib.h>

void creatlist(int size);
void printList();
int count();

void insertB();
void insertE();
void insertM(int x);

void search(int item);
void search_and_add_before(int item);

void delete_in_strat();
void delete_in_middle(int x);
void delete_in_last();

struct NODE
{
    int data;
    struct NODE *next;
};
typedef struct NODE node;
node *head;

int main()
{
    int listsize, insert_position, delet_position, search_item;
    printf("Give list size :");
    scanf("%d", &listsize);

    printf("List is creating ---\n");
    creatlist(listsize);

    printf("First Add\n");
    insertB();
    printf("input mid pos\n");
    scanf("%d", &insert_position);
    insertM(insert_position);
    printf("last add\n");
    insertE();

    printf("Printing liist ---\n");
    printList();

    printf("enter searching item : ");
    scanf("%d", &search_item);
    search(search_item);
    printList();

    search_and_add_before(search_item);
    printList();

    printf("Number of node = %d\n", count());

    delete_in_strat();
    printf("DEL position : ");
    scanf("%d", &delet_position);
    delete_in_middle(delet_position);
    delete_in_last();

    printf("Printing list --- after delete\n");
    printList();

    return 0;
}



void creatlist(int size)
{
    head = (node *)malloc(sizeof(node));
    printf("Input Data For 1 : ");
    scanf("%d", &head->data);
    head->next = NULL;
    node *temp;
    temp = head;
    for (int i = 2; i <= size; i++)
    {
        node *newNode = (node *)malloc(sizeof(node));
        printf("Input Data For %d : ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
}



void printList()
{
    node *temp;
    temp = head;
    int i = 1;
    while (temp != NULL)
    {
        printf("DATA %d : %d\n", i++, temp->data);
        temp = temp->next;
    }
}



void insertB() /* @ beginning */
{
    node *newNode = (node *)malloc(sizeof(node));
    printf("Input Data For 1st node : ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}



void insertE() /* @ end */
{
    node *newNode = (node *)malloc(sizeof(node));
    printf("Input Data For last node: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    node *temp = (node *)malloc(sizeof(node));
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}



void insertM(int x) /* @ middle position */
{
    int pos = x;
    node *newNode = (node *)malloc(sizeof(node));
    printf("Input Data For %d node: ", pos);
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    node *p, *q;
    p = head;
    q = head->next;
    for (int i = 2; i < pos; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = newNode;
    newNode->next = q;
}



void search(int item) /* Search a random data and check if the item present or not */
{
    node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == item)
        {
            printf("Item found\n");
            break;
        }
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Item not found");
    }
}




void search_and_add_before(int item) /* Search a random data and add data before the data */
{

    int counter = 0;
    node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == item)
        {
            break;
        }
        else
        {
            ++counter;
            temp = temp->next;
        }
    }
    if (temp->next == NULL)
    {
        printf("Item not found");
    }
    else
    {
        node *newNode = (node *)malloc(sizeof(node));
        printf("enter for %d", counter + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        node *p, *q;
        p = head;
        q = head->next;
        for (int i = 2; i <= counter; i++)
        {
            p = p->next;
            q = q->next;
        }
        p->next = newNode;
        newNode->next = q;
    }
}




int count()
{
    node *temp;
    temp = head;
    int i = 0;
    while (temp != NULL)
    {
        ++i;
        temp = temp->next;
    }
    return i;
}



void delete_in_strat()
{
    node *temp = (node *)malloc(sizeof(node));
    temp = head;
    head = head->next;
    free(temp);
}



void delete_in_middle(int x)
{
    node *p, *q;
    p = head;
    q = head->next;
    for (int i = 2; i < x; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
}



void delete_in_last()
{
    node *p, *q;
    p = head;
    q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
}
