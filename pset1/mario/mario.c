#include <stdio.h>
#include <cs50.h>

int get_correct_hight(void);

int main(void)
{
 int height = get_correct_hight();

//printf("your height is: %i\n", height);

 for(int i=0; i<height; i++)
  {

    for(int k= 0 ; k<height-i-1; k++) // k<height-i-1 putting the dots correctly to right-align the pyramid
     {
       printf(" ");
     }

     for(int j=0; j <= i; j++) // j <= i to make a pyramid instead of a square
     {
       printf("#");
     }

     printf("\n");
 }

}

int get_correct_hight(void)
{
    int x;
    do
    {
     x = get_int("Height: ");
    }

    while(x<1 || x>8);
    return x;
}