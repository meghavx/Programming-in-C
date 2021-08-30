#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    int data;
    struct node *next;
} LLStack;

int size = 0;

LLStack *CreateStack();
int GetSize();
int IsEmptyStack(LLStack *);
void Push(LLStack **, int);
int Pop(LLStack **);
int Top(LLStack *);
void DisplayStack(LLStack *);
void DeleteStack(LLStack **);


int main() {

    int elem, ch = -1, popped;
    LLStack *top = CreateStack();

    printf ("\n\n--------------------STACK USING SINGLY LINKED LIST--------------------\n\n");

    printf ("\n Current Status of the Stack: Empty\n\n");
    do {
        printf("\t=======================\n");
        printf("\t STACK-OPERATIONS MENU \n");
        printf("\t=======================\n");
        printf("\n\t1 Push");
        printf("\n\t2 Pop");
        printf("\n\t3 Get Top");
        printf("\n\t4 Display Stack");
        printf("\n\t5 Delete Stack");
        printf("\n\t0 EXIT\n");
        printf("\n\tEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\n\n Element to push: ");
                scanf("%d", &elem);
                Push(&top, elem);
                break;
            case 2:
                popped = Pop(&top);
                if (popped > INT_MIN)
                    printf(" Popped element: %d\n", popped);
                break;
            case 3:
                if (Top(top) > INT_MIN)
                    printf("\n\n Top of the stack: %d\n", Top(top));
                break;
            case 4:
                DisplayStack(top);
                break;
            case 5:
                DeleteStack(&top);
                break;
            case 0:
                printf("\n GOODBYE!\n");
                exit(1);
                break;
            default:
                printf("\n Invalid choice entered!\n");
                break;
        }
        printf("\n | %d <- Size of the stack\n\n\n\n", GetSize());
    
    } while (ch != 0);

    return 0;
}


LLStack *CreateStack() {
    return NULL;
}


int GetSize() {
    return size;
}


int IsEmptyStack(LLStack *top) {
    return (top == NULL);
}


void Push(LLStack **top, int val) {
    LLStack *newNode = malloc(sizeof(LLStack));
    if (!newNode) {
        printf(" Memory error!\n");
        return;
    }
    
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
    
    printf(" %d has been pushed onto the Stack!\n", val);
    size++;
}


int Pop(LLStack **top) {
    if (IsEmptyStack(*top) == 1) {
        printf("\n Can't pop the stack; Stack is empty!\n");
        return INT_MIN;
    }
    else {
        int val = (*top)->data;
        LLStack *temp = *top;
        *top = (*top)->next;
        free(temp);
        printf("\n Element has been successfully popped!\n");
        size--;
        return val;
    }
}


int Top(LLStack *top) {
    if (IsEmptyStack(top)) {
        printf("\n Can't get the top of the stack; Stack is empty!\n");
        return INT_MIN;
    }
    return top->data;
}


void DisplayStack(LLStack *top) {
    if (IsEmptyStack(top)) {
        printf("\n\n Nothing there to display; Stack is empty!\n");
        return;
    } else {
        printf("\n\n >> Current status of the Stack:\n\n\t ----------\n");
        while (top) {
            printf("\t |  %3d   |\n\t ----------\n", top->data);
            top = top->next;
        }
        printf("\n");
    }
}


void DeleteStack(LLStack **top) {
    if (IsEmptyStack(*top)) {
        printf("\n Can't delete an empty Stack!\n\n");
        return;
    }
    else {
        LLStack *p = *top;
        while (p->next) {
            LLStack *temp = p;
            p = p->next;
            free(temp);
        }
        printf("\n Stack has been successfully deleted!\n\n");
        *top = NULL;
        size = 0;
    }
}
