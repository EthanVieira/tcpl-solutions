#include <stdio.h>
#include <string.h>

int strend(char *s, char *t)
{
    char *beginningOfT = t;
    char *beginningOfS = s;

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

int main()
{
    char s1[32] = "Hello";
    char s2[32] = " World!";
    char s3[32] = "Hello World!";
    char s4[32] = "";
    char s5[32] = "H!";

    printf("'%s' ends '%s'?: %d\n", s1, s1, strend(s1, s1));
    printf("'%s' ends '%s'?: %d\n", s2, s1, strend(s1, s2));
    printf("'%s' ends '%s'?: %d\n", s3, s1, strend(s1, s3));
    printf("'%s' ends '%s'?: %d\n", s1, s2, strend(s2, s1));
    printf("'%s' ends '%s'?: %d\n", s3, s2, strend(s2, s3));
    printf("'%s' ends '%s'?: %d\n", s1, s3, strend(s3, s1));
    printf("'%s' ends '%s'?: %d\n", s2, s3, strend(s3, s2));
    printf("'%s' ends '%s'?: %d\n", s1, s4, strend(s4, s1));
    printf("'%s' ends '%s'?: %d\n", s4, s1, strend(s1, s4));
    printf("'%s' ends '%s'?: %d\n", s4, s4, strend(s4, s4));
    printf("'%s' ends '%s'?: %d\n", s5, s3, strend(s3, s5));

    return 0;
}
