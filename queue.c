#include <stdio.h>

// #include <conio.h>

int queue[20], choice, n, rear, front, item, i;
void enqueue();
void dequeue();
void display();

int main()
{
    front = -1;
    rear = -1;

    printf("\n Enter the size of QUEUE[MAX=20]:");
    scanf("%d", &n);

    printf("\n\t QUEUE OPERATIONS USING ARRAY");

    printf("\n\t------------");

    printf("\n\t 1.ENQUEUEM\n\t 2.DEQUEUE\n\t 3.DISPLAY\n\t 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            enqueue();
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            printf("\n\t EXIT POINT");
            break;
        }
        default:
        {
            printf("\n\t Please Enter a Valid Choice(1/2/3/4)");
        }
        }
    } while (choice != 4);
    return 0;
}

void enqueue()
{
    if (rear < n - 1)
    {
        printf("Enter the data item to be inserted \n");
        scanf("%d", &item);
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = rear + 1;
        }

        queue[rear] = item;
    }
    else
    {
        printf(" Queue is full or queue overflow \n");
    }
}

void dequeue()
{
    if (front != -1)
    {
        item = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = front + 1;
            printf("Deleted data item is %d \n", item);
        }
    }
        else
        {
            printf("Queue is empty or queue underflow \n");
        }
}

void display()
{
    if (front != -1)
    {
        printf("\n The elements in QUEUE \n");
        for (i = rear; i >= front; i--)
        {
            printf("\n%d", queue[i]);
        }
        printf("\n Elements at front of the queue is %d", queue[front]);
        printf("\n Elements at rear of the queue is %d", queue[rear]);

    }
        else
        {
            printf("\n The Queue is empty\n");
        }
}
