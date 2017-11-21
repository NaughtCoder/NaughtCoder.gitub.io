#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int height;
    printf("Please input the height of the pyramid within 0 and 23 inclusive: ");

    do
    {
        height = get_int();
        if (height < 0 || height > 23)
        {
            printf("Retry: ");
        }
    }
    while (height < 0 || height > 23); /* keep prompting user for input until condition is satisfied*/

    int hash;
    int space;
    int row;

    for (row = 1; row <= height; row++)
    {
        for (space = (height - row); space > 0; space--) /*for loop for printing spaces*/
        {
            printf(" ");
        }

        for (hash = 1; hash <= (row + 1); hash++) /* print hashes*/
        {
            printf("#");
        }

        printf("  ");

        for (hash = 1; hash <= (row+1); hash++)
        {
            printf("#");
        }
        printf("\n");
    }


}