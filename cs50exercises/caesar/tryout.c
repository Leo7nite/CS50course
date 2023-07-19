#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char rotate (char c, int key);

int main(int argc, string argv[])
{
    if (argc < 2 || argc > 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int length = strlen(argv[1]);
    string s = argv[1];
    char array[length];
    for(int i = 0; i < length; i++)
    {
        if(isdigit(s[i]))
        {
            array[i] = s[i];
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int key = atoi(argv[1]);
    if(key == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //printf("%i\n",key);

    string text = get_string("text: ");
    char arr[strlen(text)];
    //printf("plaintext:  %s\n", text);
    printf("ciphertext: ");
    for(int i = 0; i < strlen(text); i++)
    {
        arr[i] = rotate(text[i],key);
        printf("%c",arr[i]);
    }
    printf("\n");

}
char rotate (char c, int key)
{
    if(c >= 'a' && c <= 'z')
    {
        int subtract = (char)c - 97;
        int result = (subtract + key) % 26;
        char converted = result + 97;
        return converted;
    }
    else if(c >= 'A' && c <= 'Z')
    {
        int subtract = (char)c - 65;
        int result = (subtract + key) % 26;
        char converted = result + 65;
        return converted;
    }
    else
    {
        return c;
    }
    return '0';
}