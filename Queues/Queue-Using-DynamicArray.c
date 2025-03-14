#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct queue {
    int *array;
    int front, rear;
    int capacity;
    int size;
} DynamicArrQueue;


DynamicArrQueue *CreateDynQueue();
void DoubleQueue(DynamicArrQueue *);
int GetSize(DynamicArrQueue *);
int isEmptyQueue(DynamicArrQueue *);
void Enqueue(DynamicArrQueue *, int);
int Dequeue(DynamicArrQueue *);
int Front(DynamicArrQueue *);
int Rear(DynamicArrQueue *);
void DisplayQueue(DynamicArrQueue *);
void DeleteQueue(DynamicArrQueue *);


int main() {
    
    int elem, ch = -1, dequeued;
    DynamicArrQueue *myQueue = CreateDynQueue();
    
    printf ("\n\n--------------------QUEUE USING DYNAMIC ARRAY--------------------\n\n");
    printf ("\n Current Status of the Queue: Empty\n\n");
    
    printf("\t=======================\n");
    printf("\t QUEUE-OPERATIONS MENU \n");
    printf("\t=======================\n");
    printf("\n\t1 Enqueue");
    printf("\n\t2 Dequeue");
    printf("\n\t3 Get Front");
    printf("\n\t4 Get Rear");
    printf("\n\t5 Display Queue");
    printf("\n\t6 Delete Queue");
    printf("\n\t0 EXIT\n");
    
    do {
        printf("\n\tEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\n\n Element to enqueue: ");
                scanf("%d", &elem);
                Enqueue(myQueue, elem);
                break;
            case 2:
                dequeued = Dequeue(myQueue);
                if (dequeued > INT_MIN)
                    printf(" Dequeued element: %d\n", dequeued);
                break;
            case 3:
                if (Front(myQueue) > INT_MIN)
                    printf("\n\n Front of the Queue: %d\n", Front(myQueue));
                break;
            case 4:
                if (Rear(myQueue) > INT_MIN)
                    printf("\n\n Rear of the Queue: %d\n", Rear(myQueue));
                break;
            case 5:
                DisplayQueue(myQueue);
                break;
            case 6:
                DeleteQueue(myQueue);
                break;
            case 0:
                printf("\n GOODBYE!\n");
                exit(1);
                break;
            default:
                printf("\n Invalid choice entered!\n");
                break;
        }
        printf("\n | %d <- Size of the queue\n | %d <- Current capacity\n\n\n\n", GetSize(myQueue), myQueue->capacity);
   
    } while (ch != 0);

    return 0;
}


DynamicArrQueue *CreateDynQueue() {
    DynamicArrQueue *Q = malloc(sizeof(DynamicArrQueue));
    if (!Q) {
        printf("\n Memory error!\n");
        return NULL;
    }
    
    Q->capacity = 1;
    Q->front = Q->rear = -1;
    Q->array = malloc(Q->capacity * sizeof(int));
    
    if (!Q) {
        printf("\n Memory error!\n");
        return NULL;
    }
    return Q;
}


void DoubleQueue(DynamicArrQueue *Q) {
    Q->capacity *= 2;
    Q->array = realloc(Q->array,Q->capacity * sizeof(int));
}


int GetSize(DynamicArrQueue *Q) {
    return Q->size;
}


int isEmptyQueue(DynamicArrQueue *Q) {
    // return (Q->front == -1) && (Q->rear == -1);
    return Q->size == 0;
}


void Enqueue(DynamicArrQueue *Q, int val) {
    // if ((Q->rear+1) % Q->capacity == Q->front)
    if (GetSize(Q) == Q->capacity)
        DoubleQueue(Q);
    
    Q->rear = (Q->rear + 1) % (Q->capacity);
    Q->array[Q->rear] = val; 
    
    if (Q->front == -1)
        Q->front = Q->rear;
    
    Q->size++;
    printf(" %d has been successfully enqueued!\n", val);
}


int Dequeue(DynamicArrQueue *Q) {
    if (isEmptyQueue(Q)) {
        printf("\n Can't perform the Dequeue operation; Queue is empty!\n");
        return INT_MIN;
    }
    else {
        int val = Q->array[Q->front];
        if (Q->front == Q->rear)
            Q->front = Q->rear = -1;
        else
            Q->front += 1;
        Q->size--;
        printf("\n Element has successfully been dequeued!\n");
        return val;
    }
}


int Front(DynamicArrQueue *Q) {
    if (GetSize(Q) == 0) {
        printf("\n Can't get front of the queue; Queue is empty!\n");
        return INT_MIN;
    }
    return (Q->array[Q->front]);
}


int Rear(DynamicArrQueue *Q) {
    if (GetSize(Q) == 0) {
        printf("\n Can't get front of the queue; Queue is empty!\n");
        return INT_MIN;
    }
    return (Q->array[Q->rear]);
}


void DisplayQueue(DynamicArrQueue *Q) {
    if (GetSize(Q) == 0) {
        printf("\n\n Nothing there to display; Queue is empty!\n");
        return;
    } 
    else {
        printf("\n\n >> Current status of the Queue:\n\n\tFront —> ");
        for (int i = 0; i < GetSize(Q); i++)
            printf(" %3d ", Q->array[i]);
        printf(" <— Rear\n");
    }
}


void DeleteQueue(DynamicArrQueue *Q) {
    if (Q->size == 0) {
        printf("\n Can't delete an empty queue!\n\n");
        return;
    }
    else if (Q) {
        if (Q->array)
            free(Q->array);
        free(Q);
    }
    printf("\n Queue has been successfully deleted!\n\n");
    Q->size = 0;
    Q->capacity = 1;
    Q->front = Q->rear = -1;
}
