/**
    [PROGRAM] :  Readability (Coleman-Liau formula)
    [AUTHOR]  :  Saddam Arbaa
    [Email]   :  <saddamarbaas@gmail.com>
   
    CS50X 2020 Problem Set 2 Readability Implementation
    (a program that computes the approximate grade level needed to comprehend some text)
    
    Link to the Week 2 lecture
    CS50 2019 - Lecture 2 - Arrays
    https://youtu.be/8PrOp9t0PyQ

    Link to the  Problem Set
    https://cs50.harvard.edu/x/2020/psets/2/readability/#:~:text=Readability */

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>    /* include cs50.h  Header file */
#include <string.h>  /* include string.h Header file */
#include <ctype.h>  /* include ctype.h Header file */
#include <math.h>  /* include math.h  Header file */

// function to count the number of word in text 
int count_Word(string, int);

// function to count the number of letters in text
int count_letters(string, int);

// function to count the number of sentences in text
int sentences_Count(string, int);

int main(int argc, char *argv[]) /* the river Code */
{
    /* variables declarations */
    int letters, words, sentences, length;
    
    /*
    letters for letters count 
    words for word count
    sentences for Sentences count */
    
    /* initializ all variables */
    letters = words = sentences = length = 0;
    
    // Getting User Input string
    string text = get_string("enter some text: ");
    // get the text length
    length  = strlen(text); // call strlrn function for help 

    /* calling letter count function */
    letters = count_letters(text, length);

    // calling words count function
    words = count_Word(text, length);

    // calling sentences count function
    sentences = sentences_Count(text, length);

    /*Computes the Coleman-Liau index formula below */
    // index = 0.0588 * L - 0.296 * S - 15.8
    
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;
    float indexx = 0.0588 * L - 0.296 * S - 15.8;
    int index = round(indexx);
    
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
    
    return 0;// signal to operating system everything works fine

} /** End of main function */


/** count_letters Function takes one argument(string text) 
   and count number of letters in the given text
   lastly return number of letters  */
   
int count_letters(string  text, int length)
{
    int letters = 0; /* local variable declarations */
    
    for (int i = 0; i < length; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;  // increment letters by one
        }
    }
    return letters;  // return the number of letters 
    
} /** END of count_letters() */


/** count_word Function takes one argument(string text) 
   and count number of word in the given text
   lastly return number of words  */
   
int count_Word(string  text, int length)
{
    int words = 1; /* local variable */
    
    for (int i = 0; i < length; i++)
    {
        // to check  If the current character text[i]) is white space */
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t')
        {
            words++; // increment word by one
        }
    }
    return words;  // return the number of words 
    
} /** End of count_Word() */


/** sentences_Count Function takes one argument(string text) 
   and count number of sentences in the given text
   lastly return number of sentences  */
   
int sentences_Count(string  text, int length)
{
    int sentences = 0; /* local variable */
    for (int i = 0; i < length; i++)
    {
        if ((text[i] == '.' || text[i] == '!') || (text[i] == '?'))
        {
            sentences++; // increment sentences by one
        }
    }
    return sentences; // return the number of sentences
    
} /** END of sentences_Count() */
