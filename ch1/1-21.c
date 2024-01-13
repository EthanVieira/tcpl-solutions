#include <stdio.h>
#include <stdbool.h>

#define TABSTOP 4


int main()
{
    int c;
    int currentNumSpaces = 0;
    int currentCharIndex = 0;
    bool inSpace = false;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t')
        {
            currentCharIndex += 1;

            if (!inSpace)
            {
                inSpace = true;
            }

            if (c == ' ')
            {
                currentNumSpaces++;
            }
            else
            {
                currentNumSpaces += TABSTOP - (currentCharIndex % TABSTOP);
            }

        }
        else
        {
            if (inSpace)
            {
                inSpace = false;
                for (int i = 0; i < (currentNumSpaces / TABSTOP); i++)
                {
                    putchar('\t');
                }

                for (int i = 0; i < (currentNumSpaces % TABSTOP); i++)
                {
                    putchar(' ');
                }
            }

            putchar(c);
            currentCharIndex += 1;
            currentNumSpaces = 0;

            if (c == '\n')
            {
                currentCharIndex = 0;
            }
        }
    }

    return 0;
}

