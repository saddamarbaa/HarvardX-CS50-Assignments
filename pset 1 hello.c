/**
    [PROGRAM] :  Hello world!
    [AUTHOR]  :  Saddam Arbaa
    [Email]   :  <saddamarbaas@gmail.com>

    CS50x 2020 Problem Set 1 hello.c

    Link to the  Problem Set
    https://cs50.harvard.edu/x/2020/psets/1/hello/#:~:text=pset1  */

#include <stdio.h>
#include <cs50.h> /* include cs50.h */

int main(int argc, char *argv[]) /* the river Code */
{
    //user input name
    string name = get_string("What is your name?\n");
    printf("hello  %s\n", name);

    return 0;// signal to operating system everything works fine

}/** End of main function */
