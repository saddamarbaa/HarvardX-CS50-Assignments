/**
    [PROGRAM] :  Substitution(Substitution Cipher)
    [AUTHOR]  :  Saddam Arbaa
    [Email]   :  <saddamarbaas@gmail.com>

    CS50X 2020 Problem Set 2 Substitution Cipher Implementation
    
    substitution cipher is a program that “encrypt” a message by
    replacing every letter with another letter from the 26 charterers key.
    key should contain alphabetic charterers only and also must not
    contain repeated  charterers .
    
    Link to the Week 2 lecture
    CS50 2019 - Lecture 2 - Arrays
    https://youtu.be/8PrOp9t0PyQ

    Link to the  Problem Set
    https://cs50.harvard.edu/x/2020/psets/2/substitution/#:~:text=substitution%20cipher */

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>    /* include cs50.h  Header file */
#include <string.h>  /* include string.h Header file */
#include <ctype.h>  /* include ctype.h Header file */

/**  Global constant variable declarations */

const int UPER_CASE_INDEX = 65;     /* Upper case letter 'A' ASCII index */

const int LOWER_CASE_INDEX = 97;    /* lower case letter 'a' ASCII index */

const int NUMBER_OF_ALPHABET_INDEX = 26;  /* number of English alphabet letters */

int main(int argc, string argv[]) /* the river Code */
{
    // get key from user throw command line arguments
    string user_Key = argv[1];

    // checking if user enter only single arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key \n");
        return 1; // signal to operating system that program not successes
    }
    int key_Length = strlen(user_Key);  //  the length of given

    //checking if length of the key is 26 digits
    if (key_Length != NUMBER_OF_ALPHABET_INDEX)
    {
        printf("Key must contain 26 characters.\n");
        return 1; // signal to operating system that program not successes
    }

    // check for non alphabetical character in the key
    // as the key  must only contain alphabetic characters
    for (int i = 0; i < key_Length; i++)
    {
        if (!isalpha(user_Key[i])) // call isalpha() function
        {
            printf("key must only contain alphabetic characters \n");
            return 1; // signal to operating system that program not successes
        }
    }

    // check for repeated  characters
    for (int i = 0; i < key_Length; i++)
    {
        for (int j = i + 1; j < key_Length; j++)
        {
            if (user_Key[i] == user_Key[j])
            {
                printf("key must not contain repeated  characters . \n");
                return 1; // signal to operating system that program not successes
            }
        }
    }

    // get the plaintext from user
    string plaintext = get_string("plaintext: "); // ueser plaintext

    /** encrypting process start from here */

    printf("ciphertext: ");

    /* Iterate throw user plaintext */
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // if char is lowercase
        if (islower(plaintext[i]))  //call islower() function
        {
            int inedxlow = plaintext[i] - LOWER_CASE_INDEX;  // Substituted with char in the same i index from key
            printf("%c", tolower(user_Key[inedxlow]));
        }
        // if char is uppercase
        else if (isupper(plaintext[i]))
        {
            int  indxup = plaintext[i] - UPER_CASE_INDEX;
            printf("%c", toupper(user_Key[indxup])); //Substituted with char in the same i index from key
        }
        else // else cases
        {
            //print as is it without change
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");

    return 0;// signal to operating system everything works fine

} /** End of main function */
