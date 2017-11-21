/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <math.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)   // value = the number we are asked to find, values[] = arrays of values that are gen'd
{                                             // n = size of the array
    // Binary Search with -> O(log n)
    if (n <= 0)
    {
        return false;
    }

    int start = 0;
    int end = n - 1;
    int middle = round((start + end) / 2);


    while (start <= end)
    {
        if (value == values[middle])
        {
            return true;
        }
        else if (value > values[middle]) //look to the right
        {
            start = middle + 1;
            middle = round((start + end) / 2);
        }
        else if (value < values[middle]) //look to the left
        {
            end = middle - 1;
            middle = round((start + end) / 2);
        }
    }

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)     // values = array of values that we are given, n = size of the array
{
    if (n == 1)
    {
        return;
    }

    int swap, i, h;

    for (i = 0; i < (n - 1); i++)
    {
        for (h = 0; h < (n - i -1); h++)
        {
            if(values[h] > values[h+1])
            {
                swap = values[h];
                values[h] = values[h+1];
                values[h+1] = swap;
            }
        }
    }
    return;
}
