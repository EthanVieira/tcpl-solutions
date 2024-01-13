#include <stdio.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 15 // limit word length to 15 characters

main()
{
    int wordLengths[MAX_WORD_LENGTH];
    int c, currentLength;
    bool insideWord = false;

    for (int i = 0; i < MAX_WORD_LENGTH; i++)
    {
        wordLengths[i] = 0;
    }

    currentLength = 0;

    while ((c = getchar()) != EOF)
    {
        if (c != ' ' && c != '\t' && c != '\n')
        {
            if (!insideWord)
                insideWord = true;
            ++currentLength;
        }
        else if (insideWord)
        {
            insideWord = false;
            ++wordLengths[currentLength - 1];
            currentLength = 0;
        }
    }
    printf("-------------------------------------\n");
    for (int i = 0; i < MAX_WORD_LENGTH; i++)
    {
        printf("%2d ", i);
        for (int j = 0; j < wordLengths[i]; j++)
        {
            putchar('|');
        }
        putchar('\n');
    }
    printf("-------------------------------------\n");
}