#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int validator;
    long long buffer;
    long long cc_number;
    long long thirteen_dig = pow(10, 12);
    long long fourteen_dig = pow(10, 13);
    long long fifteen_dig  = pow(10, 14);
    long long sixteen_dig  = pow(10, 15);
    long long max          = pow(10, 16);


    do
    {
        printf("Number: ");
        cc_number = get_long_long();
    }
    while (cc_number <= 0);

    if (cc_number >= thirteen_dig && cc_number <= max)
    {
        int ones_dig = cc_number % 10;                          /* last dig */
        buffer = cc_number % 100;
        int tens_dig = floor(buffer / 10);                      /* second last dig */
        buffer = cc_number % 1000;
        int hundred_dig = floor(buffer / 100);
        buffer = cc_number % 10000;
        int thousands_dig = floor(buffer / 1000);
        buffer = cc_number % 100000;
        int ten_thousands_dig = floor(buffer / 10000);
        buffer = cc_number % 1000000;
        int hundred_thousands_dig = floor(buffer / 100000);
        buffer = cc_number % 10000000;
        int million_dig = floor(buffer / pow(10,6));
        buffer = cc_number % 100000000;
        int ten_million_dig = floor(buffer / pow(10,7));
        buffer = cc_number % 1000000000;
        int hundred_million_dig = floor(buffer / pow(10,8));
        buffer = cc_number % 10000000000;
        int billion_dig = floor(buffer / pow(10,9));
        buffer = cc_number % 100000000000;
        int ten_billion_dig = floor(buffer / pow(10,10));
        buffer = cc_number % 1000000000000;
        int hundred_billion_dig = floor(buffer / pow(10,11));
        buffer = cc_number % 1000000000000;
        int trillion_dig = floor(buffer / pow(10,12));        /* thirteenth digit */


        if (cc_number >= fifteen_dig && cc_number < sixteen_dig) /* AMEX potential*/
        {
            validator = floor(cc_number / fourteen_dig);
            if (validator == 34 || validator == 37)
            {
                buffer = cc_number % 10000000000000;
                int ten_trillion_dig = floor(buffer / pow(10,13));

            }
            else
            {
                printf("INVALID");
            }
        }
    }
    else
    {
        printf ("INVALID");
    }


    return 0;
}