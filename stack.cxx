int main(int argc, char *argv[])
{
	#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int x)
{
    if(top == MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if(top == -1)
        printf("Stack Underflow\n");
    else
    {
        printf("Deleted element: %d\n", stack[top]);
        top--;
    }
}

void peek()
{
    if(top == -1)
        printf("Stack is Empty\n");
    else
        printf("Top element: %d\n", stack[top]);
}

void display()
{
    int i;

    if(top == -1)
        printf("Stack is Empty\n");
    else
    {
        printf("Stack elements:\n");
        for(i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice, item;

    do
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exit\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 5);

    return 0;
}
}