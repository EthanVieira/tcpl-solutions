#include <ctype.h>
#include <stdio.h>
#include <math.h>

int getch(void);
void ungetch(int);

int getfloat(float *pn)
{
    int c, c2, sign;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
    {
        c2 = c;
        c = getch();
        if (!isdigit(c) && c != '.')
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

    if (c == '.')
    {
        c = getch();
        for (int i = 1; isdigit(c); c = getch(), i++)
        {
            *pn += (c - '0') / (pow(10, i));
        }

        // treat a single '.' as 0.0, so don't put back on input if there is no trailing/leading number
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
    int i = 0;
    float f = 0;
    i = getfloat(&f);
    printf("%d\n", i);
    printf("%f\n", f);

    return 0;
}
