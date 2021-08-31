#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    int data;
    struct node *next;
} LLQueue;

int size = 0;

int IsEmptyQueue();
void Enqueue(LLQueue **, LLQueue **, int);
int Dequeue(LLQueue **, LLQueue **);
int Front(LLQueue *);
int Rear(LLQueue *);
void DisplayQueue(LLQueue *);
void DeleteQueue(LLQueue **, LLQueue **);


int main() {
    int elem, ch = -1;
    int dequeuedElem, frontElem, rearElem;
    LLQueue *front = NULL, *rear = NULL;

    printf ("\n\n--------------------QUEUE USING SINGLY LINKED LIST--------------------\n\n");
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
                Enqueue(&front, &rear, elem);
                break;
            case 2:
                dequeuedElem = Dequeue(&front, &rear);
                if (dequeuedElem > INT_MIN)
                    printf(" Dequeued element: %d\n", dequeuedElem);
                break;
            case 3:
                frontElem = Front(front);
                if (frontElem > INT_MIN)
                    printf("\n\n Front of the Queue: %d\n", frontElem);
                break;
            case 4:
                rearElem = Rear(rear);
                if (rearElem > INT_MIN)
                    printf("\n\n Rear of the Queue: %d\n", rearElem);
                break;
            case 5:
                DisplayQueue(front);
                break;
            case 6:
                DeleteQueue(&front, &rear);
                break;
            case 0:
                printf("\n GOODBYE!\n");
                exit(1);
                break;
            default:
                printf("\n Invalid choice entered!\n");
                break;
        }
        printf("\n | %d <- Size of the queue\n\n\n\n", size);
   
    } while (ch != 0);

    return 0;
}


int IsEmptyQueue() {
    return size == 0;
}


void Enqueue(LLQueue **front, LLQueue **rear, int val) {
    LLQueue *newNode = (LLQueue *) malloc (sizeof(LLQueue));
    if (!newNode) {
        printf("\n Memory error!\n");
        return;
    }

    newNode->data = val;
    size++;
    if (!*rear)
        *rear = *front = newNode;
    else
        (*rear)->next = newNode;

}


int Dequeue(LLQueue **front, LLQueue **rear) {
    if (!*front) {
        printf("\n Can't perform the Dequeue operation; Queue is empty!\n");
        return INT_MIN;
    }

    int dequeued = (*front)->data;
    LLQueue *temp = *front;
    if ((*front)->next)
        *front = (*front)->next;
    else
        *front = *rear = NULL;
    free(temp);
    size--;

    printf("\n Element has successfully been dequeued!\n");
    return dequeued;
}


int Front(LLQueue *front) {
    return front->data;
}


int Rear(LLQueue *rear) {
    return rear->data;
}


void DisplayQueue(LLQueue *front) {
    if (IsEmptyQueue()) {
        printf("\n\n Nothing there to display; Queue is empty!\n");
        return;
    } 
    else {
        printf("\n\n >> Current status of the Queue:\n\n    Front —> ");
        while (front) {
            printf(" %3d ", front->data);
            front = front->next;
        }
        printf(" <— Rear\n\n");
    }
}


void DeleteQueue(LLQueue **front, LLQueue **rear) {
    if (IsEmptyQueue()) {
        printf("\n Can't delete an empty Queue!\n");
        return;
    }
    else {
        LLQueue *q = *front;
        while (q->next) {
            LLQueue *temp = q;
            q = q->next;
            free(temp);
        }
        printf("\n Queue has been successfully deleted!\n\n");
        *front = *rear = NULL;
        size = 0;
    }
}