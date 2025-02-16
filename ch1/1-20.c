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
            const int spacesToAdd = TABSTOP - (currentCharIndex % TABSTOP);
            for (int i = 0; i < spacesToAdd; i++)
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
