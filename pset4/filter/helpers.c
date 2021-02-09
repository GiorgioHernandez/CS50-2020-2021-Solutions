#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
   float avr; //Average variable

   for(int i = 0; i < height; i++)
   {
       for(int j = 0; j < width; j++)
       {
           avr = image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen; // Obtain the sum of all 3 values

           avr = avr/3; // Calculating the average

           image[i][j].rgbtRed = (int) round(avr); //putting the new values to its respective color
           image[i][j].rgbtBlue = (int) round(avr);
           image[i][j].rgbtGreen = (int) round(avr);
       }
   }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed;
    float sepiaGreen;
    float sepiaBlue;
    
    RGBTRIPLE tmp[1];
    
    for(int i = 0; i < height; i++)
    {
       for(int j = 0; j < width; j++)
       {
           //sepia red
           tmp[0].rgbtRed = image[i][j].rgbtRed;
           tmp[0].rgbtGreen = image[i][j].rgbtGreen;
           tmp[0].rgbtBlue = image[i][j].rgbtBlue;
           
           sepiaRed = .393 * tmp[0].rgbtRed + .769 * tmp[0].rgbtGreen + .189 * tmp[0].rgbtBlue;

           if(sepiaRed > 255)
           {
               sepiaRed = 255;
           }

           //sepia Green
           tmp[0].rgbtRed = image[i][j].rgbtRed;
           tmp[0].rgbtGreen = image[i][j].rgbtGreen;
           tmp[0].rgbtBlue = image[i][j].rgbtBlue;
           
           sepiaGreen = .349 * tmp[0].rgbtRed + .686 * tmp[0].rgbtGreen + .168 * tmp[0].rgbtBlue;

           if(sepiaGreen > 255)
           {
               sepiaGreen = 255;
           }

           //sepia Blue
           tmp[0].rgbtRed = image[i][j].rgbtRed;
           tmp[0].rgbtGreen = image[i][j].rgbtGreen;
           tmp[0].rgbtBlue = image[i][j].rgbtBlue;
           
           sepiaBlue = .272 * tmp[0].rgbtRed + .534 * tmp[0].rgbtGreen + .131 * tmp[0].rgbtBlue;

           if(sepiaBlue > 255)
           {
               sepiaBlue = 255;
           }

           image[i][j].rgbtRed = round(sepiaRed);
           image[i][j].rgbtGreen = round(sepiaGreen);
           image[i][j].rgbtBlue = round(sepiaBlue);

       }

    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[1];

    for(int i = 0; i < height; i++)
    {
       for(int j = 0, k = width; j < k; j++)
       {
           //Saving the actual colors into a temporary variable
           tmp[0].rgbtRed = image[i][j].rgbtRed;
           tmp[0].rgbtGreen = image[i][j].rgbtGreen;
           tmp[0].rgbtBlue = image[i][j].rgbtBlue;

           //Swaping the last values with the first ones
           image[i][j].rgbtRed = image[i][width-j-1].rgbtRed;
           image[i][j].rgbtGreen = image[i][width-j-1].rgbtGreen;
           image[i][j].rgbtBlue = image[i][width-j-1].rgbtBlue;

           image[i][width-j-1].rgbtRed = tmp[0].rgbtRed;
           image[i][width-j-1].rgbtGreen = tmp[0].rgbtGreen;
           image[i][width-j-1].rgbtBlue = tmp[0].rgbtBlue;

           k--;
       }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE BlurImage[height][width];
    double AvrRed, AvrBlue, AvrGreen;
    int Count;
    
    for(int i = 0; i < height; i++)
    {
       for(int j = 0; j < width; j++)
       {
           AvrRed = AvrBlue = AvrGreen = Count = 0; 
           
           //Blur
           for(int k = i - 1; k <= i + 1; k++) // 1 Row before and after the current pixel
           {
               for(int l = j - 1; l <= j + 1; l++) // 1 Column before and after the current pixel
               {
                   if((k >= 0 && k < height) && (l >= 0 && l < width)) // Only valid pixels will enter in the calculation
                   {
                       AvrRed += image[k][l].rgbtRed;
                       AvrBlue += image[k][l].rgbtBlue;
                       AvrGreen += image[k][l].rgbtGreen;
                       Count++; //Count how many pixels enter the calculation to use in the average
                   }
               }
           }
           
           if(Count != 0)
           {
               // Average calculation
               AvrRed = round(AvrRed / (double) Count);
               AvrBlue = round(AvrBlue / (double) Count);
               AvrGreen = round(AvrGreen / (double) Count); 
               
               // Put the averages in a temporary image
               BlurImage[i][j].rgbtRed = AvrRed;
               BlurImage[i][j].rgbtBlue = AvrBlue;
               BlurImage[i][j].rgbtGreen = AvrGreen;
           }
       }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j] = BlurImage[i][j];
        }
    }
    return;
}
