
/**
* CS 50  2020
* Problem Set 2
* substitution.c
* substitution cipher, “encrypt”  a message
* by replacing every letter with another letter from the 26 charter key
* key should  contain alphabetic chartaters only  and also must not contain repeated  chartaters
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

const int UPERCALE_INDEX = 65; //Upper case letter 'A' ASCII index
const int LOWERCALE_INDEX = 97;  //lower case letter 'a' ASCII index
const int NUMBER_OF_ALPHATE_INDEX = 26;   // number of English alphabet letters

int main(int argc, string argv[])
{
    // key from user throw command line
    string UeserKey = argv[1];

    // checking if user enter only single arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }
    int keylength = strlen(UeserKey);   // key length

    //checking if length of the key is 26 digits

    if (keylength != NUMBER_OF_ALPHATE_INDEX)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // check for non_alphabtical character in the key
    // as the key  must only contain alphabetic characters

    for (int i = 0 ; i < keylength ; i++)
    {
        if (!isalpha(UeserKey[i]))
        {
            printf("key must only contain alphabetic characters \n");

            return 1;
        }
    }
    //  check for repeated  characters

    for (int i = 0 ; i < keylength; i++)
    {
        for (int j = i + 1 ; j < keylength; j++)
        {
            if (UeserKey[i] == UeserKey[j])
            {
                printf("key must not contain repeated  characters . \n");
                return 1;
            }
        }
    }


    string plaintext = get_string("plaintext: "); // ueser plaintext

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // if char is lowercase
        if (islower(plaintext[i]))
        {
            int inedxlow = plaintext[i] - 97;  //substuted with char in the same i inedx from key
            printf("%c", tolower(UeserKey[inedxlow]));
        }

        // if char is uppercase
        else if (isupper(plaintext[i]))
        {
            int  indxup = plaintext[i] - 65;
            printf("%c", toupper(UeserKey[indxup])); //substuted with char in the same i inedx from key
        }
        else
        {
            //print as  is it without chane
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");

    return 0;
}












