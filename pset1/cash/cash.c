#include <stdio.h>
#include <math.h>
#include <cs50.h>

float get_correct_float(void);

int main(void)
{
 
 float owed = get_correct_float();
 
 int cents = round(owed * 100);
 
 int count = 0;
 
//printf("owed: %f\n", owed); //to check if the floating variable is working propperly
 
//printf("cents: %i\n", cents); //to check if the cents convertion is working propperly
 
while(cents>0) // substracting from the highest coin posible. Relations mutually exclusive.
{
 if(cents>=25)
 {
  cents -= 25;
  count++;
 }
    else if(cents>=10)
    {
     cents -= 10;
     count++;   
    }
       else if(cents>=5)
      {
       cents -= 5;
       count++;
      }
        else if(cents>=1)
        {
         cents -= 1;
         count++;
        }
}

printf("%i\n", count);

}







float get_correct_float(void)
{
    float x;
    do
    {
     x = get_float("Change Owed: ");
    }

    while(x<0);
    return x;
}