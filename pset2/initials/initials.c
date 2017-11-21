#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string();
    int i = 0;

    if(name[i] != ' ')
    {
        printf("%c", toupper(name[i]));
    }

    while(name[i] != '\0')
    {
        if(name[i] == ' ')
        {
            while(name[i] == ' ' )
            {
                i++;
            }
            printf("%c", toupper(name[i]));
        }
        i++;
    }
    printf("\n");
}