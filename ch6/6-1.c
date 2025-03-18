#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define BUFSIZE 100

int bufp = 0;
char buf[BUFSIZE];

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

int getword(char *word, int lim)
{
    char *w = word;
    int c;

    while (isspace(c = getch()) || c == '"' || c == '\'' || c == '/' || c == '*' || c == '#')
        ;

    if (c != EOF)
    {
        *w++ = c;
    }

    if (!isalpha(c) && *w != '_')
    {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++)
    {
        *w = getch();
        if (!isalnum(*w) && *w != '_')
        {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
}

int main()
{
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
    {
        printf("%s\n", word);
    }
}