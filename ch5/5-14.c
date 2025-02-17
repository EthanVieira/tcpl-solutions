#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void swap(void *v[], int i, int j)
{
    char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort_(void *v[], int left, int right, int (*comp)(void *, void *), int reverse)
{
    if (left < right)
    {
        swap(v, left, (left + right) / 2);
        int last = left;
        for (int i = left + 1; i <= right; i++)
        {
            int result = (*comp)(v[i], v[left]);
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
        qsort_(v, left, last - 1, comp, reverse);
        qsort_(v, last + 1, right, comp, reverse);
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

int main(int argc, char *argv[])
{
    int returnCode = 0;
    int numeric = 0;
    int reverse = 0;

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
    }

    if ((nlines = readLines(linePtr, MAXLINES, strArray)) >= 0)
    {
        qsort_((void **)linePtr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : strcmp), reverse);
        writeLines(linePtr, nlines);
    }
    else
    {
        printf("error: input too big to sort\n");
        returnCode = 1;
    }

    return returnCode;
}