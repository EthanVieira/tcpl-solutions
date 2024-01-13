#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

int getLine(char s[], int lim);

// for simplicity I will only check single lines
// for an entire file, one would rely on getchar and preserve
// information across lines
int main()
{
    int len;
    int currentCharIndex;
    char line[MAX_LINE];

    while ((len = getLine(line, MAX_LINE)) > 0)
    {
        currentCharIndex = 0;
        while (currentCharIndex < len - 1)
        {
            if (line[currentCharIndex] == '/')
            {
                if (line[currentCharIndex + 1] == '/')
                {
                    // remove the remaining characters in the line (don't print)
                    break;
                }
                else if (line[currentCharIndex + 1] == '*')
                {
                    // assume that the comment is valid and ends on the same line
                    currentCharIndex += 2;
                    while (line[currentCharIndex] != '*' && line[currentCharIndex + 1] != '/')
                    {
                        currentCharIndex++;
                    }

                    currentCharIndex += 2;
                }
            }
            else if (line[currentCharIndex] == '\\')
            {
                // don't consider the next char
                putchar(line[currentCharIndex]);
                putchar(line[++currentCharIndex]);
            }
            else if (line[currentCharIndex] == '"')
            {
                putchar(line[currentCharIndex]);
                while (line[++currentCharIndex] != '"')
                {
                    putchar(line[currentCharIndex]);
                }
                putchar(line[currentCharIndex++]);
            }
            else if (line[currentCharIndex] == '\'')
            {
                putchar(line[currentCharIndex]);
                while (line[++currentCharIndex] != '\'')
                {
                    putchar(line[currentCharIndex]);
                }
                putchar(line[currentCharIndex++]);
            }
            else
            {
                putchar(line[currentCharIndex++]);
            }
        }
        putchar('\n');
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