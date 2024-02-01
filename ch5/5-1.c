#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

int getint(int *pn)
{
    int c, c2, sign;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
    {
        c2 = c;
        c = getch();
        if (!isdigit(c))
        {
            ungetch(c);
            ungetch(c2);
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }

    *pn *= sign;

    if (c != EOF)
    {
        ungetch(c);
    }

    return c;
}

int main()
{
    int i1, i2 = 0;
    i1 = getint(&i2);
    printf("%d\n", i1);
    printf("%d\n", i2);

    return 0;
}
