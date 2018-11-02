#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int val;
    struct node *next;
    struct node *prev;    
};
typedef struct node n;
 
n* create_node(int);
void add_node();
void insert_at_end();
void display_from_beg();
void display_in_rev();
 
n *new, *ptr, *prev;
n *first = NULL, *last = NULL;
int number = 0;
 
int main()
{
    int ch;
 
    printf("\n linked list\n");
    printf("1.insert\n 2.display");
 
    while (1)
    {
 
        printf("\n enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {

        case 1 :
            insert_at_end();
            break;
        case 2 :
            display_from_beg();
            break;
        default:
            printf("\ninvalid choice");
			return 0;
			                
        }
    }
}
n* create_node(int info)
{
    number++;
    new = (n *)malloc(sizeof(n));
    new->val = info;
    new->next = NULL;
    new->prev = NULL;
    return new;
}
void add_node()
{
 
    int info;
 
    printf("\nenter the value you would like to add:");
    scanf("%d", &info);
    new = create_node(info);
 
    if (first == last && first == NULL)
    {
 
        first = last = new;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
    }
    else
    {
        last->next = new;
        new->prev = last;
        last = new;
        last->next = first;
        first->prev = last;
    }
}

void insert_at_end()
{
 
    char info;    
 
    printf("\nenter the char:");
    scanf("%d", &info);
    new = create_node(info);
 
    if (first == last && first == NULL)
    {
        printf("\ninitially the list is empty and now new node is inserted but at first");
        first = last = new;
        first->next = last->next = NULL;    
        first->prev = last->prev = NULL;
    }
    else
    {
        last->next = new;
        new->prev = last;
        last = new;
        first->prev = last;
        last->next = first;
    }
}
  
  

void display_from_beg()
{
    int i;
    if (first == last && first == NULL)
        printf("\nlist is empty no elemnts to print");
    else
    {    
        printf("\n%d number of nodes are there", number);
        for (ptr = first, i = 0;i < number;i++,ptr = ptr->next)
            printf("\n %d", ptr->val);
    }
}

