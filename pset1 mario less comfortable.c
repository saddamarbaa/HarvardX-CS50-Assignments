
/**
    [PROGRAM] :  Super Mario Brothers,
    [AUTHOR]  :  Saddam Arbaa
    [Email]   :  <saddamarbaas@gmail.com>
    C Program to Implement CS50x 2020 Problem Set 1
    Super Mario Brothers (the less comfortable)

    Link to the  Problem Set
    https://cs50.harvard.edu/x/2020/psets/1/mario/less/  */

#include <stdio.h>
#include <cs50.h> /* include cs50.h */

// function to positive integer
int get_positive_int(void);

int main(int argc, char *argv[]) /* the river Code */
{
    int Rows, userIput, k, j;  /* variables declarations */

    // asking user input (positive number)
    userIput = get_positive_int(); // call get_positive_int() function

    // outer loop
    for (Rows = 1; Rows <= userIput; Rows++)
    {
        // first inner loop to print spaces
        for (k = 1; k <= userIput - Rows; k++)
        {
            printf(" "); // print spaces
        }
        // second inner loop to print hashes
        for (j = 1; j <= Rows; j++)
        {
            printf("#"); // print hashes
        }
        printf("\n");
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
