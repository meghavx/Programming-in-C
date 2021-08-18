#define MAXSIZE 5

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack {
    int *array;
    int capacity;
    int top;
} StaticArrStack;

StaticArrStack *CreateStack() {
    StaticArrStack *S = malloc(sizeof(StaticArrStack));
    if (!S)
        return NULL;
    S->capacity = MAXSIZE;
    S->top = -1;
    S->array = malloc(S->capacity * sizeof(int));
    if (!S->array)
        return NULL;
    return S;
}

void Push(StaticArrStack *, int);
int Pop(StaticArrStack *);
int Top(StaticArrStack *);
int GetSize(StaticArrStack *);
int IsEmptyStack(StaticArrStack *);
void DeleteStack(StaticArrStack *);
void DisplayStackElements(StaticArrStack *);


int main() {

    int elem, ch = -1;
    StaticArrStack *myStack = CreateStack();

    printf ("\n Current Status of the Stack: Empty\n\n");
    do {
        printf("\t======================\n");
        printf("\t STACK-OPERATIONS MENU \n");
        printf("\t======================\n");
        printf("\n\t1 Push element");
        printf("\n\t2 Pop the stack");
        printf("\n\t3 Get the Top");
        printf("\n\t4 Display all the elements");
        printf("\n\t5 Delete the Stack");
        printf("\n\t0 EXIT\n");
        printf("\n\tEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\n\n Element to push: ");
                scanf("%d", &elem);
                Push(myStack, elem);
                break;
            case 2:
                if (Pop(myStack) > INT_MIN)
                    printf(" Popped element: %d\n", Pop(myStack));
                break;
            case 3:
                if (Top(myStack) > INT_MIN)
                    printf("\n\n Top of the stack: %d\n", Top(myStack));
                break;
            case 4:
                DisplayStackElements(myStack);
                break;
            case 5:
                DeleteStack(myStack);
                break;
            case 0:
                exit(1);
                break;
            default:
                printf("\n Invalid choice entered!\n");
                break;
        }
        printf("\n | %d <- Size of the stack\n | %d <- Total capacity\n | %d <- Remaining capacity\n\n\n\n", GetSize(myStack), MAXSIZE, MAXSIZE-GetSize(myStack));
    } while (ch != 0);

    return 0;
}



int GetSize(StaticArrStack *S) {
    return (S->top == -1) ? 0 : (S->top+1);
}


int IsEmptyStack(StaticArrStack *S) {
    return (S->top == -1);
}


void Push(StaticArrStack *S, int val) {
    if (GetSize(S) == MAXSIZE)
        printf(" Stack Overflow! Can't push this element onto the stack!\n");
    else {
        S->array[++S->top] = val;
        printf(" %d has been pushed onto the stack!\n", val);
    }
}


int Top(StaticArrStack *S) {
    if (IsEmptyStack(S)) {
        printf("\n Can't get the top of the stack; Stack is empty!\n");
        return INT_MIN;
    }
    else
        return (S->array[S->top]);
}


int Pop(StaticArrStack *S) {
    if (IsEmptyStack(S)) {
        printf("\n Can't pop the stack; Stack is empty!\n");
        return INT_MIN;
    } else {
        printf("\n Element has successfully been popped!\n");
        return (S->array[S->top--]);
    }
}


void DeleteStack(StaticArrStack *S) {
    if (S) {
        if (S->array)
            free(S->array);
        free(S);
    }
    printf("\n Stack elements have been successfully deleted!\n\n");
}


void DisplayStackElements(StaticArrStack *S) {
    if (IsEmptyStack(S) == 1) {
        printf("\n\n Nothing there to display; Stack is empty!\n");
        return;
    } else {
        printf("\n\n >> Current status of the stack:\n\n\t ---------\n");
        for (int i = GetSize(S)-1; i >= 0; i--)
            printf("\t |  %3d  |\n\t ---------\n", S->array[i]);
        printf("\n");
    }
}