#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DEFAULT_TAB_STOP 4

int detab(int tabStops[], int numOfTabStops)
{
    int c;
    int currentCharIndex = 0;
    int tabStopIndex = 0;
    int currentTabStop = 0;

    while ((c = getchar()) != EOF)
    {
        if (currentCharIndex >= currentTabStop)
        {
            currentTabStop += tabStopIndex < numOfTabStops ? tabStops[tabStopIndex++] : DEFAULT_TAB_STOP;
        }

        if (c == '\t')
        {
            const int spacesToAdd = currentTabStop - (currentCharIndex % currentTabStop);
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
            tabStopIndex = 0;
            currentTabStop = 0;
        }
        else
        {
            putchar(c);
            currentCharIndex++;
        }
    }

    return 0;
}

int entab(int tabStops[], int numOfTabStops)
{
    int c;
    int currentCharIndex = 0;
    int tabStopIndex = 0;
    int currentTabStop = 0;
    int currentNumSpaces = 0;
    bool inSpace = false;

    while ((c = getchar()) != EOF)
    {
        if (currentCharIndex >= currentTabStop)
        {
            currentTabStop += tabStopIndex < numOfTabStops ? tabStops[tabStopIndex++] : DEFAULT_TAB_STOP;
        }

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
                currentNumSpaces += currentTabStop - (currentCharIndex % currentTabStop);
            }
        }
        else
        {
            if (inSpace)
            {
                inSpace = false;
                for (int i = 0; i < (currentNumSpaces / currentTabStop); i++)
                {
                    putchar('\t');
                }

                for (int i = 0; i < (currentNumSpaces % currentTabStop); i++)
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
                tabStopIndex = 0;
                currentTabStop = 0;
            }
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
    int size = argc - 1;
    int tabStops[size];

    for (int i = 0; i < size; i++)
    {
        tabStops[i] = atoi(argv[i + 1]);
    }

    detab(tabStops, size);
    // entab(tabStops, size);

    return 0;
}
