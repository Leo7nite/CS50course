#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if(score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if(score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    //AFTER REALIZING THERE IS AN ARRAY AT THE TOP :) XDD
    char s[strlen(word)];
    for(int i=0; i<strlen(word); i++)
    {
        s[i] = tolower(word[i]);
    }

    int score = 0;
    char arr[26] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    //iterate through the string length
    for(int i=0; i<strlen(word); i++)
    {
        //iterate through an array of letter characters
        for(int j = 0; j<sizeof(arr); j++)
        {
            //if current letter of i=0 (letter B) for example is the same as j=1 (letter B) then add score of a point in position of POINTS[1] because it has the same position as in array of letters
            if(s[i] == arr[j])
            {
                score+= POINTS[j];
                //if all letters are found break and restart the loop
                break;
            }
        }

    }
    return score;
    /*char s[strlen(word)];
    for(int i = 0; i<strlen(word); i++)
    {
        s[i] += tolower(word[i]);

    char points4[4] = {'f','h','v','y'};
    int score = 0;
    for(int i = 0; i < strlen(word); i++)
    {
        if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'l' || word[i] == 'o' || word[i] == 'r' || word[i] == 's' || word[i] == 't' || word[i] == 'u')
        {
            score += 1;
        }
        else if(word[i] == 'd' || word[i] =='g')
        {
            score += 2;
        }
        else if(word[i] == 'b' || word[i] == 'c' || word[i] == 'm' || word[i] == 'p')
        {
            score +=3;
        }
        for(int j = 0; j < sizeof(points4); j++)
        {
            if(word[i] == points4[j])
            {
                score +=4;
            }
        }
        if(word[i] == 'k')
        {
            score += 5;
        }
        else if(word[i] == 'j' || word[i] =='x')
        {
            score += 8;
        }
        else if(word[i] == 'q' || word[i] == 'z')
        {
            score += 10;
        }
        else
        {
            score +=0;
        }
    }*/

    // TODO: Compute and return score for string

}
