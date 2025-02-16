#include <stdio.h>
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

void swap(char *v[], int i, int j)
{
    char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(char *v[], int left, int right)
{
    if (left < right)
    {
        swap(v, left, (left + right) / 2);
        int last = left;
        for (int i = left + 1; i <= right; i++)
        {
            if (strcmp(v[i], v[left]) < 0)
            {
                swap(v, ++last, i);
            }
        }

        swap(v, left, last);
        qsort(v, left, last - 1);
        qsort(v, last + 1, right);
    }
}

int main()
{
    int returnCode = 0;

    int nlines;
    char *linePtr[MAXLINES];
    char strArray[MAXLINES * MAXLEN];

    if ((nlines = readLines(linePtr, MAXLINES, strArray)) >= 0)
    {
        qsort(linePtr, 0, nlines - 1);
        writeLines(linePtr, nlines);
    }
    else
    {
        printf("error: input too big to sort\n");
        returnCode = 1;
    }

    return returnCode;
}