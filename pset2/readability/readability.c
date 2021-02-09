#include<stdio.h>
#include<cs50.h>
#include<string.h>


int main(void)
{
   string s = get_string("Text: ");

   int letters = 0; //letters
   int words = 1; //Words. Starts in one in order to count the last word in the text, because it doesn't have a space at the end to count it.
   int sentences = 0; //Sentences
   
   for (int i = 0, n = strlen(s); i < n; i++)
   {
      if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')) // Count the number of letters
      {
        letters += 1;
      }
           
      if(s[i] == ' ')  // Count a space as the end of a word
      {
        words += 1;
      }
           
      if(s[i] == '.' || s[i] == '!' || s[i] == '?') // Count dots, exclamations and interrogation marks as an end of a sentence
      {
        sentences += 1;
      }
   }
     
   //printf("%i Letters\n", letters); //show the number of letters
   //printf("%i Words\n", words); //show the number of words
   //printf("%i Sentences\n", sentences);  //show the number of sentences
   
   float L = 0; // average number of letters per 100 words
   float S = 0; // average number of sentences per 100 words
   float Index = 0; // Coleman-Liau index
   
   L = ((float)letters /(float) words) * 100;
   S = ((float)sentences /(float) words) * 100;
   
   Index = 0.0588 * L - 0.296 * S - 15.8;
  
   if(Index >= 16)
   {
     printf("Grade 16+\n");
   }
    
   else if(Index < 1) 
   {
     printf("Before Grade 1\n");
   }
     
   else 
   {
     printf("Grade %.0f\n", Index);
   }
}

