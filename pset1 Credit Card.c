/**
    [PROGRAM] :  Credit (Luhn’s Algorithm)
    [AUTHOR]  :  Saddam Arbaa
    [Email]   :  <saddamarbaas@gmail.com>

    CS50X 2020 Problem Set 1 Credit Card Program Implementation

    Link to the  Problem Set
    https://cs50.harvard.edu/x/2020/psets/1/credit/#:~:text=Card */

#include <cs50.h> /* include cs50.h  Header file */
#include <stdio.h>

// function to find the first digit from credit card
long first_Digit(long);

// function to check if credit card is valid or not
bool checksum(long);

// function to find the start two digit from credit card
long start_Two_Digit(long);

// function to the credit card length
long get_Length(long);

int main(int argc, char *argv[]) /* the river Code */
{
    long long ueserInput = 0; // Declare and initialize a variable

    do // asking user to input credit card number
    {
        ueserInput = get_long("Enter the credit card number : ");
    }
    while (ueserInput <= 0);

    //check credit card validation
    bool isValid = checksum(ueserInput); // call checksum() function

    // get start two digit of the credit card
    long first_two_digits = start_Two_Digit(ueserInput); // call start_Two_Digit() function

    // get the first digit of the credit card
    long fitst_digits = first_Digit(ueserInput);  // call first_Digit() function

    // get the Length of the credit card
    long length = get_Length(ueserInput); // call get_Length() function

    // only for testing
    // printf("\n length %d\n",(int)number_Length);
    // printf("\n first two digits %d \n",(int)first_two_digits);
    // printf("\n first  digits %d \n",(int)fitst_digits);

    /* check for all the corner cases */

    if ((isValid && (first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 ||
                     first_two_digits == 54 || first_two_digits == 55)) && length == 16)
    {
        printf("MASTERCARD\n") ;
    }
    else if (isValid && (first_two_digits == 34 || first_two_digits == 37) && length == 15)
    {
        printf("AMEX\n");
    }

    else if (isValid &&  fitst_digits == 4 && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;// signal to operating system everything works fine

} /** End of main function */


/**
  checksum Function takes one argument
 (user input of type long credit card number) as
  and return true if credit card is valid in system
  else if not valid return false */

bool checksum(long ueserInput)
{
    // local variables declarations
    long even_number, odd_number, even_numberSum , odd_numberSum ;

    long temp = 0, result = 0;

    // initialize flowing variable to zero
    even_number = 0;
    odd_number = 0;
    even_numberSum = 0;
    odd_numberSum = 0;

    even_number = ueserInput; // save in even_number ueserInput
    odd_number = ueserInput; // save in odd_number ueserInput

    //printf("even number\n");

    /*
    finding sum of number start from second
    digits * 2 according to Luhn’s Algorithm */

    while (even_number > 10)
    {
        even_number = even_number / 10;
        temp =  even_number % 10;
        even_number = even_number / 10;

        //  printf("%d\t ",(int)temp);
        result = temp * 2;

        if (result > 9)
        {
            result = result % 10 + 1;
        }

        even_numberSum = even_numberSum +  result;
    }

    //printf("\n even sum  =  %d\n",(int)even_numberSum);
    //printf("odd number\n");
    // finding sum of each other digit start from first digits according to Luhn’s Algorithm

    while (odd_number > 0)
    {
        temp = odd_number % 10;

        //  printf("%d\t",(int)temp);
        odd_number = odd_number / 100;
        odd_numberSum = odd_numberSum + temp;
    }

     // printf("\n odd sum = %d  \n",(int)odd_numberSum);

    // calculate  the total sum
    long total_sum = even_numberSum + odd_numberSum;

    //  printf("\n total sum = %d  \n",(int)total_sum);

    // check if the last digits == 0  if so its valid number
    if ((int)total_sum % 10 == 0)
    {
        return true;
    }

    return false;

}/** End of checksum() */


/**
  start_Two_Digit() function take user input as argument
  and return first two digit from credit card number*/

long start_Two_Digit(long ueserInput)
{
    while (ueserInput >= 100)
    {
        ueserInput = ueserInput / 10;
    }
    return  ueserInput;

} /** End of start_Two_Digit()*/


/**
  first_Digit() function take user input as argument
  and return first digit from the credit card  number */

long first_Digit(long ueserInput)
{
    while (ueserInput >= 10)
    {
        ueserInput = ueserInput / 10;
    }
    return  ueserInput;

} /**End of first_Digit()*/


/**
  get_Length() function take user input as argument
  return how many digit in the credit card */

long get_Length(long ueserInput)
{
    long count = 0; // counter variable declaration
    while (ueserInput > 0)
    {
        ueserInput = ueserInput / 10;
        count ++; // increment counter by one
    }
    return count; // return number of digit in the credit card

} /** End of get_Length() */
