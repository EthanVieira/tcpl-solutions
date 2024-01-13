#include <stdio.h>
#include <string.h>

int strrindex(char source[], char searchfor[]);

int main()
{
    char pattern[] = "ould";
    char testString1[] = "shoulda coulda woulda";
    char testString2[] = "no sir";
    char testString3[] = "ould i do declare ould";

    printf("%d\n", strrindex(testString1, pattern));
    printf("%d\n", strrindex(testString2, pattern));
    printf("%d\n", strrindex(testString3, pattern));
}

int strrindex(char s[], char t[])
{
    int i, j, k;

    for (i = strlen(s); i > 0; i--)
    {
        for (j = i, k = strlen(t); k > 0 && s[j-1] == t[k-1]; j--, k--)
        ;
        if (k == 0)
        {
            return i - strlen(t);
        }
    }
    return -1;
}