#include <stdio.h>

float fahrToCelsius(int fahr);

int main()
{
    for (int fahr = 0; fahr <= 300; fahr += 20)
    {
        printf("%3d %6.1f\n", fahr, fahrToCelsius(fahr));
    }

    return 0;
}

float fahrToCelsius(int fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}