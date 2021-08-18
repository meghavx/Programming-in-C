#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct queue {
    int front;
    int rear;
    int capacity;
    int *array;
} ArrayQueue;

int size = 0;

ArrayQueue *CreateQueue(int size) {
    ArrayQueue *Q = malloc(sizeof(ArrayQueue));
    if (!Q) 
        return NULL;
    Q->capacity = size;
    Q->rear = Q->front = -1;
    Q->array = malloc(Q->capacity * sizeof(int));
    if (!Q->array)
        return NULL;
    return Q;
}

int QueueSize(ArrayQueue *Q) {
    return size;
}

int isEmptyQueue(ArrayQueue *Q) {
    return (Q->front == -1) && (Q->rear == -1);
}

int isFullQueue(ArrayQueue *Q) {
    return (Q->rear + 1) % Q->capacity == Q->front;
}

void Enqueue(ArrayQueue *Q, int val) {
    if (isFullQueue(Q))
        printf("Queue overflow!\n");
    else {
        Q->rear = (Q->rear+1) % (Q->capacity);
        Q->array[Q->rear] = val;
        if (Q->front == -1)
            Q->front = Q->rear;
        size++;
    } 
}

int Dequeue(ArrayQueue *Q) {
    if (isEmptyQueue(Q)) {
        printf("Queue is empty!\n");
        return INT_MIN;   
    } 
    else {
        int val = Q->array[Q->front];
        if (Q->front == Q->rear)
            Q->front = Q->rear = -1;
        else
            Q->front += 1;
        size--;
        return Q->array[Q->front];
    }  
}


int main() {
    // int n = 1;
    // printf("Enter size of the Queue: ");
    // scanf("%d",&n);
    ArrayQueue *Q = CreateQueue(5);
    printf("Is my Queue empty? %d, Size: %d\n", isEmptyQueue(Q), QueueSize(Q));
    Enqueue(Q,10);
    printf("Is my Queue empty? %d, Size: %d\n", isEmptyQueue(Q), QueueSize(Q));
    Enqueue(Q,20);
    Enqueue(Q,30);
    printf("Is my Queue full? %d, Size: %d\n", isFullQueue(Q), QueueSize(Q));
    Enqueue(Q,40);
    printf("Is my Queue full? %d, Size: %d\n", isEmptyQueue(Q), QueueSize(Q));
    Enqueue(Q,50);
    printf("Is my Queue full? %d, Size: %d\n", isEmptyQueue(Q), QueueSize(Q));
    Enqueue(Q,60);
    Dequeue(Q);
    printf("Is my Queue full? %d, Size: %d\n", isFullQueue(Q), QueueSize(Q));
    Enqueue(Q,60);
    printf("Is my Queue empty? %d, Size: %d\n", isEmptyQueue(Q), QueueSize(Q));
    printf("Is my Queue full? %d, Size: %d\n", isFullQueue(Q), QueueSize(Q));
    return 0;
}
