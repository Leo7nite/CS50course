#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int CountLetters(string text);
int CountWords(string text);
int CountSentences(string text);

int main(void)
{
    string text = get_string("Enter text: ");
    int letterCount = CountLetters(text);
    int wordCount = CountWords(text);
    int senCount = CountSentences(text);
    /*printf("%i letters\n", letterCount);
    printf("%i words\n", wordCount);
    printf("%i sentences\n", senCount);*/

    //index = 0.0588 * L - 0.296 * S - 15.8
    float avgLet = (float)letterCount/(float)wordCount * 100;
    float avgSen = (float)senCount/(float)wordCount * 100.0;
    float index = (0.0588 * avgLet) - (0.296 * avgSen) - 15.8;
    if(index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", round(index));
    }

}
int CountSentences(string text)
{
    int count = 0;
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
int CountWords(string text)
{
    int count = 0;
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] == ' ')
        {
            count++;
        }
    }
    return count+1;
}

int CountLetters(string text)
{
    int count = 0;
    char arr[26] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char s[strlen(text)];
    for(int i = 0; i < strlen(text); i++)
    {
        s[i] = tolower(text[i]);
    }
    for(int i = 0; i < sizeof(s); i++)
    {
        for(int j = 0; j < sizeof(arr); j++)
        {
            if(s[i] == arr[j])
            {
                count++;
                break;
            }
        }
    }
    return count;
}