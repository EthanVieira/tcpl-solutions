#include <stdio.h>

int strend(char *s, char *t)
{
    const char *beginningOfT = t;
    const char *beginningOfS = s;

    // loop on s++ followed by a single s-- instead of simply looping on ++s
    // because this approach will correctly handle empty strings
    while (*s++)
        ;

    while (*t++)
        ;

    s--;
    t--;

    for (; *s == *t; --s, --t)
    {
        if (s == beginningOfS)
        {
            return t == beginningOfT;
        }
    }

    return ++t == beginningOfT;
}

void testStrEnd(char *s, char *t)
{
    printf("'%s' ends '%s'?: %d\n", t, s, strend(s, t));
}

int main()
{
    char s1[32] = "Hello";
    char s2[32] = " World!";
    char s3[32] = "Hello World!";
    char s4[32] = "";
    char s5[32] = "H!";

    testStrEnd(s1, s1);
    testStrEnd(s1, s2);
    testStrEnd(s1, s3);
    testStrEnd(s2, s1);
    testStrEnd(s3, s1);
    testStrEnd(s3, s2);
    testStrEnd(s4, s1);
    testStrEnd(s1, s4);
    testStrEnd(s4, s4);
    testStrEnd(s3, s5);

    return 0;
}
