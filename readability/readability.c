#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int countLetters(string s);
int countWords(string s);
int countSentences(string s);
void showResult(int index);

int main(void)
{
    string text = get_string("Text: ");

    // Get necessary values to calculate
    int letters = countLetters(text);
    int words = countWords(text);
    int sentences = countSentences(text);

    // Average number by letters | Average sentences by words
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;

    // Formula
    float index = (int) round(0.0588 * L - 0.296 * S - 15.8);

    showResult(index);
}

int countLetters(string s)
{
    int words = 0;
    // Iterate over all chars of text
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        (isupper(s[i])) ? s[i] = tolower(s[i]) : 0; // Transform each super case in lower case to make easy the verification
        (s[i] >= 'a' && s[i] <= 'z') ? words++ : 0;
    }
    return words;
}

int countWords(string s)
{
    int words = 0;
    // Iterate over all chars of text
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        (s[i] == ' ') ? words++ : 0;
    }
    return words + 1; // + 1 because for loop dont count the last word once there is no blank space to check
}

int countSentences(string s)
{
    int sentences = 0;
    // Iterate over all chars of text
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        (s[i] == '.' || s[i] == '?' || s[i] == '!') ? sentences++ : 0;
    }
    return sentences;
}

void showResult(int index)
{
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}