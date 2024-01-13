#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXOP 100
#define MAXVAL 100
#define BUFSIZE 100
#define NUMBER '0'

void push(double f);

void varPush(char c);

double pop(void);

char varPop(void);

int getop(char s[]);

int getch(void);

void ungetch(int);

void clear(void);

void printtop(void);

void swaptop(void);

void duplicate(void);

void setVariable(char name, double value);

double getVariable(char name);

void ungets(char s[]);

int sp = 0;
int varSp = 0;
int bufp = 0;
double val[MAXVAL];
char varVal[MAXVAL];
char buf[BUFSIZE];
double variables[27];
bool isVarSet[27];
double mostRecentlyPushed;

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
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

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
    {}

    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c;
    }
    i = 0;

    if (c == '-')
    {
        if (isdigit(c = getch()))
        {
            s[i++] = '-';
            s[i] = c;
        }
        else if (c == '\n')
        {
            ungetch(c);
            return '-';
        }
        else
        {
            return '-';
        }

    }

    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getch()))
        {}
    }

    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
        {}
    }

    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }

    return NUMBER;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp > 0)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

void ungets(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        ungetch(s[i]);
    }
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


