#include <stdio.h>
#include <stdbool.h>

main()
{
    int c;
    bool insideWord = false;

    while ((c = getchar()) != EOF)
    {
        if (c != ' ' && c != '\t' && c != '\n')
        {
            if (!insideWord)
                insideWord = true;
            putchar(c);
        }
        else if (insideWord)
        {
            insideWord = false;
            putchar('\n');
        }
    }
}