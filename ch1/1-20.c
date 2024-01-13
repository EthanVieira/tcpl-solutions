#include <stdio.h>

#define TABSTOP 4


int main()
{
    int c;
    int currentCharIndex;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            for (int i = 0; i < TABSTOP - (currentCharIndex % TABSTOP); i++)
            {
                putchar(' ');
                currentCharIndex++;
            }
        }
        else if (c == '\n')
        {
            putchar(c);
            currentCharIndex = 0;
        }
        else
        {
            putchar(c);
            currentCharIndex++;
        }
    }

    return 0;
}

