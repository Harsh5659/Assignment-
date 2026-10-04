# DSA Assignment – Structures & Algorithms

## Q1. Stack Using Array in C

### Question
Design and implement a stack using an array without using any built-in stack library. Perform:
- PUSH(x)
- POP()
- PEEK()
- DISPLAY()

The program must handle Stack Overflow and Stack Underflow conditions.

### Explanation

A **stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle. This means the element inserted last is removed first.

For example:

If we push:
`10, 20, 30`

The stack becomes:

```text
TOP
 ↓
30
20
10
```

When POP() is performed, `30` is removed first.

In an array-based stack, a variable called `top` is used to keep track of the position of the topmost element.

Initially:

```text
top = -1
```

This indicates that the stack is empty.

#### PUSH(x)

The PUSH operation inserts an element at the top of the stack.

Before insertion, we check whether:

```text
top == MAX - 1
```

If this condition is true, the stack is full and insertion is not possible. This condition is called **Stack Overflow**.

Otherwise:

```text
top = top + 1
stack[top] = x
```

#### POP()

POP removes the top element.

If:

```text
top == -1
```

the stack is empty, so deletion is not possible. This condition is called **Stack Underflow**.

Otherwise, the top element is removed and `top` is decreased.

#### PEEK()

PEEK displays the element currently present at the top without removing it.

If the stack is empty, PEEK cannot return an element.

#### DISPLAY()

DISPLAY prints all stack elements starting from `top` and moving toward the bottom.

### C Program

```c
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
```

### Sample Output

```text
===== STACK MENU =====
1. PUSH
2. POP
3. PEEK
4. DISPLAY
5. EXIT

Enter your choice: 1
Enter value to push: 10
10 pushed into the stack.

Enter your choice: 1
Enter value to push: 20
20 pushed into the stack.

Enter your choice: 1
Enter value to push: 30
30 pushed into the stack.

Enter your choice: 4

Stack elements are:
30
20
10

Enter your choice: 3

Top element = 30

Enter your choice: 2

30 popped from the stack.

Enter your choice: 4

Stack elements are:
20
10
```

### Stack Overflow Example

The array size in this program is:

```c
#define MAX 5
```

Therefore, at most five elements can be stored.

If the user attempts to insert a sixth element, the program displays:

```text
Stack Overflow! Cannot insert 60.
```

This happens because there is no free location in the fixed-size array.

### Stack Underflow Example

If the user tries to POP an element when the stack contains no elements, the program displays:

```text
Stack Underflow! Stack is empty.
```

This prevents the program from accessing an invalid array position.

### Time and Space Complexity

| Operation | Time Complexity | Explanation |
|---|---|---|
| PUSH | O(1) | Inserts at the top |
| POP | O(1) | Removes from the top |
| PEEK | O(1) | Directly accesses top |
| DISPLAY | O(n) | May print all n elements |

The **space complexity is O(n)** because the array can store up to `n` elements.

### What happens when the stack is fixed-size?

When a stack is implemented using a fixed-size array, its capacity cannot automatically increase. If all positions are occupied and another element is inserted, **Stack Overflow** occurs.

For example, if:

```text
MAX = 5
```

and the stack contains:

```text
10 20 30 40 50
```

attempting to push `60` is rejected.

This is an important limitation of an array-based fixed-size stack. A dynamically allocated stack can be designed to grow, but the given implementation uses a fixed array as required by the question.

---

# Q2. Circular Queue Using Array in C

### Question
Implement a Circular Queue using an array supporting:
- ENQUEUE(x)
- DEQUEUE()
- FRONT()
- DISPLAY()

The implementation must correctly distinguish between a full queue and an empty queue.

### Explanation

A **queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle.

This means the element inserted first is removed first.

For example:

```text
ENQUEUE: 10, 20, 30

FRONT → 10  20  30 ← REAR
```

After DEQUEUE():

```text
FRONT → 20  30 ← REAR
```

A **circular queue** is an improved form of a queue in which the last position of the array is logically connected to the first position.

The circular behavior is achieved using the modulo operator:

```c
(rear + 1) % MAX
```

and

```c
(front + 1) % MAX
```

This allows the queue to reuse positions that became free after deletion.

### Full and Empty Conditions

For this implementation:

**Empty queue:**

```text
front == -1
```

**Full queue:**

```text
(rear + 1) % MAX == front
```

These conditions allow the program to distinguish between a full queue and an empty queue.

### ENQUEUE(x)

ENQUEUE inserts an element at the rear.

If the queue is full, insertion is rejected and **Queue Overflow** is displayed.

If the queue is empty, both `front` and `rear` are initialized to `0`.

Otherwise:

```text
rear = (rear + 1) % MAX
```

The new value is then stored at `queue[rear]`.

### DEQUEUE()

DEQUEUE removes the element from the front.

If:

```text
front == -1
```

the queue is empty, so deletion is not possible.

If `front == rear`, only one element is present. After removing it, both are reset to `-1`.

Otherwise:

```text
front = (front + 1) % MAX
```

### FRONT()

FRONT displays the element at the front without removing it.

### DISPLAY()

DISPLAY starts at `front` and continues circularly until `rear` is reached.

### C Program

```c
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
```

### Sample Output

```text
===== CIRCULAR QUEUE MENU =====
1. ENQUEUE
2. DEQUEUE
3. FRONT
4. DISPLAY
5. EXIT

Enter your choice: 1
Enter value to enqueue: 10
10 inserted into the circular queue.

Enter your choice: 1
Enter value to enqueue: 20
20 inserted into the circular queue.

Enter your choice: 1
Enter value to enqueue: 30
30 inserted into the circular queue.

Enter your choice: 4

Circular Queue elements are:
10 20 30

Enter your choice: 3

Front element = 10

Enter your choice: 2

10 deleted from the circular queue.

Enter your choice: 1
Enter value to enqueue: 40
40 inserted into the circular queue.

Enter your choice: 4

Circular Queue elements are:
20 30 40
```

### Circular Reuse of Memory

Suppose the queue has five positions:

```text
Index:  0   1   2   3   4
        -------------------
        10  20  30  40  50
```

After deleting `10` and `20`, the beginning positions become free:

```text
Index:  0   1   2   3   4
        -------------------
        --  --  30  40  50
```

A circular queue can reuse these free positions.

For example, after suitable deletions, a new element can be inserted at index `0` by wrapping around:

```c
rear = (rear + 1) % MAX;
```

This is the major advantage of a circular queue.

---

# Comparison: Circular Queue vs Linear Queue

| Feature | Linear Queue | Circular Queue |
|---|---|---|
| Structure | Linear | Circular |
| Memory reuse | Limited | Better |
| ENQUEUE | O(1) | O(1) |
| DEQUEUE | O(1) | O(1) |
| Space | O(n) | O(n) |
| Rear movement | Moves toward last index | Wraps around |
| Memory utilization | Can leave unused positions | Reuses freed positions |

## 1. Why does a circular queue provide better utilization of memory?

In a simple linear queue, `front` and `rear` generally move in one direction.

Consider:

```text
[10][20][30][40][50]
 ↑              ↑
FRONT          REAR
```

If the first three elements are deleted:

```text
[ ][ ][ ][40][50]
          ↑    ↑
        FRONT REAR
```

The first three positions are empty, but a simple linear queue may not be able to use them if `rear` has already reached the last index.

A circular queue solves this problem by connecting the last position back to the first position.

Thus, previously freed positions can be reused.

## 2. Time complexity of ENQUEUE and DEQUEUE

Both operations take:

```text
O(1)
```

### ENQUEUE – O(1)

Only the `rear` position is updated and the new element is inserted.

### DEQUEUE – O(1)

Only the `front` position is updated and the front element is removed.

No shifting of elements is required.

## 3. Space complexity

For a queue with capacity `n`, the space complexity is:

```text
O(n)
```

because the array contains `n` positions.

The circular queue does not require another array for the basic implementation.

## 4. Problem in a linear queue when REAR reaches the last index

This is known as **wasted space** or the **false overflow problem**.

Example:

```text
Capacity = 5

[ ][ ][30][40][50]
          ↑      ↑
        FRONT   REAR
```

The first two positions are free, but if `REAR` has reached the final array index, a basic linear queue may report overflow when another element is inserted.

The circular queue avoids this by moving `REAR` back to the beginning:

```text
rear = (rear + 1) % MAX;
```

Therefore, circular queues make better use of fixed array storage.

---

# Final Complexity Summary

## Stack

| Operation | Time | Space |
|---|---:|---:|
| PUSH | O(1) | O(n) total storage |
| POP | O(1) | O(n) total storage |
| PEEK | O(1) | O(n) total storage |
| DISPLAY | O(n) | O(n) total storage |

## Circular Queue

| Operation | Time | Space |
|---|---:|---:|
| ENQUEUE | O(1) | O(n) total storage |
| DEQUEUE | O(1) | O(n) total storage |
| FRONT | O(1) | O(n) total storage |
| DISPLAY | O(n) | O(n) total storage |

---

# GitHub Upload Structure

A clean GitHub repository can be organized as:

```text
DSA-Assignment/
│
├── README.md
│
├── Stack/
│   └── stack_array.c
│
├── Circular_Queue/
│   └── circular_queue.c
│
└── Outputs/
    └── sample_output.txt
```

Suggested repository description:

```text
DSA Assignment – Stack and Circular Queue implementation in C.
Includes source code, explanations, operations, complexity analysis,
overflow/underflow handling, and sample outputs.
```

Suggested commit messages:

```text
Add stack implementation using array
Add circular queue implementation
Add complexity analysis and documentation
Add sample outputs
```
