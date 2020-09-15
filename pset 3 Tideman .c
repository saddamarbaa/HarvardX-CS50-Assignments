#include <stdio.h>
#include <string.h>  /* include string.h Header file */
#include <cs50.h>    /* include cs50.h  Header file */

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool is_Cycles(int,int);

int main(int argc, string argv[]) /* the river Code */
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks)) // call vote() function
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
        record_preferences(ranks); // record_preferences() function

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();

    return 0;// signal to operating system everything works fine

} /** End of main function */

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // iterate throw the candidate array
    for (int i = 0; i < candidate_count; i++)
    {
       // first check if the given name match
        // one of the candidates name
        if (strcmp(name, candidates[i]) == 0)
        {
            // if the name match update given ranks Array with
            // ranks[rank] = i
            ranks[rank] = i;
            return true; // we are done
        }
    }
    /*
    if reach this line is mean that the name
    is not found just return false */
    return false;

} /** End of vote() */


// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{

    // iterate throw the candidate array
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++; // Update preferences
        }
    }

} /** End of record_preferences() */


// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // iterate throw the candidate array
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
           if(preferences[i][j] > preferences[j][i])
           {
               /* add pairs of candidates */
               pairs[pair_count].winner = i;
               pairs[pair_count].loser = j;
               pair_count++; /* increment pair count by one */
           }
           else if(preferences[i][j] < preferences[j][i])
           {
               /* add pairs of candidates */
               pairs[pair_count].winner = j;
               pairs[pair_count].loser = i;
               pair_count++; /* increment pair count by one */
           }
           /* in else cases mean
           (preferences[i][j] == preferences[j][i])
            in that case do nothing */
        }
    }
}/** End of add_pairs () */


// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int i, j;    // i,j are counters

    // run two  loops : one for walking through the array
    // and the other for comparison
    for (i = 0; i < pair_count - 1; i++)
    {
        // inner loop for comparison
        for (j = i + 1; j < pair_count; j++)
        {
            if(preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[j].winner][pairs[j].loser])
            {
                // if so swap them
                int temp_winner = pairs[j].winner;
                int temp_loser = pairs[j].loser;
                pairs[j].winner = pairs[i].winner;
                pairs[j].loser = pairs[i].loser;
                pairs[i].winner = temp_winner;
                pairs[i].loser = temp_loser;
               // swap is done
            }
        }
    }

} /** End of sort_pairs () */

bool is_Cycles(int a, int b )
{
    if(locked[a][b] == true)
    {
        /* base case */
        return true;
    }
     for (int i = 0; i < candidate_count; i++)
       {
           if(locked[i][a] == true)
           { /* Recursive case */
               return is_Cycles(i ,b);
           }

       }




   /* reach this line return false */
   return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        if(!is_Cycles(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][ pairs[i].loser] = true;
        }

    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}

