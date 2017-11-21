#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s k\n", argv[0]);
        return 1;
    }

    int k = atoi(argv[1]);

    printf("plaintext: ");
    string plain_text = get_string();
    int n = strlen(plain_text);

    printf("ciphertext: ");
    for (int i = 0; i < n; i++)
    {
        if(isalpha(plain_text[i]))
        {
            if(isupper(plain_text[i]))
            {
                int alpha_index = plain_text[i] - 65;
                int alpha_cipher_index = (alpha_index + k) % 26;
                int ascii_cipher = alpha_cipher_index + 65;
                printf("%c", (char) ascii_cipher);
            }

            if(islower(plain_text[i]))
            {
                int alpha_index = plain_text[i] - 97;
                int alpha_cipher_index = (alpha_index + k) % 26;
                int ascii_cipher = alpha_cipher_index + 97;
                printf("%c", (char) ascii_cipher);
            }
        }
        else
        {
            printf("%c", plain_text[i]);
        }
    }
    printf("\n");

    return 0;
}