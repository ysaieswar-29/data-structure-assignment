#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {

    if((rear + 1) % MAX == front) {
        printf("Queue Full\n");
        return;
    }

    if(front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

void dequeue() {

    if(front == -1) {
        printf("Queue Empty\n");
        return;
    }

    printf("Removed element: %d\n", queue[front]);

    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void peek() {
    if(front == -1)
        printf("Queue Empty\n");
    else
        printf("Front element: %d\n", queue[front]);
}

void display() {

    int i;

    if(front == -1) {
        printf("Queue Empty\n");
        return;
    }

    printf("Queue elements: ");

    for(i = front; i != rear; i = (i + 1) % MAX) {
        printf("%d ", queue[i]);
    }

    printf("%d\n", queue[rear]);
}

int main() {

    int choice, value;

    while(1) {

        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice");
        }
    }
}