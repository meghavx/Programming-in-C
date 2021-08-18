#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct queue {
    int front;
    int rear;
    int capacity;
    int *array;
} DynArrayQueue;

int size = 0;

DynArrayQueue *CreateDynQueue() {
    DynArrayQueue *Q = malloc(sizeof(DynArrayQueue));
    if (!Q)
        return NULL;
    Q->capacity = 1;
    Q->front = Q->rear = -1;
    Q->array = malloc(Q->capacity * sizeof(int));
    if (!Q)
        return NULL;
    return Q;
}

void DoubleQueue(DynArrayQueue *Q) {
    Q->capacity *= 2;
    Q->array = realloc(Q->array,Q->capacity * sizeof(int));
}

int QueueSize() {
    return size;
}

int isEmptyQueue(DynArrayQueue *Q) {
    return (Q->front == -1) && (Q->rear == -1);
}

void Enqueue(DynArrayQueue *Q, int val) {
    if ((Q->rear+1) % Q->capacity == Q->front)
        DoubleQueue(Q);
    Q->rear = (Q->rear + 1) % (Q->capacity);
    Q->array[Q->rear] = val; 
    if (Q->front == -1)
        Q->front = Q->rear;
    size++;
}

int Dequeue(DynArrayQueue *Q) {
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
        return val;
    }
}


int main() {
    DynArrayQueue *Q = CreateDynQueue();
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
    int x = Dequeue(Q);
    printf("Is my Queue full? %d, Size: %d\n", isFullQueue(Q), QueueSize(Q));
    Enqueue(Q,60);
    printf("Is my Queue empty? %d, Size: %d\n", isEmptyQueue(Q), QueueSize(Q));
    printf("Is my Queue full? %d, Size: %d\n", isFullQueue(Q), QueueSize(Q));
    return 0;
}