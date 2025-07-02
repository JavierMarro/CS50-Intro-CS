// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;
// size function, going for approach 1, count each word
int numWords = 0;
// TODO: Choose number of buckets in hash table (26, one for each letter of the alphabet) // Seems
// good to me
const unsigned int N = 26;

// Hash table
node *table[N];
// node *n = malloc(sizeof(node));
// strcpy(n->word, "Hello");
// n->NEXT = NULL;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // 1 harsh word = hars value
    int hash_v = hash(word);
    // 2 access linked list index hash table
    node *cursor = table[hash_v];
    // 3 traverse linked list and loop up word
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function // Seems good to me
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // 1 Open file and check if NULL value
    FILE *dictionary_file = fopen(dictionary, "r");
    if (dictionary_file == NULL)
    {
        printf("There was no available space for file\n");
        return false;
    }
    // 2 Read strings from file AND return EOF in end of file
    char w[45]; // largest word
    while (fscanf(dictionary_file, "%s", w) != EOF)
    {
        // 3 create node in each iteration
        node *newWord = malloc(sizeof(node));
        // 4 Hash value
        int hash_v = hash(w);
        // From code provided by BRYAN
        strcpy(newWord->word, w);
        newWord->next = table[hash_v];
        table[hash_v] = newWord;
        numWords++;
    }
    fclose(dictionary_file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return numWords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // as in lecture, we need a third 'vase' or container, in this case the container will point at
    // the data to delete whilst cursor points at next to keep track
    for (int i = 0; i < N; i++)
    {
        node *tmp = table[i];
        node *cursor = table[i];
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
