/**
 * Implements a dictionary's functionality.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

unsigned int dictionary_size = 0;

int hash_it(char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(needs_hashing); i<n; i++)
        hash = (hash << 2) ^ needs_hashing[i];
    return hash % HASHTABLE_SIZE;
}


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    int z;
    int check;
    int bucket;

    z = strlen(word); //return value of strlen does not include the null terminating character
    char buffer[z+1];

    strcpy(buffer, word);
    for(int y = 0; y < z; y++)
    {
        buffer[y] = tolower(buffer[y]);
    }
    buffer[z + 1] ='\0';
    bucket = hash_it(buffer);

    node *trav = HASH_TABLE[bucket];  //create traversal pointer and point to the bucket of the hashtable with the corresponding word

    while(trav != NULL)
    {
        check = strcmp(trav->value, buffer);
        if(check == 0)
            return true;

        trav = trav->next;
    }

    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{

    FILE *fp = fopen(dictionary, "r");
    if (fp == NULL)
        return false;


    for(int i = 0; i < HASHTABLE_SIZE; i++) //declare and initialize? HASH_TABLE data structure
        HASH_TABLE[i] = NULL;

    int index;
    char word[LENGTH+1];

    while(fscanf(fp, "%s", word) != EOF)
    {
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            unload();
            return false;
        }

        strcpy(new->value, word);
        index = hash_it(new->value);
        if(HASH_TABLE[index] == NULL)
        {
            HASH_TABLE[index] = new;
            new->next = NULL;
        }
        else
        {
            new->next = HASH_TABLE[index];
            HASH_TABLE[index] = new;
        }
        dictionary_size++;
    }

    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dictionary_size;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    for(int k = 0; k < HASHTABLE_SIZE; k++)
    {
        node *trav = HASH_TABLE[k];
        while(trav != NULL)
        {
            node *temp = trav;
            trav = trav->next;
            free(temp);
        }
    }
    return true;
}
