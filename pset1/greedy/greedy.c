#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    float buffer;
    int cents;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    int remaining;
    int total;

    printf("O hai! How much change is owed?\n");

    do {
        change = get_float();
        if (change < 0)
        {
            printf("O hai! How much change is owed?\n");
        }
    }
    while (change < 0);

    buffer = change * 100;
    cents = round(buffer); /* round cents to prevent imprecision*/

    while (cents > 0)
    {
        if (cents % 25 != 0)
        {
            remaining = cents % 25;
            quarters = floor(cents / 25);
            cents = remaining;

        }
        if (cents % 25 == 0)
        {
            quarters = cents / 25;
            cents = 0;
        }

        if (cents % 10 != 0)
        {
            remaining = cents % 10;
            dimes = floor(cents / 10);
            cents = remaining;

        }

        if (cents % 10 == 0)
        {
            dimes = cents / 10;
            cents = 0;
        }

        if (cents % 5 != 0)
        {
            remaining = cents % 5; /* %= */
            nickels = floor(cents / 5);
            cents = remaining;

        }

        if (cents % 5 == 0)
        {
            nickels = cents / 5;
            cents = 0;
        }

        if (cents != 0)
        {
            pennies = cents / 1;
            cents = 0;
        }

        total = quarters + dimes + nickels + pennies;
        printf("%d\n", total);
    }

    return 0;
}