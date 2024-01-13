#include <stdio.h>

void reverse(char s[], int left, int right);

int main()
{
    char s1[] = "hello world!";
    char s2[] = "ReVerSe! Me pLease!";
    char s3[] = "";
    char s4[] = "a";
    char s5[] = "ab";

    reverse(s1, 0, 11);
    printf("%s\n", s1);
    reverse(s2, 0, 18);
    printf("%s\n", s2);
    reverse(s3, 0, 0);
    printf("%s\n", s3);
    reverse(s4, 0, 0);
    printf("%s\n", s4);
    reverse(s5, 0, 1);
    printf("%s\n", s5);

    return 0;
}

// assumes right >= left and the existence of s[left] and s[right]
void reverse(char s[], int left, int right)
{
    int length = (right - left) + 1;
    char temp;

    if (length <= 1)
    {
        return;
    }
    else
    {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        reverse(s, ++left, --right);
    }
}