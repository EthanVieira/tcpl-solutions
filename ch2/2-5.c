#include <stdio.h>
#include <stdbool.h>

int any(char s1[], char s2[]);
bool inString(char s[], int c);

int main()
{
    printf("%d\n", any("This is sentence uno.", "seu"));
    return 0;
}

// find first occurrence of s2 chars in s1
int any(char s1[], char s2[])
{
    for (int i = 0; s1[i] != '\0'; i++)
    {
        if (inString(s2, s1[i]))
        {
            return i;
        }
    }
    return -1;
}

bool inString(char s[], int c)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == c)
        {
            return true;
        }
    }

    return false;
}