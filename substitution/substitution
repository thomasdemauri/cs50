#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(string p, string map);
bool isAlphaKey(string k);
bool isNotRepeated(string k);


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if (!isAlphaKey(argv[1]))
    {
        printf("Key must contain only alphabetical characters.\n");
        return 1;
    }

    if (!isNotRepeated(argv[1]))
    {
        printf("Key must not repeat characters.\n");
        return 1;
    }

    string map = argv[1];

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    encrypt(plaintext, map);
    printf("\n");

    return 0;
}

void encrypt(string p, string map)
{
    // Iterate over all characters in plaintext
    for (int i = 0, l = strlen(p); i < l; i++)
    {
        // If is uppercase or lowercase to preserve the case in plaintext
        if (isupper(p[i]))
        {
            // Current ASCII value of p minus offset will match with the positions in map
            printf("%c", toupper(map[p[i] - 65]));
        }
        else if (islower(p[i]))
        {
            // Current ASCII value of p minus offset will match with the positions in map
            printf("%c", tolower(map[p[i] - 97]));
        }
        else
        {
            printf("%c", p[i]);
        }
    }
}

bool isAlphaKey(string k)
{
    // Iterate over all characters in key
    for (int i = 0, l = strlen(k); i < l; i++)
    {
        // Check wether current char is alphabetical or not
        if (!isalpha(k[i]))
        {
            return false;
        }
    }

    return true;
}

bool isNotRepeated(string k)
{
    // Iterate over all the characters
    for (int i = 0, l = strlen(k); i < l; i++)
    {
        // Inside every loop iterate again over all the characters
        for (int j = 0; j < l; j++)
        {
            // If i and j is not in the same position
            if (i != j)
            {
                // Compare the current chacacter in loop i with current character in loop j
                if (k[i] == k[j])
                {
                    return false;
                }
            }
        }
    }

    return true;
}