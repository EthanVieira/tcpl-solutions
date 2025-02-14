#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day)
{
    int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    char *dayTable = leap ? *(daytab + 1) : *(daytab);

    if (year > 0 && month > 0 && month <= 12 && day > 0 && day <= *(dayTable + month))
    {
        for (int i = 1; i < month; i++)
        {
            day += *(dayTable + i);
        }
    }
    else
    {
        day = -1;
    }

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    char *dayTable = leap ? *(daytab + 1) : *(daytab);

    if (year > 0 && yearday <= (leap ? 366 : 365))
    {
        int i;
        for (i = 1; yearday > *(dayTable + i); i++)
        {
            yearday -= *(dayTable + i);
        }

        *pmonth = i;
        *pday = yearday;
    }
}

int main()
{
    printf("%d\n", day_of_year(2025, 3, 25));
    printf("%d\n", day_of_year(2025, 13, 25));
    printf("%d\n", day_of_year(2025, 2, 30));
    printf("%d\n", day_of_year(400, 3, 25));

    int month = -1;
    int day = -1;
    month_day(2025, 80, &month, &day);
    printf("%d %d\n", month, day);
    month_day(400, 80, &month, &day);
    printf("%d %d\n", month, day);

    month = -1;
    day = -1;

    month_day(2025, 366, &month, &day);
    printf("%d %d\n", month, day);
    month_day(400, 366, &month, &day);
    printf("%d %d\n", month, day);

    return 0;
}