/**
    [PROGRAM] :  Super Mario Brothers Implementation
    [AUTHOR]  :  Saddam Arbaa
    [Email]   :  <saddamarbaas@gmail.com>
    C Program to Implement CS50x 2020 Problem Set 1
    Super Mario Brothers(the more comfortable version)
    
    Link to the Week 1 lecture
    CS50 2019 - Lecture 1 - C
    https://youtu.be/e9Eds2Rc_x8
    
    Link to the  Problem Set
    https://cs50.harvard.edu/x/2020/psets/1/mario/more/  */

#include <stdio.h>
#include <cs50.h> /* include cs50.h */

// function to get positive integer
int get_positive_int(void);

int main(int argc, char *argv[]) /* the river Code */
{
    /* variables declarations */
    int userIput, Rows, spaces, leftHashes, rightHashes, gap;  

    // asking user input (positive number)
    userIput = get_positive_int(); // call get_positive_int() function

    // outer loop
    for (Rows = 1; Rows <= userIput; Rows++)
    {
        // loop to print spaces
        for (spaces = 1; spaces <= userIput - Rows; spaces++)
        {
            printf(" "); // print spaces
        }
        // loop to print the left Hashes
        for (leftHashes = 1; leftHashes <= Rows; leftHashes++)
        {
            printf("#"); // print hashes
        }
        // loop to print the gap between left Hashes and right Hashes
        for (gap = 1; gap <= 2; gap++)
        {
            printf(" "); // print gap
        }
        
        // loop to print the right Hashes
        for (rightHashes = 1; rightHashes <= Rows; rightHashes++)
        {
            printf("#"); // print right Hashes
        }
        printf("\n"); // new line after each Row
    }
    
    return 0;// signal to operating system everything works fine

}/** End of main function */


/** function to Prompt user for positive integer between 1 and 8 */

int get_positive_int(void)
{
    int n; /* local variable declarations    */
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8); // Prompt user for Height between 1 and 8

    return n; // return the Height

} /** End of get_positive_int() */
