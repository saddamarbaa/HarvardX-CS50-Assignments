/**
    [PROGRAM] :  Filter(the more comfortable version)
    [AUTHOR]  :  Saddam Arbaa
    [Email]   :  <saddamarbaas@gmail.com>

    CS50X 2020 Problem Set 4 Filter the more comfortable
    version Implementation.
    Filter is a program that applies filters to BMPs(images).
    Links to the Week 4 lecture
    https://youtu.be/cF6YkH-8vFk
    Links to the  Problem Set
    https://cs50.harvard.edu/x/2020/psets/4/filter/more/ */

#include "helpers.h"  /* include helpers.h Header file */
#include "math.h"    /* include math.h Header file */

/**
 function to Convert image to grayscale
 this grayscale function loop throw the two dimensional array
 and calculate the average number of image[height][width] for color
 Red ,Green ,Blue

 then set value of red ,green and blue to average value */

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    /* variable declarations */
    int i, j, Red, Green, Blue, grayscale;
    float gray;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            Red = image[i][j].rgbtRed;
            Green = image[i][j].rgbtGreen;
            Blue = image[i][j].rgbtBlue;

            // calculate the  average
            gray = (Red + Green + Blue) / 3.0;
            grayscale = round(gray); // round the value

            // rest the value of each color to be the average value
            image[i][j].rgbtRed = grayscale;
            image[i][j].rgbtGreen = grayscale;
            image[i][j].rgbtBlue = grayscale;
        }
    }

} /** ENF of grayscale() */


/**
 function to Convert image to sepia
 this sepia function Convert image to sepia by looping
 throw the two dimensional array and for each pixel calculate
 new color value using sepia formula blow

 sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
 sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
 sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
 ensure the result is an integer number between 0 to 255 inclusive
 set value of red , green and blue to average value */

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    /* variable declarations */
    int i, j, Red, Green, Blue, sepiaRed, sepiaGreen, sepiaBlue;
    float sRed, sGreen, sBlue;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            Red = image[i][j].rgbtRed;
            Green = image[i][j].rgbtGreen;
            Blue = image[i][j].rgbtBlue;

            // sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
            sRed =  .393 * Red + .769 * Green + .189 * Blue;
            sepiaRed = round(sRed); // round the value

            // ensure the new value is integer number between 0 and 255 inclusive
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            else if (sepiaRed < 0)
            {
                sepiaRed = 0;
            }
            // sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
            sGreen =  .349 * Red + .686 * Green + .168 * Blue;
            sepiaGreen = round(sGreen); // round the value

            // ensure the new value is  integer number between 0 and 255 inclusive
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            else if (sepiaGreen < 0)
            {
                sepiaGreen = 0;
            }
            // sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
            sBlue =  .272 * Red + .534 * Green + .131 * Blue;
            sepiaBlue =  round(sBlue); // round the value

            //ensure the new value is  integer number between 0 and 255 inclusive
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            else if (sepiaBlue < 0)
            {
                sepiaBlue = 0;
            }

            // rest the value of each color to sepia value
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

} /** END of sepia() */


/**
 function to Reflect image horizontally
 this Reflecting function take image and produce a mirror image
 of that original picture by looping throw the two dimensional array and swap pixel on
 horizontally opposite side in each Row */

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    /* variable declarations */
    int i, j, Red, Green, Blue;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width / 2; j++)
        {
            // temp variable to use in swap process
            RGBTRIPLE temp  = image[i][j];

            image[i][j] = image[i][width - 1 - j];

            image[i][width - 1 - j] = temp;

            Red = image[i][j].rgbtRed;

            Green = image[i][j].rgbtGreen;

            Blue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = Red;

            image[i][j].rgbtGreen = Green;

            image[i][j].rgbtBlue = Blue;
        }
    }
}/** END of reflect() */


/**
  function to Blur image
  Blur function blur the image by looping throw each pixel in
  the picture and average the color values of neighboring pixels */

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copyimage[height][width]; // Gets mirror image to work on

    /* variable declarations */

    int i, j, Red, Green, Blue, counter;

    float newRed, newGreen, newBlue;

    // Go through all pixels and copy to copyimage
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            copyimage[i][j] = image[i][j];
        }
    }

    /* iterate throw entire image i for rows (height),
    j for columns (width)
    for each pixel in the image calculate blur color value
    by averaging the color values of neighboring pixels */
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            /* initialize flowing variable to zero */
            newRed = 0.0;
            newGreen = 0.0;
            newBlue = 0.0;
            counter = 0;

            // checks each pixel within -1 to + 1 of each row  [i] (left to right)
            for (int m = -1; m < 2; m++)
            {
                // checks each pixel withint -1 to +1 of each j pixel ( up to down)
                for (int n = -1; n < 2; n++)
                {
                    // check first if the pixel within bounds blow
                    //if so then find new value by averaging the color values of neighboring pixels

                    if (i + m >= 0  && j + n >= 0 && i + m < height && j + n < width)
                    {
                        newRed = copyimage[i + m][j + n].rgbtRed + newRed;
                        newGreen = copyimage[i + m][j + n].rgbtGreen + newGreen;
                        newBlue = copyimage[i + m][j + n].rgbtBlue + newBlue;
                        counter++; // increment counter by one
                    }
                }
            }
            /* set the new value back to original image */
            image[i][j].rgbtRed = round(newRed / counter);
            image[i][j].rgbtGreen = round(newGreen / counter);
            image[i][j].rgbtBlue = round(newBlue / counter);
        }
    }

} /** END of blur() */


/**
 *  Detect edges function(Sobel filter algorithm)

  detect edges in an image : lines in the image that create
  a boundary between one object and another by applying the Sobel
  operator  algorithms for image processing. */

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    /* variable declarations */
    int i, j;
    long GXRed, GYRed, GXGreen, GYGreen, GXBlue, GYBlue;


    //Convolution GX Matrix
    // -1   0    1
    // -2   0    2
    // -1   0    1

    int GX [3][3] = {{ -1,   0,  1}, { -2,  0,  2}, { -1,  0,  1} };

    //Convolution GY Matrix
    //   -1   -2  -1
    //    0    0   0
    //    1    2    1

    int GY [3][3] = { { -1,  -2,  -1}, { 0,  0,  0   }, { 1,  2, 1   }  };

    // Gets mirror image to work on
    RGBTRIPLE copyimage[height][width];

    // Go through all the pixels and copy to copyimage
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            copyimage[i][j] = image[i][j];
        }
    }
    /* iterate throw entire image i for rows (height),
    j for columns (width) */
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            /* initialize flowing variable to zero */
            GXRed = 0.0;
            GYRed = 0.0;
            GXGreen = 0.0;
            GYGreen = 0.0;
            GXBlue = 0.0;
            GYBlue = 0.0;

            // checks each pixel within -1 to + 1 of each row  [i] (left to right)
            for (int m = -1, x = 0; m < 2; m++, x++)
            {
                // checks each pixel withint -1 to +1 of each j pixel ( up to down)
                for (int n = -1, y = 0; n < 2; n++, y++)
                {
                    // check first if the pixel within bounds blow
                    if (i + m >= 0  && j + n >= 0 && i + m < height && j + n < width)
                    {
                        GXRed = GXRed + copyimage[i + m][j + n].rgbtRed  * GX [x][y];
                        GYRed = GYRed + copyimage[i + m][j + n].rgbtRed  * GY [x][y];

                        GXGreen = GXGreen + copyimage[i + m][j + n].rgbtGreen  * GX [x][y];
                        GYGreen = GYGreen + copyimage[i + m][j + n].rgbtGreen * GY [x][y];

                        GXBlue = GXBlue + copyimage[i + m][j + n].rgbtBlue  * GX [x][y];
                        GYBlue = GYBlue + copyimage[i + m][j + n].rgbtBlue  * GY [x][y];
                    }
                }
            }

            /*
            compute each new channel values using The Sobel filter
            algorithm which combines Gx and Gy into a final value
            by calculating the square root of Gx^2 + Gy^2 */

            int totalRed = round(sqrt((GXRed * GXRed) + (GYRed * GYRed)));

            // ensure the new value is  integer number between 0 and 255 inclusive
            if (totalRed > 255)
            {
                totalRed = 255;
            }
            else if (totalRed < 0)
            {
                totalRed = 0;
            }
            int totalGreen = round(sqrt((GXGreen * GXGreen) + (GYGreen  * GYGreen)));

            // ensure the new value is  integer number between 0 and 255 inclusive
            if (totalGreen > 255)
            {
                totalGreen = 255;
            }
            else if (totalGreen < 0)
            {
                totalGreen = 0;
            }
            int totalBlue = round(sqrt((GXBlue * GXBlue) + (GYBlue * GYBlue)));

            // ensure the new value is  integer number between 0 and 255 inclusive
            if (totalBlue > 255)
            {
                totalBlue = 255;
            }
            else if (totalBlue < 0)
            {
                totalBlue = 0;
            }

            // assign the final value from the copy image back to original image
            image[i][j].rgbtRed = totalRed;
            image[i][j].rgbtGreen = totalGreen;
            image[i][j].rgbtBlue = totalBlue;
        }
    }
} /** END of edges() */

