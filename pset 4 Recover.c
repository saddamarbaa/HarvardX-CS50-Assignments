/**
    [PROGRAM] :  Recove r(Recover deleted image from memory card)
    [AUTHOR]  :  Saddam Arbaa
    [Email]   :  <saddamarbaas@gmail.com>

    CS50X 2020 Problem Set 4 Recover Implementation.

    Recover is the a program that recovers JPEGs from a forensic image.
    (Recover deleted image from memory card).

    Links to the Week 4 lecture
    https://youtu.be/cF6YkH-8vFk
    Links to the  Problem Set
    https://cs50.harvard.edu/x/2020/psets/4/recover/#:~:text=a%20program%20that%20recovers%20JPEGs%20from%20a%20forensic%20image */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>   /* include stdint.h Header file */
#include <stdbool.h>  /* include stdbool.h Header file */

int main(int argc, char *argv[]) /* the river Code */
{
    // Ensure user ran program with one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        printf("the program should executed with exactly one command-line argument\n");
        return 1;// signal to operating system that program not successes
    }
    // Open file from given memory card( open the memory card)
    FILE *inptrfile = fopen(argv[1], "r");

    // throw error if the file can't be open for any reason
    if (inptrfile == NULL)
    {
        printf("could not open file \n");
        return 1;// signal to operating system that program not successes
    }

    typedef uint8_t BYTE;
    BYTE buffer[512];       // create buffer

    char filename[8];        // create array name filename

    int counter = 0;          // (counter) How many JPGE found

    FILE *img  = NULL;      // create output file for images

    bool open = false;    // to keep track if we've found a JPGE yet or not

    // iterate throw the given memory card and read 512 byte each time until reach the end of memory
    while ((fread(buffer, 512, 1, inptrfile) == 1))
    {
        // Check the first forth bytes to know if its JPGE image or not
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // if file already found close previous file to open new one
            if (open == true)
            {
                fclose(img);
            }
            else
            {
                open = true;
            }
            // Open new file and write first buffer
            sprintf(filename, "%03d.jpg", counter);
            // open file and write the information that been found
            img = fopen(filename, "w");
            counter++; // increment counter by one
        }
        if (open == true)
        {
            // write 512 bytes to the file any time we found start of JPGE
            fwrite(buffer, 512, 1, img);
        }
    }
    // close files
    fclose(img);
    fclose(inptrfile);

    /** End of Recover */

    return 0; // signal to operating system everything works fine

}/** End of main function */
