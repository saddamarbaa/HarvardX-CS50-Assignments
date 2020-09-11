/**
    [PROGRAM] :  Runoff(an instant Runoff Election)
    [AUTHOR]  :  Saddam Arbaa
    [Email]   :  <saddamarbaas@gmail.com>
    CS50X 2020 Problem Set 3 Runoff Implementation

    Runoff is a program that Simulate Runoff Election.
    Link to the Week 3 lecture
    CS50 2019 - Lecture 3 - Algorithms
    https://youtu.be/fykrlqbV9wM
    Link to the  Problem Set
    https://cs50.harvard.edu/x/2020/psets/3/runoff/#:~:text=Runoff */

#include <stdio.h>
#include <string.h>  /* include string.h Header file */
#include <cs50.h>    /* include cs50.h  Header file */

// maximum number of voters in the election.
#define MAX_VOTERS 100

// maximum number of candidates in the election
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
//  (preferences array Global declaration */)
int preferences[MAX_VOTERS][MAX_CANDIDATES];

/* Struct to represent Candidates for storing their informations
   Candidates have name, vote count, eliminated status */
typedef struct
{
    string name;     /* name filed */
    int votes;        /* votes */
    bool eliminated;  /* eliminated status */
}
candidate;

/* Array of candidates Global declaration */
candidate candidates[MAX_CANDIDATES];

/* Number of voters Global declaration */
int voter_count;

/* Number of candidates Global declaration */
int candidate_count;

/* blow are the Functions prototypes */

// function to Record preference if vote is valid
bool vote(int voter, int rank, string name);

// function to Tabulate(Update)votes
// for non-eliminated candidates
void tabulate(void);

// function to Print the winner
bool print_winner(void);

// function to Find the candidate with the minimum
// number of votes fom non-eliminated candidates
int find_min(void);

// Function to Find if the election is tied  or not
bool is_tie(int min);

/* function to Eliminate the candidate
   who have minimum number of votes */
void eliminate(int min);

int main(int argc, string argv[]) /* the river Code */
{
    if (argc < 2) // Check for invalid argc
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1; // signal to operating system that program not successes
    }

    candidate_count = argc - 1; // Number of the candidates

    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2; // signal to operating system that program not successes
    }
    /*
    iterate over the array of candidate and initialize
    their votes to zero and candidates[i].eliminated to False*/
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // number of voters
    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3; // signal to operating system that program not successes
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)  // Loop over all voters
    {
        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))  // call vote function
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break; // if we have winner we are done
        }
        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }

    return 0;// signal to operating system everything works fine

} /** End of main function */


/** function to Record preference if vote is valid */

bool vote(int voter, int rank, string name)
{
    // iterate throw the candidate array
    for (int i = 0; i < candidate_count; i++)
    {
        // check first if the given name name match
        // one of the candidates name
        if (strcmp(name, candidates[i].name) == 0)
        {
            // if the name match update preference Array with i
            // preferences[voter][rank] = i
            preferences[voter][rank] = i;
            return true;
        }
    }
    /* if reach this line is mean that the name
       is not found just return false */
    return false;

} /** End of vote() */


/** function to Tabulate(Update) votes for non-eliminated candidates */

void tabulate(void)
{
    // loop over voters
    for (int i = 0; i < voter_count; i++)
    {
        // i =  voter  j = rank
        int j = 0;

        /*
        if the candidates is already been eliminated then update it
        vote count to his second preferences candidate for that
        increment j++ by one so we can reach the second preferences
        we can also use condition blow
        while (candidates[preferences[i][j]].eliminated == true)
        j++ */
        if (candidates[preferences[i][j]].eliminated == true)
        {
          j++; // j is now at second  preferences index
        }

        // if the candidates is not been eliminated update vote count
        if (candidates[preferences[i][j]].eliminated == false)
        {
            candidates[ preferences[i][j]].votes++;
        }
    }

} /** End of tabulate() */


/** function to Print the winner of the election, if there is one */

bool print_winner(void)
{
    // local variable declarations
    int i, majority;

    /*
    iterate throw all the candidate to check each one
    if the candidate have have majority 50% + 1  print
    his name as winner and return true else return false */
    for (i = 0; i < candidate_count; i++)
    {
        majority = voter_count / 2; // calculate the majority

        if (candidates[i].votes > maximim)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    /*
    if reach this line is mean that there is no candidate
    have majority vote so far just return false */
    return false;

} /** End of vote() */


/** function to Return the minimum number of votes
    any remaining candidate has */

int find_min(void)
{
    // local variable declarations
    int i, min_votes;

    /* assume candidate at first index
     has the minimum vote so far */
    min_votes = candidates[0].votes;

    /*
    iterate throw all the candidate to check each one
    if the candidate still on the game and have the
    lowest vote number return the lowest */

    for (i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes < min_votes)
        {
            min_votes = candidates[i].votes; // we have new min vote
        }
    }
    return min_votes; // return the min_votes

} /** End of find_min() */


/**
 Function Return true if the election is tied
 between all candidates, false otherwise */

bool is_tie(int min)
{
    /*
    iterate throw all the candidate to check each
    one if the candidate is still on game or been
    eliminated if is still on the game then check
    if [candidate[i].vote == min if so its tie return true
    else return false */
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes == min)
        {
            return true;
        }
    }
    return false;

} /** END of  is_tie() */


/** function to Eliminate the candidate(or candidates)
    who have minimum number of votes. */

void eliminate(int min)
{
    /*
    iterate throw all the candidate to check each one
    if the candidate has smallest number of vote and still
    on the game then be eliminated */
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min && candidates[i].eliminated == false)
        {
            candidates[i].eliminated = true;
        }
    }

}   /**  END of eliminate() */
