// Implements a dictionary's functionality

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 50000;

// Hash table
node *table[N];

// Number of words in your dictionary
unsigned int Number_words;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // get the probable position in the array
    unsigned int tag = hash(word);
    //node *cursor = table[tag];
    
    //traverse the linked list looking up for the word
    for(node *cursor = table[tag]; cursor != NULL; cursor = cursor->next)
    {
        if(strcasecmp(cursor->word, word) == 0) //compare the input word with every word in that dictionary section
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    unsigned long hash_number = 5381; //random

    for(const char *ptr = word; *ptr != '\0'; ptr++)
    {
        hash_number = ((hash_number << 5) + hash_number) + tolower(*ptr);
    }

    return hash_number % N;

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{

    //node *table[N]; for monitoring purposes
    // TODO
    // Opening the dictionary file
    FILE *d = fopen(dictionary, "r");
    if(!d)
    {
        return false;
    }

    // Scan the dictionary for words
    char sample[LENGTH + 1];
    unsigned int bucket = 0;

    while (fscanf(d, "%s", sample) != EOF)
    {
        //allocate memory for every new word
        node *new_word = malloc(sizeof(node));

        //check for malloc to success
        if(new_word == NULL)
        {
            printf("failed to allocate memory");
            return false;
        }

        //copying the string read into the new node
        strcpy(new_word->word, sample);
        new_word->next = NULL;

        //asigning a spot in the hashtable
        bucket = hash(new_word->word);

        if(table[bucket] == NULL)
        {
            table[bucket] = new_word;
            Number_words += 1;
        }
        else
        {
            new_word->next = table[bucket];
            table[bucket] = new_word;
            Number_words += 1;
        }
    }

    //momentary freeing memory

    //node *tmp = table[bucket];
    //while(tmp!=NULL)
    //{
    //    node *temp = tmp->next;
    //    free(tmp);
    //    tmp = temp;
    //}
    //monitoring purposes
    fclose(d);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return Number_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *cursor = NULL;
    node *temp = NULL;

    for(unsigned int i = 0; i < N; i++)
    {
        cursor = table[i];

        while(cursor!=NULL)
        {
            temp = cursor->next;
            free(cursor);
            cursor = temp;
        }
    }

    return true;
}
