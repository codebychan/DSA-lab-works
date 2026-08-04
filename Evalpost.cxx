//multidigits supported 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char postfix[200];
    char *token;
    int a, b, result;

    printf("Enter postfix expression (space separated):\n");
    fgets(postfix, sizeof(postfix), stdin);

    token = strtok(postfix, " \n");

    while (token != NULL)
    {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
        {
            push(atoi(token));
        }
        else
        {
            b = pop();
            a = pop();

            switch (token[0])
            {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
                case '%':
                    result = a % b;
                    break;
                default:
                    printf("Invalid operator\n");
                    return 1;
            }

            push(result);
        }

        token = strtok(NULL, " \n");
    }

    printf("Result = %d\n", pop());

    return 0;
}
