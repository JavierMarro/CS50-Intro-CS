#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int ValuePairs[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int wordTotal(string word);

int main(void)
{
    string playerOne = get_string("Player 1: ");
    string playerTwo = get_string("Player 2: ");

    int player1Score = wordTotal(playerOne);
    int player2Score = wordTotal(playerTwo);

    if (player1Score > player2Score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player2Score > player1Score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int wordTotal(string word)
{
    int score = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            score += ValuePairs[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += ValuePairs[word[i] - 'a'];
        }
    }
    return score;
}
