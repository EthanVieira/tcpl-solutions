#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int evaluate(int left, int right, char *op)
{
    int result = left;

    if (strcmp(op, "+") == 0)
    {
        result += right;
    }
    else if (strcmp(op, "-") == 0)
    {
        result -= right;
    }
    else if (strcmp(op, "x") == 0) // use x for multiplication to avoid shell * shenanigans
    {
        result *= right;
    }
    else if (strcmp(op, "/") == 0)
    {
        result /= right;
    }
    else
    {
        printf("Invalid operator given. Available operators are: + - x /");
    }

    return result;
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Must have at least 3 arguments in a reverse Polish expression.");
    }
    else if (argc % 2 != 0)
    {
        printf("Invalid number of arguments for a reverse Polish expression.");
    }
    else
    {
        int numOperations = (argc / 2) - 1;
        int operatorIndex = argc - numOperations;
        int leftOperandIndex = operatorIndex - 2;
        char *op;
        int left = 0;
        int right = atoi(argv[operatorIndex - 1]);

        for (int i = 0; i < numOperations; i++)
        {
            op = argv[operatorIndex++];
            left = atoi(argv[leftOperandIndex--]);
            right = evaluate(left, right, op);
        }

        printf("%d", right);
    }
}