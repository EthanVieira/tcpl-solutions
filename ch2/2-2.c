#include <stdio.h>


int main()
{
    int lim = 1000;
    char s[lim];
    char c;

    for (int i=0; i < lim-1; ++i)
    {
        if ((c=getchar()) != '\n')
        {
            if (c != EOF)
            {
                s[i] = c;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }

    return 0;
}
