#include <stdio.h>
#include <stdbool.h>

void squeeze(char s1[], char s2[]);
bool inString(char s[], int c);

int main()
{
    char s[] = "This is sentence uno.";
    squeeze(s, "seu");

    printf("%s\n", s);
    return 0;
}

// delete all chars in s2 from s1
void squeeze(char s1[], char s2[])
{
    int i, j;

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        if (!inString(s2, s1[i]))
        {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
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