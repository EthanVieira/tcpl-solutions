#include <stdio.h>

#define MAXLINE 1000
#define PRINTING_MINIMUM 80

int getLine(char s[], int lim);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (len > PRINTING_MINIMUM)
        {
            printf("%s", line);
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
