#include <stdio.h>

void escape(char s[], char t[]);
void reverseEscape(char s[], char t[]);

int main()
{
    char testStr[] = "test \n   \\n \\t    \t test";
    char resultStr1[100];
    char resultStr2[100];
    escape(resultStr1, testStr);
    reverseEscape(resultStr2, testStr);
    printf("%s\n", testStr);
    printf("%s\n", resultStr1);
    printf("%s\n", resultStr2);
    return 0;
}

// assume len(s) is large enough to hold the new string
// only converts tabs and newlines
void escape(char s[], char t[])
{
    int j = 0;
    for (int i = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }

    s[j] = '\0';
}

// assume len(s) is large enough to hold the new string
// only converts tabs and newlines
void reverseEscape(char s[], char t[])
{
    int j = 0;
    for (int i = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
            case '\\':
                if (t[i + 1] != '\0')
                {
                    switch (t[i + 1])
                    {
                        case 'n':
                            i++;
                            s[j++] = '\n';
                            break;
                        case 't':
                            i++;
                            s[j++] = '\t';
                            break;
                        default:
                            s[j++] = '\\';
                    }
                }
                else
                {
                    s[j++] = '\\';
                }
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }

    s[j] = '\0';
}