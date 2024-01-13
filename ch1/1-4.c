#include <stdio.h>

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -20;
    upper = 150;
    step = 10;

    printf("--------------\n");
    printf("Celsius | Fahr\n");
    printf("--------------\n");

    celsius = lower;
    while (celsius <= upper)
    {
        fahr = (celsius * (9.0 / 5.0)) + 32.0;
        printf("%3.0f %10.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}