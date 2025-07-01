#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    // Iterate over each candidate
    for (int i = 0; i < 10; i++)
    {
        // Check if candidate's name matches given name
        if (strcmp(candidates[i].name, name) == 0)
        {
            // If yes, increment candidate's votes and return true
            candidates[i].votes += 1;
            return true;
        }
    }
    // If no match, return false
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    // New variables to store information on winner and max votes
    string winners[2];
    int winnerIndex = 0;
    int maxVotes = 0;
    // Loop over all candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // Find the maximum number of votes
        if (candidates[i].votes > maxVotes)
        {
            // If true, update new variable
            maxVotes = candidates[i].votes;
            winnerIndex = 0;
        }
        // Find the candidate that matches the maximum number of votes
        if (maxVotes == candidates[i].votes)
        {
            // then update variables with the name of the person with max votes and up index by 1
            winners[winnerIndex] = candidates[i].name;
            winnerIndex += 1;
        }
    }
    // Print the candidate (or candidates) with maximum votes
    if (winnerIndex > 1)
    {
        for (int i = 0; i < winnerIndex; i++)
        {
            printf("%s\n", winners[i]);
        }
    }
    else
    {
        printf("%s\n", winners[0]);
    }
    return;
}
