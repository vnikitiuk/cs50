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
}
candidate;

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
            i--;
        }
    }

    // Display winner of election
    print_winner();
}

// <my-code>

// Update vote totals given a new vote
bool vote(string name)
{
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    // Candidates with the largest amount of votes
    candidate winners[MAX];
    int winner_index = 0;

    // To track the largest number of votes
    int more_votes = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes >= more_votes)
        {
            more_votes = candidates[i].votes;
            winners[winner_index] = candidates[i];
            winner_index++;
        }
    }

    // Printing the winner
    printf("%s\n", winners[winner_index - 1].name);

    // Checking if there are more winners
    for (int i = winner_index - 1; i > 0; i--)
    {
        if (winners[i].votes == winners[i - 1].votes)
        {
            printf("%s\n", winners[i - 1].name);
        }
        else
        {
            return;
        }
    }
    return;
}

// <\my-code>