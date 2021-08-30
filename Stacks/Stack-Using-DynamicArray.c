#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack {
    int *array;
    int top;
    int capacity;
    int size;
} DynamicArrStack;


DynamicArrStack *CreateStack();
void Push(DynamicArrStack *, int);
int Pop(DynamicArrStack *);
int Top(DynamicArrStack *);
int GetSize(DynamicArrStack *);
int IsEmptyStack(DynamicArrStack *);
void DeleteStack(DynamicArrStack *);
void DoubleStack(DynamicArrStack *);
void DisplayStackElements(DynamicArrStack *);


int main() {
    int elem, ch = -1, popped;
    DynamicArrStack *myStack = CreateStack();
    
    printf ("\n Current Status of the Stack: Empty\n\n");
    
    do {
        printf("\t=======================\n");
        printf("\t STACK-OPERATIONS MENU \n");
        printf("\t=======================\n");
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
                popped = Pop(myStack);
                if (popped > INT_MIN)
                    printf(" Popped element: %d\n", popped);
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
        printf("\n | %d <- Size of the stack\n | %d <- Total capacity\n\n\n\n", GetSize(myStack), myStack->capacity);
    
    } while (ch != 0);
    
    return 0;
}


DynamicArrStack *CreateStack() {
    DynamicArrStack *S = malloc(sizeof(DynamicArrStack));
    if (!S) {
        printf("\n Memory error!\n");
        return NULL;
    }
    S->capacity = 1;
    S->top = -1;
    S->array = malloc(S->capacity*sizeof(int));
    if (!S->array) {
        printf("\n Memory error!\n");
        return NULL;
    }
    return S;
}


void DoubleStack(DynamicArrStack *S) {
    S->capacity *= 2;
    S->array = realloc(S->array, S->capacity * sizeof(int)); 
}


int GetSize(DynamicArrStack *S) {
    return S->size;
}


int IsEmptyStack(DynamicArrStack *S) {
    return (S->size == 0);
}


void Push(DynamicArrStack *S, int val) {
    if (GetSize(S) == S->capacity)
        DoubleStack(S);
    
    S->array[++S->top] = val;
    printf(" %d has been pushed onto the stack!\n", val);
}


int Pop(DynamicArrStack *S) {
    if (IsEmptyStack(S)) {
        printf("\n Can't pop the stack; Stack is empty!\n");
        return INT_MIN;
    } else {
        printf("\n Element has successfully been popped!\n");
        return (S->array[S->top--]);
    }
}


int Top(DynamicArrStack *S) {
    if (IsEmptyStack(S)) {
        printf("\n Can't get the top of the stack; Stack is empty!\n");
        return INT_MIN; 
    } else 
        return (S->array[S->top]);
}


void DisplayStackElements(DynamicArrStack *S) {
    if (GetSize(S) == 0) {
        printf("\n\n Nothing there to display; Stack is empty!\n");
        return;
    } else {
        printf("\n\n >> Current status of the stack:\n\n\t ----------\n");
        for (int i = GetSize(S)-1; i >= 0; i--)
            printf("\t |  %3d   |\n\t ----------\n", S->array[i]);
        printf("\n");
    }
}


void DeleteStack(DynamicArrStack *S) {
    if (GetSize(S) == 0) {
        printf("\n Can't delete an empty stack!\n\n");
        return;
    }
    else if (S) {
        if (S->array)
            free(S->array);
        free(S);
    }
    printf("\n Stack has been successfully deleted!\n\n");
    S->size = 0;
    S->capacity = 1;
    S->top = -1;
}

