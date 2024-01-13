#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE 1000

int getLine(char s[], int lim);
void printErrorIfEOL(char c);

int parenthesesCheck = 0;
int bracketCheck = 0;
int braceCheck = 0;
bool inComment = false;
bool inString = false;
bool inChar = false;

// for simplicity I will only check single lines
// for an entire file, one would rely on getchar and preserve
// information across lines
int main()
{
    int len;
    int currentCharIndex;
    char line[MAX_LINE];
    extern int parenthesesCheck;
    extern int bracketCheck;
    extern int braceCheck;
    extern bool inComment;
    extern bool inString;
    extern bool inChar;

    while ((len = getLine(line, MAX_LINE)) > 0)
    {
        currentCharIndex = 0;

        parenthesesCheck = 0;
        bracketCheck = 0;
        braceCheck = 0;
        inComment = false;
        inString = false;
        inChar = false;

        while (currentCharIndex < len)
        {
            if (line[currentCharIndex] == '/')
            {
                if (line[currentCharIndex + 1] == '/')
                {
                    // don't need to check full line comments
                    printErrorIfEOL('\n');
                    break;
                }
                else if (line[currentCharIndex + 1] == '*')
                {
                    inComment = true;
                    // assume that the comment ends on the same line
                    currentCharIndex += 2;
                    while ((line[currentCharIndex] != '*' && line[currentCharIndex + 1] != '/') && line[currentCharIndex] != '\n')
                    {
                        // don't need to check when in comment
                        currentCharIndex++;
                    }

                    if (line[currentCharIndex] == '*' && line[currentCharIndex + 1] == '/')
                    {
                        inComment = false;
                    }

                    printErrorIfEOL(line[currentCharIndex]);
                    currentCharIndex += 2;
                }
            }
            else if (line[currentCharIndex] == '\\')
            {
                // recklessly handle this
                currentCharIndex += 2;
            }
            else if (line[currentCharIndex] == '"')
            {
                inString = true;
                while (line[++currentCharIndex] != '"' && line[currentCharIndex] != '\n')
                ;

                if (line[currentCharIndex] == '"')
                {
                    inString = false;
                }

                printErrorIfEOL(line[currentCharIndex++]);
            }
            else if (line[currentCharIndex] == '\'')
            {
                inChar = true;
                while (line[++currentCharIndex] != '\'' && line[currentCharIndex] != '\n')
                ;

                if (line[currentCharIndex] == '\'')
                {
                    inChar = false;
                }
                printErrorIfEOL(line[currentCharIndex++]);
            }
            else if (line[currentCharIndex] == '(')
            {
                parenthesesCheck++;
                currentCharIndex++;
            }
            else if (line[currentCharIndex] == ')')
            {
                parenthesesCheck--;
                currentCharIndex++;
            }
            else if (line[currentCharIndex] == '[')
            {
                bracketCheck++;
                currentCharIndex++;
            }
            else if (line[currentCharIndex] == ']')
            {
                bracketCheck--;
                currentCharIndex++;
            }
            else if (line[currentCharIndex] == '{')
            {
                braceCheck++;
                currentCharIndex++;
            }
            else if (line[currentCharIndex] == '}')
            {
                braceCheck--;
                currentCharIndex++;
            }
            else
            {
                printErrorIfEOL(line[currentCharIndex++]);
            }
        }
        putchar('\n');
    }


    return 0;
}

int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    {
        if (i < (lim - 1))
        {
            s[i] = c;
        }
    }

    if (c == '\n')
    {
        if (i < (lim - 1))
        {
            s[i] = c;
            s[++i] = '\0';
        }
        else
        {
            s[lim - 1] = c;
            s[lim] = '\0';
            i++;
        }
    }
    else if (i < (lim - 1))
    {
        s[i] = '\0';
    }
    else
    {
        s[lim - 1] = '\0';
    }

    return i;
}

void printErrorIfEOL(char c)
{
    extern int parenthesesCheck;
    extern int bracketCheck;
    extern int braceCheck;
    extern bool inComment;
    extern bool inString;
    extern bool inChar;

    if (c == '\n' || c == '\0')
    {
        if (parenthesesCheck != 0)
        {
            printf("Warning! Unbalanced parentheses.\n");
        }
        if (bracketCheck != 0)
        {
            printf("Warning! Unbalanced brackets.\n");
        }
        if (braceCheck != 0)
        {
            printf("Warning! Unbalanced braces.\n");
        }
        if (inComment)
        {
            printf("Warning! Missing an ending to a block comment.\n");
        }
        if (inString)
        {
            printf("Warning! Missing an ending quotation mark.\n");
        }
        if (inChar)
        {
            printf("Warning! Missing an ending single apostrophe.\n");
        }
    }
}