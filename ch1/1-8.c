#include <stdio.h>

main()
{
    int c;
    int nl = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
            ++nl;
    }
    printf("%d", nl);
}