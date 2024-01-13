#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000
#define LINE_CUTOFF 15

int getLine(char s[], int lim);

int main()
{
    int len;
    int tempLen;
    char line[MAX_LINE];
    char tempLine[LINE_CUTOFF + 1];

    while ((len = getLine(line, MAX_LINE)) > 0)
    {
        int currentCharIndex = 0;
        while (len > LINE_CUTOFF)
        {
            tempLen = LINE_CUTOFF + 1;
            strncpy(tempLine, line + currentCharIndex, LINE_CUTOFF);
            tempLine[LINE_CUTOFF] = '\0';

            // find last blank char
            while (tempLen > 0 && (tempLine[tempLen - 1] != ' ' && tempLine[tempLen - 1] != '\t'))
            {
                tempLine[--tempLen] = '\0';
            }

            // handle full line of non blanks by connecting with a dash
            if (tempLen == 0)
            {
                strncpy(tempLine, line + currentCharIndex, LINE_CUTOFF - 1);
                tempLine[LINE_CUTOFF - 1] = '-';
                tempLine[LINE_CUTOFF] = '\0';
                len -= (LINE_CUTOFF - 1);
                currentCharIndex += strlen(tempLine) - 1;
            }
            else
            {
                len -= strlen(tempLine);
                currentCharIndex += strlen(tempLine);
            }

            printf("%s\n", tempLine);
        }

        if (len > 0)
        {
            strncpy(tempLine, line + currentCharIndex, LINE_CUTOFF);
            printf("%s\n", tempLine);
        }
    }

    return 0;
}

int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    {
        if (i < (lim - 1))
        {
            s[i] = c;
        }
    }

    if (c == '\n')
    {
        if (i < (lim - 1))
        {
            s[i] = c;
            s[++i] = '\0';
        }
        else
        {
            s[lim - 1] = c;
            s[lim] = '\0';
            i++;
        }
    }
    else if (i < (lim - 1))
    {
        s[i] = '\0';
    }
    else
    {
        s[lim - 1] = '\0';
    }

    return i;
}