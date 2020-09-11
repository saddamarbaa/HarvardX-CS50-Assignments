/**
    [PROGRAM] :  Plurality(plurality election )
    [AUTHOR]  :  Saddam Arbaa
    [Email]   :  <saddamarbaas@gmail.com>

    CS50X 2020 Problem Set 3 Plurality Implementation

    Plurality is a program that Simulate a plurality election.

    Link to the Week 3 lecture
    CS50 2019 - Lecture 3 - Algorithms
    https://youtu.be/fykrlqbV9wM

    Link to the  Problem Set
    https://cs50.harvard.edu/x/2020/psets/3/plurality/#:~:text=a%20program%20that%20runs%20a%20plurality%20election*/

#include <stdio.h>
#include <cs50.h>    /* include cs50.h  Header file */
#include <string.h>  /* include string.h Header file */

// maximum number of candidates in the election
#define MAX 9

/* Struct to represent Candidates for storing their informations
   each Candidates have name and vote count */
typedef struct
{
    string name; /* name filed */
    int votes;   /* votes filed */
} candidate;

/* Array of candidates Global declaration */
candidate candidates[MAX];

/* Number of candidates Global declaration */
int candidate_count;

/* blow are the Functions prototypes */

/* function to Update vote */
bool vote(string name);

/* function to Print the winner(or winners) of the election */
void print_winner(void);

int main(int argc, string argv[])    /* the river Code */
{
    if (argc < 2) // Check for invalid argc
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1; // signal to operating system that program not successes
    }
    candidate_count = argc - 1;  // Number of the candidates

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2; // signal to operating system that program not successes
    }
    /*
    iterate over the array of candidate
    and initialize their votes to zero for now */
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // number of voters
    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        // get their Candidate name
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name)) // call vote function
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner(); // call print_winner() function

    return 0;// signal to operating system everything works fine

} /** End of main function */

/**
 function to Update vote totals given a new vote
 iterate over the array of candidate and search
 for the given candidate name if the given candidate
 name is on the list then update it number vote by one
 and return true else mean the name is not on the list return false */

bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            // update votes count by adding 1
            candidates[i].votes = candidates[i].votes + 1; // same as candidates[i].votes++
            return true;
        }
    }

    /* if reach this line is mean that the name
       is not found  just return false */
    return false;

} /** End of vote() */


/** function to Print the winner(or winners) of the election */

void print_winner(void)
{
    int i, j, max_Vote;  /* variable declarations */

    max_Vote = 0;   /* initialize max vote to zero */

    /* max_Vote for counting number of highest vote candidate */

    // Finding the highest number of votes
    for (i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > Max_Vote)
        {
            max_Vote = candidates[i].votes ;
        }
    }

    /*
    Printing out names of all the winner who have highest
    number of votes. if two candidate have same number of vote
    my program print out two of them as winner */

    for (j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes == Max_Vote)
        {
            printf("%s\n", candidates[j].name);
        }
    }

} /** End of print_winner() */

