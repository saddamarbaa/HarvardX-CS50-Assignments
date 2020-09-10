/**
    [PROGRAM] :  Caesar (Caesar’s cipher)
    [AUTHOR]  :  Saddam Arbaa
    [Email]   :  <saddamarbaas@gmail.com>

    CS50X 2020 Problem Set 2 Caesar Implementation
    (a program that encrypts messages using Caesar’s cipher)
    Encrypt messages using Caesar cipher algorithm by “rotating”
    each letter by k positions
    ci = (pi + k) % 26
    and k is a secret key a non-negative integer
    
    Link to the Week 1 lecture
    CS50 2019 - Lecture 1 - C
    https://youtu.be/e9Eds2Rc_x8

    Link to the  Problem Set
    https://cs50.harvard.edu/x/2020/psets/2/caesar/#:~:text=a%20program%20that%20encrypts%20messages%20using%20Caesar%E2%80%99s%20cipher */

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>    /* include cs50.h  Header file */
#include <string.h>  /* include string.h Header file */
#include <ctype.h>  /* include ctype.h Header file */
#include <math.h>  /* include math.h  Header file */

// function to cipher the upper case alphabet
char cipher_UpperCase_Alphabet(char, int);

// function to cipher the lower case alphabet
char cipher_LowerCase_Alphabet(char, int);

/**  GILOBAL constant variable declarations */

const int UPER_CASE_INDEX = 65;     /* Upper case letter 'A' ASCII index */

const int LOWER_CASE_INDEX = 97;    /* lower case letter 'a' ASCII index */

const int NUMBER_OF_ALPHABET_INDEX = 26;  /* number of English alphabet letters */

int main(int argc, string argv[]) /* the river Code */
{
    /* will use to store user given key latter
     after been converted from text to number */
    int user_Key = 0; /* variable declarations */

    // get key from user throw command line arguments
    string key = argv[1];

    // checking if user enter only single arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    // Iterate throw the key which is second command line argument argv[1]
    // and check if all charter are numeric number between 0 -9

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isdigit(key[i]))
        {
            printf("Usage: ./caesar k\n");
            printf("Key must contain only numeric number between 0 -9 .\n");
            return 1;
        }
    }

    user_Key = atoi(key);  // convert the key from string to integer

    // get the plaintext from user
    string plaintext = get_string("plaintext: "); // user plaintext

    /** encrypting process start from here */

    printf("ciphertext: ");  //ciphertext

    /* Iterate throw user plaintext and encrypted by “rotating”
       each letter by given key number */

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        //if char is lowercase
        if (islower(plaintext[i])) // call islower() function
        {
            // call cipher_LowerCase_Alphabet() function for help
            printf("%c", cipher_LowerCase_Alphabet(plaintext[i], user_Key));
        }
        // if char is uppercase
        else if (isupper(plaintext[i])) // call isupper() function
        {
            // call cipher_UpperCase_Alphabet() function for help
            printf("%c", cipher_UpperCase_Alphabet(plaintext[i], user_Key));
        }
        else // lese cases
        {
            //print as is it without change
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");

    return 0;// signal to operating system everything works fine

} /** End of main function */


/**
  cipher_UpperCase_Alphabet Function takes 2 argument
  (Single Uppeercase letter and key) and return new single char after encripated
   ci = (pi + k) % 26  */

char cipher_UpperCase_Alphabet(char indvualChar, int user_Key)
{
    indvualChar = ((indvualChar - UPER_CASE_INDEX) + user_Key) % NUMBER_OF_ALPHABET_INDEX + UPER_CASE_INDEX;
    return indvualChar; // return indvualChar

} /** End of cipher_UpperCase_Alphabet() */


/**
  cipher_LowerCase_Alphabet Function takes 2 argument
  (Single Lower letter and key) and return new single char after encripated
   ci = (pi + k) % 26  */

char cipher_LowerCase_Alphabet(char indvualChar, int  user_Key)
{
    indvualChar = ((indvualChar - LOWER_CASE_INDEX) + user_Key) % NUMBER_OF_ALPHABET_INDEX + LOWER_CASE_INDEX;

    return indvualChar; // return indvualChar

}/** END of cipher_LowerCase_Alphabet() */
