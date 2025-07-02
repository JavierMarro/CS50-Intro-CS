#include <cs50.h>
#include <stdio.h>

// This initial implementation is dangerous in line 9 due to not know how much memory is available for that string
// It doesn't know where the string is going to end.
// Therefore it is better to carry on using the library cs50 and get_string
int main(void)
{
    char *s;
    printf("string: ");
    scanf("%s", s);
    printf("string: %s\n", s);
}
