#include <stdio.h>

void swap (int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

// Unfortunately the function below will not swap x and y values as they're outside of the function's scope (or exectuion memory)
// void swap(int a, int b)
// {
//     int tmp = a;
//     a = b;
//     b = tmp;
// }

// For the function to be usable in the execution memory of main we need to pass the data by reference (pointing at the address)
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
