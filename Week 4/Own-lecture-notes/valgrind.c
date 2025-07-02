#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int)); //malloc is allocating space for 3 integers
    x[1] = 72;
    x[2] = 73;
    x[3] = 33;
}

// 2 BUGS in this code. Not starting with x[0] and not using free(x) at the end
// running command valgrind and then the name of file will provide feedback related to memory related mistakes in my code
