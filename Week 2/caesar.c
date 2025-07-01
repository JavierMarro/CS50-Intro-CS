#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2) // Checks the number of arguments, if not print message and return 1
    {
        printf("Usage: ./ceasar key\n");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]); // Converts the argument to an integer

        printf("%i\n", key);

        string text = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int i = 0, len = strlen(text); i < len;
             i++) // Loops through each letter from user's input
        {
            int letter = text[i];
            if (letter >= 'a' && letter <= 'z')
            {
                int cipher = letter - 'a'; // Finds position of letter in alphabet
                int ciphertext = cipher + key; // Adds key to position and wraps around using modulo 26
                int ciphermod = ciphertext % 26;
                letter = 'a' + ciphermod; // Updates the letter
            }
            else if (letter >= 'A' &&
                     letter <= 'Z') // Does the same as above but with capital letters
            {
                int cipher = letter - 'A';
                int ciphertext = cipher + key;
                int ciphermod = ciphertext % 26;
                letter = 'A' + ciphermod;
            }
            printf("%c", letter);
        }
        printf("\n");
    }
    return 0; // Exitting successfully
}
