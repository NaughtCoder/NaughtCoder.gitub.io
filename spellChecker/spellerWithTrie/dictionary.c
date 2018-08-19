/**
 * Implements a dictionary's functionality.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#include "dictionary.h"

int dict_size = 0; //create global variable to count size;

void freeing(trie *node) //free pointers from bottom to top
{
    for(int b = 0; b < 27; b++)
    {
        if(node->children[b] != NULL)
        {
            freeing(node->children[b]);
        }
    }
    free(node);
}


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    //create traversal pointer for checking
    trie *trav = root;
    int a = 0;
    while (word[a] != '\0')
    {
        if(isalpha(word[a]))
        {
            char c = tolower(word[a]);
            if(trav->children[c - 97] == NULL)
                return false;

            trav = trav->children[c - 97];
        }
        else
        {
            if(trav->children[26] == NULL)
                return false;

            trav = trav->children[26];
        }
        a++;
    }

    if(trav->is_word == true)
        return true;

    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // TODO
    FILE *fp = fopen(dictionary, "r");

    //check for null
    if (fp == NULL)
    {
        return false;
    }

    // initalize root pointer and give it default values
    root = malloc(sizeof(trie));
    root->is_word = false;
    for(int j = 0; j < 27; j++)
        root->children[j] = NULL;

    char word[46];
    int index;

    while(fscanf(fp, "%s", word) != EOF)
    {
        trie *current = root;
        int i = 0;

        while(word[i] != '\0')
        {
            if(isalpha(word[i]))
                index = tolower(word[i]) - 97;
            else
                index = 26;

            if(current->children[index] == NULL)
            {
                trie *new = malloc(sizeof(trie)); //allocate memory for a new temp node

                if (new == NULL) //check for memory allocation failure
                {
                    fprintf(stderr, "Could not allocate memory");
                    return false;
                }

                new->is_word = false; //set bool value in the new node to false
                for (int k = 0; k < 27; k++) //assign the children pointer arrays to point to null/nothing
                    new->children[k] = NULL;

                current->children[index] = new; //make the current nodes children array point to the new temp node
            }
            current = current->children[index]; //assign value of current pointer to point at the new node as well
            i++;
        }
        current->is_word = true;
        dict_size++;

    }

    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dict_size;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    trie *trav = root;
    freeing(trav);
    return true;
}
