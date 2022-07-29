#include <stdio.h>
#include <cs50.h>

int length(long n)
{
    int len = 0;
    for (; n > 0; n /= 10)
    {
        len++;
    }
    return len;
}

bool lunhsAlgorithm(long n, int len)
{
    long cNumber = n;
    int digit;  // Current digit
    int sum = 0;
    bool multiply = false; // Trigger to alternate between multiply every other digit and just sum the normal's digit

    // Iterate over all the digits
    for (int i = 0; i < len; i++)
    {
        digit = cNumber % 10; // Get current digit

        // Each loop multiply will alternate between false and true and depending on value will do something
        if (!multiply)
        {
            sum += digit;
            multiply = true;
        }
        else
        {
            digit *= 2;
            sum += (digit / 10) + (digit % 10); // In case the number is greather than 9 will break it self in two digits and sum them
            multiply = false;
        }

        cNumber /= 10; // Next number
    }
    return sum % 10 == 0 ? true : false;
}

void findFlag(long n, int len)
{
    long cNumber = n;
    bool checkSum = lunhsAlgorithm(cNumber, len);

    // Iterate over all the digits and stop at two first digits
    for (int i = 0; i < len - 2; i++)
    {
        cNumber /= 10;
    }

    int idTwo = cNumber;
    int idOne = cNumber / 10; // Get only first digit to check whether is Visa

    // Find flag
    if ((idTwo == 34 || idTwo == 37) && len == 15 && checkSum)
    {
        printf("AMEX\n");
    }
    else if ((idTwo == 51 || idTwo == 52 || idTwo == 53 || idTwo == 54 || idTwo == 55) && len == 16 && checkSum)
    {
        printf("MASTERCARD\n");
    }
    else if (idOne == 4 && (len == 13 || len == 16) && checkSum)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

long getCardNumber(void)
{
    long cNumber;
    do
    {
        cNumber = get_long("Number: ");
    }
    while (cNumber <= 0);
    return cNumber;
}

int main(void)
{
    long cardNumber = getCardNumber();
    int len = length(cardNumber);
    findFlag(cardNumber, len);
}
