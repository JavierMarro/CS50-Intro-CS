// imports below are helper functions from Harvard's cS50
// #include <cs50.h>
// #include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
        for (int height = 1; height <= n; height++)
        {
            for (int i = 0; i < n - height; i++)
            {
                printf(" ");
            }
            for (int j = 0; j < height; j++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
    while (n < 1 || n > 8);
}
