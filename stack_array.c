c
#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

/* PUSH operation */
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("\nStack Overflow! Cannot insert %d.\n", value);
        return;
    }

    top++;
    stack[top] = value;

    printf("\n%d pushed into the stack.\n", value);
}

/* POP operation */
void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow! Stack is empty.\n");
        return;
    }

    printf("\n%d popped from the stack.\n", stack[top]);
    top--;
}

/* PEEK operation */
void peek()
{
    if (top == -1)
    {
        printf("\nStack is empty. No top element.\n");
        return;
    }

    printf("\nTop element = %d\n", stack[top]);
}

/* DISPLAY operation */
void display()
{
    int i;

    if (top == -1)
    {
        printf("\nStack is empty.\n");
        return;
    }

    printf("\nStack elements are:\n");

    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

/* Main function */
int main()
{
    int choice, value;

    while (1)
    {
        printf("\n===== STACK MENU =====\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
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
                printf("\nProgram terminated.\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
