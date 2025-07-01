#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int checkLetters(string);
int checkWords(string);
int checkSentences(string);
float colemanLiau(float *avLetters, float *avSentences);

float letters;
float words;
float sentences;

int main(void)
{
    string text = get_string("Text: "); // Get user's text
    int i = strlen(text);
    checkLetters(text);
    checkWords(text);
    checkSentences(text);
    float avLetters = 100 * (letters / (float) words);
    float avSentences = 100 * (sentences / (float) words);
    float average = colemanLiau(&avLetters, &avSentences); // Get ultimate result

    if (average <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if ((int) average >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) average + 1);
    }
}

int checkLetters(string text)
{
    letters = 0; // Utilising global variable and increasing count
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        char letter = text[i];
        if (isalpha(letter) != 0)
        {
            letters++;
        }
    }
    return letters;
}

int checkWords(string text)
{
    words = 1; // Utilising global variable, starting it at 1 due to word after last space,
               // increasing count
    for (int i = 0, w = strlen(text); i < w; i++)
    {
        char space = text[i];
        if (isspace(space))
        {
            words++;
        }
    }
    return words;
}

int checkSentences(string text)
{
    sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char punctuation = text[i]; // If iteration encounters ., !, or ?, inscrease count
        if (punctuation == '.' || punctuation == '!' || punctuation == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

float colemanLiau(float *avLetters, float *avSentences)
{
    float index = 0.0588 * (*avLetters) - 0.296 * (*avSentences) - 15.8;
    return index;
}
