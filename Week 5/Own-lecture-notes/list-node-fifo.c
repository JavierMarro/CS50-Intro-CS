#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int number;
    struct node *next;
} node;
// This is a FIFO example
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
            //this exit line could happen any time, either beginning of value allocation or halfway through
            // therefore we'd need to implement sth that frees any memory already malloc'd
            return 1;
        }
        //n takes you to the chunk of memory just created that contains a number. The line below can be refactored tho
        // (*n).number = get_int("Number: ");
        n->number = get_int("Number: ");

        //NEW CODE TO IMPLEMENT FIFO (appending nodes to the list)
        //to the next container which should be safe and hold nothing as of yet: (*n).next = NULL;
        n->next = NULL;
        // If list is empty
        if ( list == NULL)
        {
            list = n; // then it sets equal to the address of the new node
        }
        // If list has numbers already, it should append
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next) //sets a new variable ptr to the start of the list, then that keeps happening for as long as the pointer itself isn't NULL
            {
                if (ptr->next == NULL) // If I'm pointint at a node that next field is NULL, this means end of the list
                {
                    ptr->next = n; // I want to change the NULL value to the address of the new node and break
                    break;
                }
            }
        }
    }
    // In order to print the sequence of numbers created in the above loop we can set a variable 'ptr' that points to the original list (or original pointer for the address)
        // node *ptr = list;
        // while (ptr != NULL)
        // {
        //     printf("%i\n", ptr->number);
        //     ptr = ptr->next; // this is done for ptr to keep pointing arrows at the following node
        // }
        //the above while loop can be also done with a for loop:
        for (node *ptr = list; ptr != NULL; ptr = ptr->next)
        {
            printf("%i\n", ptr->number);
        }

        // free the linked list
        node *ptr = list;
        while (ptr!= NULL)
        {
            node *next = ptr->next;
            free(ptr);
            ptr = next;
        }
        return 0;
}
