#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int lim);
void copy(char to[], char from[]);

int main()
{
    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
    {
        printf("Line length: %d\n", max);
        printf("%s", longest);
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

void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
}