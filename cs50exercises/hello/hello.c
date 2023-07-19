#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Gets users input
    string name = get_string("Enter name: ");
    //Prints users input
    printf("Hello, %s!\n", name);
}