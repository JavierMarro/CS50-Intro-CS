#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1);
    // t stores the address of a new chunk of memory that is big enough to store however many chars are inputted in var s (+1 for the nul character /0 end of string) Using malloc we are avoiding the issue created in char *t = s in which t just ended up pointing at the address of s (and therefore using the data in s), rather creating a new address where to store the copied data

    if (t == NULL) // NULL means 0, meaning if malloc cannot assign memory because of hardware's
                   // limitation, then we need to stop and exit
    {
        printf("Apologies, no available memory");
        return 1;
    }
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i]; // copying all char from s to t
    }

    // the loop from lines 20 to 23 can be 'refactored' or automised using an in library function:
    // strcopy(t, s) strcopy takes two arguments, first one destination, then source

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t); // this is the second part to malloc, freeing the space for the data copied
}
