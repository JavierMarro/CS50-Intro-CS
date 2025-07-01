// imports below are helper functions from Harvard's cS50 which allowed using string and bool
// #include <cs50.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

void checkSum(long numCard, int *totalH, int *totalT);

int main(void)
{
    string card;    // asking for the card number as a string
    int cardLength; // checking that the card length complies with card providers available
    long numCard;   // converting card string into a number to be able to manipulate it
    int totalH = 0; // sum of every other digit
    int totalT = 0; // sum of the rest of digits
    int total = 0;  // sum of total

    do
    {
        card = get_string("Number: ");
        cardLength = strlen(card);
        numCard = atol(card);
    }
    while (cardLength < 13 || cardLength > 16);

    checkSum(numCard, &totalH, &totalT);
    total = totalH + totalT;

    if (total % 10 == 0)
    {
        if (cardLength == 15 && card[0] == '3' && (card[1] == '4' || card[1] == '7'))
        {
            printf("AMEX\n");
        }
        else if (cardLength == 16 && card[0] == '5' && (card[1] == '1' || card[1] == '2' || card[1] == '3' || card[1] == '4' || card[1] == '5'))
        {
            printf("MASTERCARD\n");
        }
        else if ((cardLength == 13 || cardLength == 16) && card[0] == '4')
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

void checkSum(long numCard, int *totalH, int *totalT)
{
    int digit;
    bool isEven = false; // tracks if it's every other digit

    while (numCard != 0)
    {
        digit = numCard % 10; // checks last digit
        if (isEven)
        {
            int digitDoubled = digit * 2;
            *totalH += (digitDoubled > 9) ? (digitDoubled - 9) : digitDoubled;
        }
        else
        {
            *totalT += digit; // adds non multiplied digits
        }
        numCard /= 10;    // removes last digit
        isEven = !isEven; // bang operator toggles between every other digit
    }
}
