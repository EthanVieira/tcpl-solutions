#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[], int lim);
void reverse(char s[]);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0)
    {
        reverse(line);
        printf("%s\n", line);
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

void reverse(char s[])
{
    int length;
    char temp;

    for (length = 0; s[length] != '\0'; length++)
        ;

    for (int i = length; i > length / 2; i--)
    {
        temp = s[length - i];
        s[length - i] = s[i - 1];
        s[i - 1] = temp;
    }
}
