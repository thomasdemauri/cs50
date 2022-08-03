#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool validateKey(string key);
void encrypt(string text, int key);

int main(int argc, string argv[])
{
    // Check if there is more than 1 command-line argument
    if (argc != 2)
    {
        printf("Error\n");
        return 1;
    }

    // Check if every char in argument is between '0' and '9'
    if (!validateKey(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Prompt's user
    string plaintext = get_string("plaintext: ");

    // Convert into int
    int key = atoi(argv[1]);

    encrypt(plaintext, key);

    return 0;
}

bool validateKey(string key)
{
    for (int i = 0, l = strlen(key); i < l; i++)
    {
        // If the current char is not a digit the function will return false
        if (!isdigit(key[i]))
        {
            return false;
        }
    }

    // If every char in key is a digit
    return true;
}

void encrypt(string p, int key)
{
    printf("ciphertext: ");
    /*
        Current value ASCII plus key minus 97 or  65
        This result module by 26 will return the numbers of houses to wrap around
        Then sum again with 97 or 65 to return the new value ASCII
    */
    for (int i = 0, l = strlen(p); i < l; i++)
    {
        if (islower(p[i]))
        {
            printf("%c", (p[i] + key - 97) % 26 + 97);
        }
        else if (isupper(p[i]))
        {
            printf("%c", (p[i] + key - 65) % 26 + 65);
        }
        else
        {
            printf("%c", p[i]);
        }
    }

    printf("\n");
}