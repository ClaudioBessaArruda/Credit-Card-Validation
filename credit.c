#include <stdio.h>
#include <cs50.h>

int main(void)
{

    long cardNumber = get_long("What is your credit card number?\n");
    int sumA = 0; // odd digits
    int sumB = 0; // even digits
    int sumC = 0;
    bool check = false; // not sure if booleans work within the cs50 header
    long cardNumber1 = cardNumber;
    int digits = 0; // number of digits


    while (cardNumber1 != 0)  // counts the number of digits of cardNumber
    {
        cardNumber1 /= 10;
        digits++;
    }

    cardNumber1 = cardNumber;


    for (int i = 1; i <= digits ; i++)  // checksum formula
    {
        if (i % 2 != 0)
        {
            int sumA1 = 0;
            sumA1 = cardNumber1 % 10;
            cardNumber1 /= 10;
            sumA += sumA1;
        }
        if (i % 2 == 0)
        {
            int sumB1 = 0;
            sumB1 = cardNumber1 % 10;
            cardNumber1 /= 10;
            sumB1 *= 2;
            if (sumB1 >= 10)
            {
                sumB1 = (sumB1 - 10) + 1;
            }
            sumB += sumB1;
        }
    }

    cardNumber1 = cardNumber;
    sumC = (sumB + sumA);

    if (sumC % 10 == 0)  // returns result of the checksum
    {
        check = true;
    }
    else
    {
        check = false;
    }

// checking if it is a valid card and what company is it from

    if (digits == 15 && check == true) // American Express
    {
        cardNumber1 /= 10000000;
        cardNumber1 /= 1000000;
        if (cardNumber1 == 34 || cardNumber1 == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (digits == 13 && check == true) // Visa 13-digit card
    {
        cardNumber1 /= 1000000000000;
        if (cardNumber1 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (digits == 16 && check == true) // Mastercard or Visa 16-digit card
    {
        cardNumber1 /= 100000000000000;
        if (cardNumber1 == 51 || cardNumber1 == 52 || cardNumber1 == 53 || cardNumber1 == 54 || cardNumber1 == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (cardNumber1 >= 40 && cardNumber1 < 50)
        {
            printf("VISA\n");
        }
        else if (cardNumber1 != 4)
        {
            printf("INVALID\n");
        }
    }
    else  // fake or non-card numbers
    {
        if (check == false)
        {
            printf("INVALID\n");
        }
        else if (digits != 15 && digits != 13 && digits != 16)
        {
            printf("INVALID\n");
        }
    }
