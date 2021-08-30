#define MAXSIZE 10

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack {
    int *array;
    int capacity;
    int top;
    int size;
} StaticArrStack;


StaticArrStack *CreateStack();
int GetSize(StaticArrStack *);
int IsEmptyStack(StaticArrStack *);
void Push(StaticArrStack *, int);
int Pop(StaticArrStack *);
int Top(StaticArrStack *);
void DisplayStack(StaticArrStack *);
void DeleteStack(StaticArrStack *);


int main() {

    int elem, ch = -1, popped;
    StaticArrStack *myStack = CreateStack();

    printf ("\n Current Status of the Stack: Empty\n\n");
    
    printf("\t======================\n");
    printf("\t STACK-OPERATIONS MENU \n");
    printf("\t======================\n");
    printf("\n\t1 Push");
    printf("\n\t2 Pop");
    printf("\n\t3 Get Top");
    printf("\n\t4 Display Stack");
    printf("\n\t5 Delete Stack");
    printf("\n\t0 EXIT\n");

    do {
        printf("\n\tEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\n\n Element to push: ");
                scanf("%d", &elem);
                Push(myStack, elem);
                break;
            case 2:
                popped = Pop(myStack);
                if (popped > INT_MIN)
                    printf(" Popped element: %d\n", popped);
                break;
            case 3:
                if (Top(myStack) > INT_MIN)
                    printf("\n\n Top of the stack: %d\n", Top(myStack));
                break;
            case 4:
                DisplayStack(myStack);
                break;
            case 5:
                DeleteStack(myStack);
                break;
            case 0:
                printf("\n GOODBYE!\n");
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


StaticArrStack *CreateStack() {
    StaticArrStack *S = malloc(sizeof(StaticArrStack));
    if (!S) {
        printf("\nMemory error!\n");
        return NULL;
    }
    S->capacity = MAXSIZE;
    S->top = -1;
    S->array = malloc(S->capacity * sizeof(int));
    if (!S->array)
        return NULL;
    return S;
}

int GetSize(StaticArrStack *S) {
    // return (S->top == -1) ? 0 : (S->top+1);
    return S->size;
}


int IsEmptyStack(StaticArrStack *S) {
    return (S->top == -1);
}


void Push(StaticArrStack *S, int val) {
    if (GetSize(S) == MAXSIZE)
        printf(" Stack Overflow! Can't push this element onto the stack!\n");
    else {
        S->array[++S->top] = val;
        S->size++;
        printf(" %d has been pushed onto the stack!\n", val);
    }
}


int Pop(StaticArrStack *S) {
    if (IsEmptyStack(S)) {
        printf("\n Can't pop the stack; Stack is empty!\n");
        return INT_MIN;
    } else {
        printf("\n Element has been successfully popped!\n");
        S->size--;
        return (S->array[S->top--]);
    }
}


int Top(StaticArrStack *S) {
    if (IsEmptyStack(S)) {
        printf("\n Can't get top of the stack; Stack is empty!\n");
        return INT_MIN;
    }
    return (S->array[S->top]);
}


void DisplayStack(StaticArrStack *S) {
    if (GetSize(S) == 0) {
        printf("\n\n Nothing there to display; Stack is empty!\n");
        return;
    } else {
        printf("\n\n >> Current status of the Stack:\n\n\t ----------\n");
        for (int i = GetSize(S)-1; i >= 0; i--)
            printf("\t |  %3d   |\n\t ----------\n", S->array[i]);
        printf("\n");
    }
}


void DeleteStack(StaticArrStack *S) {
    if (S->size == 0) {
        printf("\n Can't delete an empty stack!\n\n");
        return;
    }
    else if (S) {
        if (S->array)
            free(S->array);
        free(S);
        S->size = 0;
    }
    printf("\n Stack has been successfully deleted!\n\n");
}
