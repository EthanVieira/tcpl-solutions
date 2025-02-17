#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 500
#define MAXLEN 100

int getLine(char *s, int lim)
{
    int limit = lim - 1;
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    {
        if (i < limit)
        {
            *s++ = c;
        }
    }

    if (c == '\n')
    {
        *s++ = c;
        if (i >= limit)
        {
            i++;
        }
    }
    *s = '\0';

    return i;
}

int readLines(char *linePtr[], int maxlines, char *strArray)
{
    int len;
    char line[MAXLEN];

    int nlines = 0;
    while ((len = getLine(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines)
        {
            nlines = -1;
            break;
        }
        else
        {
            line[len] = '\0';
            strcpy(strArray, line);
            linePtr[nlines++] = strArray;
            strArray += len + 1;
        }
    }
    return nlines;
}

void writeLines(char *linePtr[], int nlines)
{
    for (int i = 0; i < nlines; i++)
    {
        printf("%s\n", linePtr[i]);
    }
}

void swap(char *v[], int i, int j)
{
    char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

char *stringToLower(const char *s)
{
    int len = strlen(s);
    char *lowerStr = malloc(len + 1);
    for (int i = 0; s[i]; i++)
    {
        lowerStr[i] = tolower(s[i]);
    }
    return lowerStr;
}

void qsort_(char *v[], int left, int right, int (*comp)(void *, void *), int reverse, int caseSensitive, int column)
{
    if (left < right)
    {
        swap(v, left, (left + right) / 2);
        int last = left;
        for (int i = left + 1; i <= right; i++)
        {
            char *l;
            char *r;
            char *cl;
            char *cr;
            // dangerously assumes the columns exist
            if (column > 0)
            {
                char i_copy[MAXLEN];
                char i_left[MAXLEN];
                strcpy(i_copy, v[i]);
                strcpy(i_left, v[left]);
                cl = strtok(i_copy, ",");

                for (int j = 1; j < column; j++)
                {
                    cl = strtok(NULL, ",");
                }

                cr = strtok(i_left, ",");

                for (int j = 1; j < column; j++)
                {
                    cr = strtok(NULL, ",");
                }
            }
            else
            {
                cl = v[i];
                cr = v[i];
            }

            l = caseSensitive ? cl : stringToLower(cl);
            r = caseSensitive ? cr : stringToLower(cr);

            int result = (*comp)(l, r);

            if (caseSensitive)
            {
                free(l);
                free(r);
            }

            if (reverse)
            {
                if (result > 0)
                {
                    swap(v, ++last, i);
                }
            }
            else if (result < 0)
            {
                swap(v, ++last, i);
            }
        }

        swap(v, left, last);
        qsort_(v, left, last - 1, comp, reverse, caseSensitive, column);
        qsort_(v, last + 1, right, comp, reverse, caseSensitive, column);
    }
}

int numcmp(const char *s1, const char *s2)
{
    double v1 = atof(s1);
    double v2 = atof(s2);
    if (v1 < v2)
    {
        return -1;
    }
    else if (v1 > v2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int dirOrderCmp(const char *s1, const char *s2)
{
    char c1, c2;

    do
    {
        c1 = *s1++;
        c2 = *s2++;
        while (!isalnum(c1) && !iswspace(c1) && c1 != '\0')
        {
            c1 = *s1++;
        }

        while (!isalnum(c2) && !iswspace(c2) && c2 != '\0')
        {
            c2 = *s2++;
        }

        if (c1 == '\0')
        {
            return c1 - c2;
        }
    } while (c1 == c2);

    return c1 - c2;
}

int main(int argc, char *argv[])
{
    int returnCode = 0;
    int numeric = 0;
    int reverse = 0;
    int caseSensitive = 1;
    int dirOrder = 0;
    int column = -1;

    int nlines;
    char *linePtr[MAXLINES];
    char strArray[MAXLINES * MAXLEN];

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-n") == 0)
        {
            numeric = 1;
        }
        else if (strcmp(argv[i], "-r") == 0)
        {
            reverse = 1;
        }
        else if (strcmp(argv[i], "-f") == 0)
        {
            caseSensitive = 0;
        }
        else if (strcmp(argv[i], "-d") == 0)
        {
            dirOrder = 1;
        }
        else if (strncmp("-c", argv[i], strlen("-c")) == 0)
        {
            column = atoi(argv[i] + 2);
        }
    }

    if ((nlines = readLines(linePtr, MAXLINES, strArray)) >= 0)
    {
        qsort_(linePtr, 0, nlines - 1, (int (*)(void *, void *))(dirOrder ? dirOrderCmp : (numeric ? numcmp : strcmp)),
               reverse,
               caseSensitive,
               column);
        writeLines(linePtr, nlines);
    }
    else
    {
        printf("error: input too big to sort\n");
        returnCode = 1;
    }

    return returnCode;
}