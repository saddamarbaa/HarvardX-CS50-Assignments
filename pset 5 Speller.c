// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  /* include string.h Header file */
#include <cs50.h>    /* include cs50.h  Header file */

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

/*
head pointer point to the first element
of Linked List at an index of Hash Table
(head node,also called first node) */
node* Head = NULL;

/* Global define of Hash Table maximum
  capacity and initialization to 997(997 is prime number) */
#define HASHTABLE_SIZE  997

/* Global array(hash table) declaration*/
node *table[HASHTABLE_SIZE];

/* Global declaration of Hash Table size and initialization
  to zero (number of elements present in Hash Table */
int word_count = 0;

// function to create hash table and initialize to zero
void initialize_table(void);


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
// Hashes the word (hash function posted on reddit by delipity)
// so all the credit to  delipity
unsigned int hash(const char *word)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % HASHTABLE_SIZE;
    
} /** END of hash() */


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // first step Open dictionary file
    FILE *file = fopen(dictionary, "r");

    // throw error if the file can't be open for any reason
    if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        unload();
        return false; // signal that program not successes
    }

    // creating char array to store data of file
    char word[LENGTH + 1];

    /*
    second step(scan dictionary word by word)
    iterate over the given dictionary file and read one
    word each time until reach the end of file*/
    while (fscanf(file, "%s", word) != EOF)
    {
        // next step is to create new node
        // allocate memory dynamically for node using malloc C function
        node* new_node = (node*) malloc(sizeof(node));
        if(new_node == NULL) /* Error handling */
        {
            printf("Error in allocating memory\n");
            unload();
            return false; // signal that program not successes
        }

        /* add information to node */
        strcpy(new_node -> word, word); // Copies word into node if malloc succeeds
        new_node -> next = NULL;        // next is NULL for now

        /* next step is to insert the node into hash table */

        // get the hash code
	    unsigned int index = hash(new_node -> word); // call hash() function

        // Initializes head to point to given index by hashFunction
        Head = table[index];

	    /** Handle the corner cases */

	    if(Head == NULL) /* check if list is empty then this node is the first node */
        {
            /** link changes */
            table[index] = new_node; // insert first node in list
            word_count++;              /* increment hash size by one*/
        }
        else
        {
            /* if already some element are in the linked list
               let add the new node at the Beginning of the list*/

            /** link changes */
            new_node -> next = Head;   // right side connection first
            Head = new_node;            // left side connection second
            word_count++;              /* increment hash size by one */
        }
        printf("Key :(%s) been inserted \n",new_node -> word); // inform user the word is been inserted
    }

    fclose(file);  // close files
    return true; // signal that program  successes

} /** End of load() */



// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;  // return number of the words in hash table

} /** End of size() */

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}


/** function To  initialize the Array(hash tables) */

void initialize_table()
{
    /* loop and initialize hash table Head and tail to NULL */
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        table[i] = NULL;
    }

}  /** End of initialize_Array */

