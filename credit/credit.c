#include <stdio.h>
#include <cs50.h>

int one_digit(long num);
long delete_last_digit(long num);
string type_of_card(long num);
bool luhn_algorithm(long credit_card);

int main(void)
{
    // Prompt for credit card number
    long card_num = get_long("Put your credit card number here: ");

    // Checking the card with Luhn’s algorithm
    if (luhn_algorithm(card_num))
    {
        // Getting for type of card
        printf("%s", type_of_card(card_num));
    }
    else
    {
        printf("INVALID\n");
    }
}

// Getting last digit of the card
int one_digit(long num)
{
    return num % 10;
}

// Delete last diget of the card
long delete_last_digit(long num)
{
    return num / 10;
}

// Checking for type of card
string type_of_card(long num)
{
    if ((num >= 340000000000000 && num < 350000000000000) || (num >= 370000000000000 && num < 380000000000000))
    {
        return "AMEX\n";
    }
    if (num >= 5100000000000000 && num < 5600000000000000)
    {
        return "MASTERCARD\n";
    }
    if ((num >= 4000000000000000 && num < 5000000000000000) || (num >= 4000000000000 && num < 5000000000000))
    {
        return "VISA\n";
    }
    return "VALID (OTHER CARD)\n";
}

// Luhn’s algorithm implimentation
bool luhn_algorithm(long credit_card)
{
    int sum = 0;
    int index = 1;

    while (credit_card > 0)
    {
        // Getting last digit of the card
        int num = one_digit(credit_card);
        // Delete last diget of the card
        credit_card = delete_last_digit(credit_card);

        if (index % 2 == 0)
        {
            // Multipling every other digit by 2
            int sum_of_num = num * 2;
            // Adding products’ digits together
            sum += one_digit(sum_of_num) + delete_last_digit(sum_of_num);
        }
        else
        {
            // Adding rest digits to the sum
            sum += num;
        }
        index++;
    }

    // Checking total’s last digit is 0
    if (one_digit(sum) == 0)
    {
        return true;
    }
    return false;
}
