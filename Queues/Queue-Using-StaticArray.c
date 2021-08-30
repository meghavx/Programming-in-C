#define MAXSIZE 10

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct queue {
    int *array;
    int capacity;
    int front, rear;
    int size;
} StaticArrQueue;


StaticArrQueue *CreateQueue();
int GetSize(StaticArrQueue *);
int IsEmptyQueue(StaticArrQueue *);
void Enqueue(StaticArrQueue *, int);
int Dequeue(StaticArrQueue *);
int Front(StaticArrQueue *);
int Rear(StaticArrQueue *);
void DisplayQueue(StaticArrQueue *);
void DeleteQueue(StaticArrQueue *);


int main() {

    int elem, ch = -1, dequeued;
    StaticArrQueue *myQueue = CreateQueue();

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
                    printf("\n\n Dequeued element: %d\n", dequeued);
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
        printf("\n | %d <- Size of the queue\n | %d <- Total capacity\n | %d <- Remaining capacity\n\n\n\n", GetSize(myQueue), MAXSIZE, MAXSIZE-GetSize(myQueue));
    } while (ch != 0);

    return 0;
}


StaticArrQueue *CreateQueue() {
    StaticArrQueue *Q = malloc (sizeof(StaticArrQueue));
    if (!Q) {
        printf("\nMemory error!\n");
        return NULL;
    }
    
    Q->capacity = MAXSIZE;
    Q->size = 0;
    Q->rear = Q->front = -1;
    Q->array = (int *) malloc (Q->capacity * sizeof(int));
    
    if (!Q->array) {
        printf("\nMemory error!\n");
        return NULL;
    }

    return Q;
}

int GetSize(StaticArrQueue *Q) {
    return Q->size;
}

int IsEmptyQueue(StaticArrQueue *Q) {
    // return (Q->front == -1) && (Q->rear == -1);
    return GetSize(Q) == 0;
}

void Enqueue(StaticArrQueue *Q, int val) {
    if (GetSize(Q) == Q->capacity)
        printf("Queue overflow!\n");
    else {
        Q->rear = (Q->rear+1) % (Q->capacity);
        Q->array[Q->rear] = val;
        if (Q->front == -1)
            Q->front = Q->rear;
        Q->size++;
    } 
}

int Dequeue(StaticArrQueue *Q) {
    if (IsEmptyQueue(Q)) {
        printf("Queue is empty!\n");
        return INT_MIN;   
    } 
    else {
        int val = Q->array[Q->front];
        
        if (Q->front == Q->rear)
            Q->front = Q->rear = -1;
        else
            Q->front += 1;
        
        Q->size--;
        return Q->array[Q->front];
    }  
}


int Front(StaticArrQueue *Q) {
    if (GetSize(Q) == 0) {
        printf("\n Can't get front of the queue; Queue is empty!\n");
        return INT_MIN;
    }
    
    return (Q->array[Q->front]);
}


int Rear(StaticArrQueue *Q) {
    if (GetSize(Q) == 0) {
        printf("\n Can't get front of the queue; Queue is empty!\n");
        return INT_MIN;
    }
    
    return (Q->array[Q->rear]);
}


void DisplayQueue(StaticArrQueue *Q) {
    if (Q->size == 0) {
        printf("\n\n Nothing there to display; Queue is empty!\n");
        return;
    } else {
        printf("\n\n >> Current status of the Queue:\n\n\t ----------\n");
        for (int i = 0; i < GetSize(Q); i++)
            printf("\t |  %3d   |\n\t ----------\n", Q->array[i]);
        printf("\n");
    }
}


void DeleteQueue(StaticArrQueue *Q) {
    if (Q->size == 0) {
        printf("\n Can't delete an empty queue!\n\n");
        return;
    }
    else if (Q) {
        if (Q->array)
            free(Q->array);
        free(Q);
        Q->size = 0;
    }
    printf("\n Queue has been successfully deleted!\n\n");
}
