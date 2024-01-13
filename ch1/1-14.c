#include <stdio.h>
#include <stdbool.h>

#define ASCII_TABLE_LENGTH 128 // Unextended version

main()
{
    int charFrequencies[ASCII_TABLE_LENGTH];
    int c, currentLength;

    for (int i = 0; i < ASCII_TABLE_LENGTH; i++)
    {
        charFrequencies[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        ++charFrequencies[c];
    }

    printf("-------------------------------------\n");
    for (int i = 1; i < ASCII_TABLE_LENGTH; i++)
    {
        if (charFrequencies[i] != 0)
        {
            if (i == '\t')
            {
                printf("\\t ");
            }
            else if (i == '\b')
            {
                printf("\\b ");
            }
            else if (i == '\\')
            {
                printf("\\\\ ");
            }
            else if (i == '\n')
            {
                printf("\\n ");
            }
            else
            {
                printf("%c ", i);
            }
            for (int j = 0; j < charFrequencies[i]; j++)
            {
                putchar('|');
            }
            putchar('\n');
        }
    }
    printf("-------------------------------------\n");
}