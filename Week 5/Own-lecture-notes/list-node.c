#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int number;
    struct node *next;
} node;
// This is a LIFO example
int main(void)
{
    //creating a linked list (allocating a joint sequence of nodes that store info, in this case numbers)
    // 1st pointer to the beginning (or head) of list initialised to NULL because otherwise the variable could contain garbage values
    // list is just the address of a node
    node *list = NULL;
    // 2nd iterate to assign the place to each element of the linked list
    for (int i = 0; i < 3; i++)
    {
        // create a pointer which is set to whatever is the size of a node
        // n is just the address of a node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        //n takes you to the chunk of memory just created that contains a number. The line below can be refactored tho
        // (*n).number = get_int("Number: ");
        n->number = get_int("Number: ");
        //to the next container which should be safe and hold nothing as of yet: (*n).next = NULL;
        // the above can also be refactored to n->next = NULL; however, for the loop to be effective, this needs changing to point to list
        n->next = list;
        list = n;
        // what setting list to n does is linking each n (or node) to all number's locations
    }
    // In order to print the sequence of numbers created in the above loop we can set a variable 'ptr' that points to the original list (or original pointer for the address)
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next; // this is done for ptr to keep pointing arrows at the following node
    }
}
