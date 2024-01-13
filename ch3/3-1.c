#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
    int testArray1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int testArray2[] = {2, 3, 5, 8, 10};
    printf("%d\n", binsearch(4, testArray1, 10)); // 3
    printf("%d\n", binsearch(4, testArray2, 5)); // -1
    printf("%d\n", binsearch(10, testArray2, 5)); // 4
    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    if (v[low] == x)
    {
        return low;
    }

    return -1;
}