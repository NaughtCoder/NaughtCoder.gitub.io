#define _XOPEN_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s hash\n", argv[0]);
        return 1;
    }
    char test[9];
    char pass[9] = "";
    char salt[3];
    char ascii[95];

    for (int i = 0; i < 95; i++)
    {
        ascii[i]=(char) (i + 32);
    }

    salt[0] = argv[1][0];
    salt[1] = argv[1][1];

     for(int i = 0; i < 95; i++)
        for(int j = 0; j < 95; j++)
            for(int k = 0; k < 95; k++)
                for(int l = 0; l < 95; l++)
                    for(int m = 0; m < 95; m++)
                        for(int n = 0; n < 95; n++)
                            for(int o = 0; o < 95; o++)
                                for(int p = 0; p < 95; p++)
                                {
                                    pass[0] = ascii[i];
                                    pass[1] = ascii[j];
                                    pass[2] = ascii[k];
                                    pass[3] = ascii[l];
                                    pass[4] = ascii[m];
                                    pass[5] = ascii[n];
                                    pass[6] = ascii[o];
                                    pass[7] = ascii[p];

                                    for(int q = 0, r = 8; q <= 7; q++, r--)
                                        for(int s = 0; s < q + 1; s++) {
                                            // take r characters
                                            strncpy(test, pass+s, r);
                                            test[r] = '\0';

                                            // try password of length r
                                            if(strcmp(crypt(test, salt), argv[1]) == 0) {
                                                printf("%s\n", test);
                                                return 0;
                                            }
                                        }
                                }

    return 0;
}