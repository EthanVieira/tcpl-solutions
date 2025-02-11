#include <stdio.h>

#define MAXLINE 1000

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

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0)
    {
        printf("%s", line);
    }

    return 0;
}
