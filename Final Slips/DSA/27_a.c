#include <stdio.h>
#define MAX 3

int data[MAX];
int front;
int rear;

void init()
{
    front = rear = -1;
}

int isFull()
{
    if ((rear + 1) % MAX == front)
        return 1;
    return 0;
}

int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}

void enqueue(int n)
{
    if (isFull())
        printf("Queue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX;
        data[rear] = n;
    }
}

int dequeue()
{
    int val = -1;
    if (isEmpty())
    {
        printf("Queue Underflow\n");
    }
    else
    {
        val = data[front];
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
    return val;
}

void display()
{
    printf("Queue Elements: ");
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i != rear; i = (i + 1) % MAX)
    {
        printf("%d ", data[i]);
    }
    printf("%d\n", data[rear]);
}

int main()
{
    init();
    enqueue(4);
    display();
    enqueue(14);
    display();
    enqueue(24);
    display();
    enqueue(34);
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();

    return 0;
}
