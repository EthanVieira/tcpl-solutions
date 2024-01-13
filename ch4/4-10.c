#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'

void push(double f);

void varPush(char c);

double pop(void);

char varPop(void);

int getop(char in[], char s[]);

int getLine(char s[], int lim);

void clear(void);

void printtop(void);

void swaptop(void);

void duplicate(void);

void setVariable(char name, double value);

double getVariable(char name);

void ungets(char s[]);

int sp = 0;
int varSp = 0;
double val[MAXVAL];
char varVal[MAXVAL];
double variables[27];
bool isVarSet[27];
double mostRecentlyPushed;

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];
    char in[MAXOP];
    in[0] = '\0';

    while ((type = getop(in, s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0)
                {
                    push(pop() / op2);
                }
                else
                {
                    printf("error: zero divisor\n");
                }
                break;
            case '%':
                op2 = pop();
                push((int) pop() % (int) op2);
                break;
            case '^':
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case '=':
                setVariable(varPop(), pop());
                break;
            case 'v':
                push(mostRecentlyPushed);
                break;
            case 'p':
                printtop();
                break;
            case 'w':
                swaptop();
                break;
            case 'c':
                clear();
                break;
            case 'd':
                duplicate();
                break;
            case 's':
                push(sin(pop()));
                break;
            case 'e':
                push(exp(pop()));
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                if (isupper(type))
                {
                    if (isVarSet[type - 'A'])
                    {
                        push(getVariable(type));
                    }
                    else
                    {
                        // assume it is being set here
                        varPush(type);
                    }
                }
                else
                {
                    printf("error: unknown command %s\n", s);
                }

                break;
        }
    }


    return 0;
}

void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
        mostRecentlyPushed = f;
    }
    else
    {
        printf("error: stack full, can't push %g\n", f);
    }
}

void varPush(char c)
{
    if (varSp < MAXVAL)
    {
        varVal[varSp++] = c;
    }
    else
    {
        printf("error: stack full, can't push %g\n", c);
    }
}

double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("here?");
        printf("error: stack empty\n");
        return 0.0;
    }
}

char varPop(void)
{
    if (varSp > 0)
    {
        return varVal[--varSp];
    }
    else
    {
        printf("error: stack empty\n");
        return 'A';
    }
}

int getop(char in[], char s[])
{
    int i;

    if (strlen(in) == 0)
    {
        while (getLine(in, MAXOP) < 0)
        {}
    }

    while (in[0] ==  ' ' || s[0] == '\t')
    {
        memmove(in, in+1, strlen(in));
    }
    s[0] = in[0];

    s[1] = '\0';
    memmove(in, in+1, strlen(in));

    if (!isdigit(s[0]) && s[0] != '.' && s[0] != '-')
    {
        return s[0];
    }
    i = 0;

    if (s[0] == '-')
    {
        if (isdigit(in[0]))
        {
            s[++i] = in[0];
            memmove(in, in+1, strlen(in));
        }
        else
        {
            return '-';
        }

    }

    if (isdigit(in[0]))
    {
        do
        {
            s[++i] = in[0];
            memmove(in, in+1, strlen(in));
        }
        while (isdigit(in[0]));
    }

    if (in[0] == '.')
    {
        do
        {
            s[++i] = in[0];
            memmove(in, in+1, strlen(in));
        }
        while (isdigit(in[0]));
    }

    s[i+1] = '\0';

    return NUMBER;
}

int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    {
        if (i < (lim - 1))
        {
            s[i] = c;
        }
    }

    if (c == '\n')
    {
        if (i < (lim - 1))
        {
            s[i] = c;
            s[++i] = '\0';
        }
        else
        {
            s[lim - 1] = c;
            s[lim] = '\0';
            i++;
        }
    }
    else if (i < (lim - 1))
    {
        s[i] = '\0';
    }
    else
    {
        s[lim - 1] = '\0';
    }

    return i;
}

void clear(void)
{
    sp = 0;
    varSp = 0;
}

void printtop(void)
{
    printf("Value at top of stack: %lf\n", val[sp - 1]);
}

void swaptop(void)
{
    if (sp > 1)
    {
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    }
    else
    {
        printf("error: can't swap less than two elements\n");
    }
}

// assuming this is meant to duplicate the top item in the stack and then put the duplicate on the top of stack
void duplicate(void)
{
    if (sp > 0)
    {
        push(val[sp - 1]);
    }
    else
    {
        printf("error: nothing in the stack to duplicate\n");
    }
}

// assume only capital letters to simplify and avoid collisions with other commands
// assign variable and push to stack
void setVariable(char name, double value)
{
    isVarSet[name - 'A'] = true;
    variables[name - 'A'] = value;
    push(value);
}

double getVariable(char name)
{
    return variables[name - 'A'];
}








