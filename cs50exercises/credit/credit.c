#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool cardCheck(string card);
void AmericanExpress(bool isValid);
void Mastercard(bool isValid);
void Visa(bool isValid);

int main(void)
{

    /*vpišeš številko ki jo želiš met*/
    string card = get_string("Number to check: ");
    int length = strlen(card);


    if(length == 15)
    {
        if(card[0] == '3' && (card [1] == '4' || card [1] == '7'))
        {
            bool isValid = cardCheck(card);
            AmericanExpress(isValid);
        }
        else
        {
            printf("INVALID\n");
        }

    }

    else if(length == 16)
    {
        if(card[0] == '5' && (card[1] == '1' || card[1] == '2' || card[1] == '3' || card[1] == '4' || card[1] == '5'))
        {
            bool isValid = cardCheck(card);
            Mastercard(isValid);
        }
        else if(card[0] == '4')
        {
            bool isValid = cardCheck(card);
            Visa(isValid);

        }
        else
        {
            printf("INVALID\n");
        }
        //mastercard or visa
    }
    else if(length == 13 )
    {
        if(card[0] == '4')
        {
            bool isValid = cardCheck(card);
            Visa(isValid);
        }
    }
    else
    {
        printf("INVALID\n");
    }

}

void AmericanExpress(bool isValid)
{
    if(isValid == true)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
void Mastercard(bool isValid)
{
    if(isValid == true)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
void Visa(bool isValid)
{
    if(isValid == true)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

bool cardCheck(string card)
{
    long multiplied = 0;
    long sum = 0;
    //LOOP THROUGH STRING OF CARD NUMBER
    //for(int i=0; i<strlen(card); i++)
    //{
    //IF CARD STARTS WITH NUMBERS (CHAR) 3 AND 4
    //if(card[0] == '3' && card[1] == '4')
    //{
    //START ON STRING CHARACTER 0 AND INCREASE BY 2
    for(int k = strlen(card)-2; k >= 0; k -= 2)
    {
        //MULTIPLY EVERY OTHER(2nd) by 2, CHANGE CHARACTER by subtracting 48 because number 3 = 51 in ascii, 4 = 52 ... so 51-48 = 3, 52-48=4..and so on..
        //char num = card[k];
        //printf("%c",num);
        multiplied = (card[k]-48) * 2;
        //IF multiply number has an amount higher than 10 then use MOD% to split numbers like 12 into 1+2, by adding remainder + 1 (2+1)
        if(multiplied >= 10)
        {
            long remain = multiplied % 10;
            sum += remain + 1;
        }
        //else just add the multiplied number to sum variable
        else
        {
            sum += multiplied;
        }
    }
    //after that start with 1 and increase by 2, so you get every ODD number place in forloop, and add them to the sum.
    for(int j = strlen(card)-1; j >= 0; j -= 2)
    {
        sum += (card[j]-48);
    }
    //if sum is equal 20, then the american express card is valid
    if(sum % 10 == 0)
    {
        return true;
    }
    //otherwise print invalid
    else
    {
        return false;
    }
    return 0;
}
/*identifies 378282246310005 as AMEX
    expected "AMEX\n", not "Function Ameri..."
:( identifies 371449635398431 as AMEX
    expected "AMEX\n", not "Function Ameri..."
:( identifies 5555555555554444 as MASTERCARD
    expected "MASTERCARD\n", not "Function Maste..."
:( identifies 5105105105105100 as MASTERCARD
    expected "MASTERCARD\n", not "Function Maste..."
:( identifies 4111111111111111 as VISA
    expected "VISA\n", not "Visa\n"
:( identifies 4012888888881881 as VISA
    expected "VISA\n", not "Visa\n"
:( identifies 4222222222222 as VISA
    expected "VISA\n", not "Function VISA ..."
:( identifies 1234567890 as INVALID
    expected "INVALID\n", not "invalid \n"
:( identifies 369421438430814 as INVALID
    expected "INVALID\n", not "Invalid\n"
:( identifies 4062901840 as INVALID
    expected "INVALID\n", not "invalid \n"
:( identifies 5673598276138003 as INVALID
    expected "INVALID\n", not ""
:( identifies 4111111111111113 as INVALID
    expected "INVALID\n", not "Function VISA ..."
:( identifies 4222222222223 as INVALID
    expected "INVALID\n", not "Function VISA ..."*/