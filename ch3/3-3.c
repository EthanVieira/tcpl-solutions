#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[]);

int main()
{
    char testStr1[] = "-aa-f0-9jkl;eej t-Xp-Q-";
    char resultStr1[100];
    expand(testStr1, resultStr1);
    printf("%s\n", testStr1);
    printf("%s\n", resultStr1);
    return 0;
}

// range is A-Z, a-z or 0-9
// assume s2 can hold expanded s1
// for simplicity, assume '-' will only be used as leading/trailing char or to create a legitimate range
void expand(char s1[], char s2[])
{
    int j = 0;
    for (int i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] == '-' && i != 0 && s1[i+1] != '\0')
        {
            // assume it is a valid range
            // any invalid ranges will just remove the '-' char
            // e.g. p-Q -> pQ
            for (char c = s1[i-1] + 1; c < s1[i+1]; c++)
            {
                s2[j++] = c;
            }
        }
        else
        {
            s2[j++] = s1[i];
        }
    }

    s2[j] = '\0';
}
