#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 500
#define MAXLEN 100

int getLine(char *s, int lim)
{
    int limit = lim - 1;
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    {
        if (i < limit)
        {
            *s++ = c;
        }
    }

    if (c == '\n')
    {
        *s++ = c;
        if (i >= limit)
        {
            i++;
        }
    }
    *s = '\0';

    return i;
}

int readLines(char *linePtr[], int maxlines, char *strArray)
{
    int len;
    char line[MAXLEN];

    int nlines = 0;
    while ((len = getLine(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines)
        {
            nlines = -1;
            break;
        }
        else
        {
            line[len] = '\0';
            strcpy(strArray, line);
            linePtr[nlines++] = strArray;
            strArray += len + 1;
        }
    }
    return nlines;
}

int main(int argc, char *argv[])
{
    int n = 10;
    if (argc == 2 && argv[1][0] == '-')
    {
        n = atoi(argv[1] + 1);
    }

    int nLines;
    char *linePtr[MAXLINES];
    char strArray[MAXLINES * MAXLEN];

    if ((nLines = readLines(linePtr, MAXLINES, strArray)) >= 0)
    {
        int numToPrint = 0;

        if (n >= nLines)
        {
            numToPrint = nLines;
        }
        else
        {
            numToPrint = n > 0 ? n : 0;
        }

        for (int i = nLines - numToPrint; i < nLines; i++)
        {
            printf("%s\n", linePtr[i]);
        }
    }

    return 0;
}