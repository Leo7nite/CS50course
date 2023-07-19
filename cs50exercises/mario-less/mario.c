#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Enter height of pyramid:");
    }
    while(height < 1 || height > 8);

    for(int i=0; i<height; i++)
    {
        for(int k=height-1; k>i; k--)
        {
            printf(" ");
        }
        for(int j=0; j<=i; j++)
        {
            printf("#");

        }
        printf("  ");
        for(int l=0; l<=i; l++)
        {
            printf("#");
        }
        
        printf("\n");


    }
}