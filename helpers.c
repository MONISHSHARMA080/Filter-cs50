#include "helpers.h"
#include <math.h>

int max(int var, int max)
{
  if (var > max)
  {
    var = max;
  }
  return var;
}
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
      {
        int p = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3.0) ;
        image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = p ;
      }
    }
}


void sepia(int height, int width, RGBTRIPLE image[height][width])
{
   for(int i=0;i< height ; i++)
  {
     for(int j=0; j< width ; j++)
      {
            int sepiablue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            int sepiagreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiared = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            image[i][j].rgbtRed =   max(sepiared,255);
           image[i][j].rgbtGreen = max(sepiagreen,255);
           image[i][j].rgbtBlue = max(sepiablue,255);

      }
  }
    return;
}

// Reflect image horizontally
    void reflect(int height, int width, RGBTRIPLE image[height][width])
{


    // not did it (if functionf)or every coulur, if on middle or in even- 4+1/2 -1 stop
    for(int i=0;i< height ; i++)
   {
    int f = (width /2) ;
     if(width % 2 != 0)
     {
       f = round(width/2) ;
     }
     for(int j=0; j< f ; j++)
      {
        RGBTRIPLE temp[height][width];
        temp[i][j] = image[i][j];
        image[i][j] =  image[i][width-1-j];
        image[i][width-1-j] =  temp[i][j] ;
      }
  }
  return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
   RGBTRIPLE copy[height][width];
   {
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
   }

  for (int i = 0 ; i < height; i++)
  {
    for (int j=0; j<width;j++)
    {
     float avgb = 0;
     float avgg = 0;
     float avgr = 0;
// divide by times addded
  int counter =0;
       for (int k=-1;k<2;k++)
       {
         for(int l=-1;l<2;l++)
         {
          if((k+i>=0 && k+i<=height-1) && (j+l>=0 && j+l<=height-1))
            {
              avgr  += copy[i+k][j+l].rgbtRed;
              avgb  += copy[i+k][j+l].rgbtBlue;
              avgg  += copy[i+k][j+l].rgbtGreen;
              counter++;
            }
           }
         }
        image[i][j].rgbtRed= round((avgr)/counter);
        image[i][j].rgbtGreen=round((avgg)/counter);
        image[i][j].rgbtBlue= round((avgb)/counter);
       }
    }
return;
}