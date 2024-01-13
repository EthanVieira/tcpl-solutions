#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]);

int main()
{
    printf("%f\n", atof("123.45e-6"));
    printf("%f\n", atof("123.45e6"));
    printf("%f\n", atof("123.45"));
    printf("%f\n", atof("123"));
    printf("%f\n", atof("123E5"));
}

double atof(char s[])
{
    double val;
    int i, sign;
    double power = 1;
    int sign2 = 1;
    int exp = 0;

    for (i = 0; isspace(s[i]); i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.')
    {
        i++;
        for (power = 1.0; isdigit(s[i]); i++)
        {
            val = 10.0 * val + (s[i] - '0');
            power *= 10.0;
        }
    }

    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        sign2 = 1;
        if (s[i] == '+')
        {
            i++;
        }
        else if (s[i] == '-')
        {
            i++;
            sign2 = -1;
        }

        for (exp = 0.0; isdigit(s[i]); i++)
        {
            exp = 10.0 * exp + (s[i] - '0');
        }
    }

    return (sign * val / power) * pow(10.0, sign2 * exp);

}

