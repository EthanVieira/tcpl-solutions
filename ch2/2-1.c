#include <stdio.h>
#include <limits.h>
#include <float.h>



int main()
{
    printf("Limits for unsigned char: %d, %d\n", 0, UCHAR_MAX);
    printf("Limits for unsigned short: %d, %d\n", 0, USHRT_MAX);
    printf("Limits for unsigned int: %d, %u\n", 0, UINT_MAX);
    printf("Limits for unsigned long: %d, %u\n", 0, ULONG_MAX);
    printf("Limits for signed char: %d, %d\n", CHAR_MIN, CHAR_MAX);
    printf("Limits for signed short: %d, %d\n", SHRT_MIN, SHRT_MAX);
    printf("Limits for signed int: %d, %d\n", INT_MIN, INT_MAX);
    printf("Limits for signed long: %d, %d\n", LONG_MIN, LONG_MAX);
    printf("Limits for signed float: %.10e, %.10e\n", FLT_MIN, FLT_MAX);
    printf("Limits for signed double: %.10e, %.10e\n", DBL_MIN, DBL_MAX);
    printf("Limits for signed long double: %.10e, %.10e\n", LDBL_MIN, LDBL_MAX);

    return 0;
}