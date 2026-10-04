c
#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

/* ENQUEUE operation */
void enqueue(int value)
{
    /* Check whether queue is full */
    if ((rear + 1) % MAX == front)
    {
        printf("\nQueue Overflow! Queue is full.\n");
        return;
    }

    /* First element */
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;

    printf("\n%d inserted into the circular queue.\n", value);
}

/* DEQUEUE operation */
void dequeue()
{
    int value;

    if (front == -1)
    {
        printf("\nQueue Underflow! Queue is empty.\n");
        return;
    }

    value = queue[front];

    printf("\n%d deleted from the circular queue.\n", value);

    /* Only one element was present */
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

/* FRONT operation */
void showFront()
{
    if (front == -1)
    {
        printf("\nQueue is empty. No front element.\n");
        return;
    }

    printf("\nFront element = %d\n", queue[front]);
}

/* DISPLAY operation */
void display()
{
    int i;

    if (front == -1)
    {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nCircular Queue elements are:\n");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

/* Main function */
int main()
{
    int choice, value;

    while (1)
    {
        printf("\n===== CIRCULAR QUEUE MENU =====\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. FRONT\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                showFront();
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
