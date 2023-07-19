#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char swapLetters(char c, string key);
bool Usage(int argc, string s);

int main(int argc, string argv[])
{
    bool itsfalse = Usage(argc,argv[1]);
    if(itsfalse == 1)
    {
        return 1;
    }
    string key = argv[1];
    string text = get_string("plaintext:  ");
    int plainLength = strlen(text);
    char arr[plainLength];
    printf("ciphertext: ");
    //forloop to add together all the characters i swap
    //function to swap characters based on key, (send text[i] character to function and swap it and bring it back and add it to ciphertext array also send key)
    for(int i = 0; i < plainLength; i++)
    {
        arr[i] = swapLetters(text[i], key);
        printf("%c",arr[i]);
    }
    printf("\n");

    //printf("%s\n",argv[1]);
}

bool Usage(int argc, string s)
{
    if(argc < 2 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int stringLength = strlen(s);
    if(stringLength != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    char arr[stringLength];
    for(int i = 0; i< stringLength; i++)
    {
        if(s[i] >= 48 && s[i]<=57)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        arr[i] = tolower(s[i]);
    }
    for(int i = 0; i < stringLength-1; i++)
    {
        for(int j = i+1; j < stringLength; j++)
        {
            if(arr[i] == arr[j])
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }
    return 0;
}

char swapLetters(char c, string key)
{
    int keyLength = strlen(key);
    if(c >= 'a' && c <= 'z')
    {
        int subtract = (char)c - 97;
        for(int i = 0; i < keyLength; i++)
        {
            if(i == subtract)
            {
                char converted = tolower(key[i]);
                return converted;
            }
        }
    }
    else if(c >= 'A' && c <= 'Z')
    {
        int subtract = (char)c - 65;
        for(int i = 0; i < keyLength; i++)
        {
            if(i == subtract)
            {
                char converted = toupper(key[i]);
                return converted;
            }
        }
    }
    return c;

}
/*:( handles invalid characters in key
    timed out while waiting for program to exit
:( handles duplicate characters in uppercase key
    timed out while waiting for program to exit
:( handles duplicate characters in lowercase key
    timed out while waiting for program to exit
:( handles multiple duplicate characters in key
    timed out while waiting for program to exit*/