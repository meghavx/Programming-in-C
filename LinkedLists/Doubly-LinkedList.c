/*
	@author: Megha Verma
	July 2021
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int data;
	struct node *next;
	struct node *prev;
} DLLNode;


/* Following functions will work the same way as they do for SLL */
int findMiddle(DLLNode *);
void deleteLL(DLLNode **);
int getLength_recursively(DLLNode *);
int getLength_iteratively(DLLNode *);
void printLL_iteratively(DLLNode *);
void printLL_recursively(DLLNode *, int);
void updateAtPosition(DLLNode **, int, int);



/* Implementation of following functions shall vary, though */
void insertAtPosition(DLLNode **, int, int);
void insertAtStart(DLLNode **, int);
void insertAtEnd(DLLNode **, int);
void deleteAtPosition(DLLNode **, int);
void reverseLL_iteratively(DLLNode **);
void reverseLL_recursively(DLLNode **, DLLNode *);



int main() {

	int val, pos;

	DLLNode *n1 = (DLLNode *)malloc(sizeof(DLLNode));
	DLLNode *n2 = (DLLNode *)malloc(sizeof(DLLNode));
	DLLNode *n3 = (DLLNode *)malloc(sizeof(DLLNode));
	DLLNode *n4 = (DLLNode *)malloc(sizeof(DLLNode));

	DLLNode *head = n1; head->prev = NULL;

	n1->data = 10; n1->next = n2; n1->prev = head;
	n2->data = 20; n2->next = n3; n2->prev = n1;
	n3->data = 30; n3->next = n4; n3->prev = n2;
	n4->data = 40; n4->next = NULL; n1->prev = n3;


	printf(" Existing DLL: ");
	printLL_iteratively(head);
	printf("\n Length: %d\n", getLength_recursively(head));
	printf("\n Middle element -> %d\n\n", findMiddle(head));


	
	/* TESTING THE INSERT AT START FUNCTION */
	printf ("\n Insert at start: ");
	scanf("%d", &val);
	insertAtStart(&head, val);
	printf("\n Current status of DLL:\n ");
	printLL_recursively(head, 0);
	printf("\n\n Length: %d", getLength_recursively(head));
	printf("\n Middle element -> %d\n\n", findMiddle(head));



	/* TESTING THE INSERT AT END FUNCTION */
	printf ("\n Insert at end: ");
	scanf("%d", &val);
	insertAtEnd(&head, val);
	printf("\n Current status of DLL:\n ");
	printLL_recursively(head, 0);
	printf("\n\n Length: %d", getLength_recursively(head));
	printf("\n Middle element -> %d\n\n", findMiddle(head));
    


	/* TESTING THE INSERT AT POSITION FUNCTION */
	printf ("\n Insert at position (val pos): ");
	scanf("%d %d", &val, &pos);
	insertAtPosition(&head, val, pos);
	printf("\n Current status of DLL:\n ");
	printLL_recursively(head, 0);
	printf("\n\n Length: %d", getLength_recursively(head));
	printf("\n Middle element -> %d\n\n", findMiddle(head));
    	


	/* TESTING THE UPDATE VALUE FUNCTION */ 
	printf ("\n Update at position (val pos): ");
	scanf("%d %d", &val, &pos);
	updateAtPosition(&head, val, pos);
	printf("\n Current status of LL:\n ");
	printLL_recursively(head, 0);
	printf("\n\n Length: %d", getLength_recursively(head));
	printf("\n Middle element -> %d\n\n", findMiddle(head));
    


	/* TESTING THE DELETE NODE AT POSITION FUNCTION */
	printf ("\n Delete node at position: ");
	scanf("%d", &pos);
	deleteAtPosition(&head, pos);
	printf("\n Current status of DLL:\n ");
	printLL_recursively(head, 0);
	printf("\n\n Length: %d", getLength_recursively(head));
	printf("\n Middle element -> %d\n\n", findMiddle(head));
	

 
	/* TESTING THE REVERSE LL FUNCTIONS */
	reverseLL_iteratively(&head);
	printf("\n Printing (iteratively) reversed DLL:\n ");
	printLL_recursively(head, 0);
	
	printf("\n\n NOTE: Further round of reversing should restore the original order of LL.\n");

	reverseLL_recursively(&head, head);
	printf("\n Printing (recursively) reversed DLL (original order restored):\n ");
	printLL_recursively(head, 0);
	printf("\n");

	/* TESTING THE DELETE LL FUNCTION */
	deleteLL(&head);
	printf("\n Status of LL after performing deletion: ");
	printLL_iteratively(head);
	printf("\n Length: %d\n", getLength_recursively(head));
		


	/* TESTING THE INSERT AT START FUNCTION */
	printf ("\n Insert at start: ");
	scanf("%d", &val);
	insertAtStart(&head, val);
	printf("\n Current status of DLL:\n ");
	printLL_recursively(head, 0);
	printf("\n\n Length: %d", getLength_recursively(head));
	printf("\n Middle element -> %d\n\n", findMiddle(head));
	

	/* TESTING THE INSERT AT END FUNCTION */
	printf ("\n Insert at end: ");
	scanf("%d", &val);
	insertAtEnd(&head, val);
	printf("\n Current status of DLL:\n ");
	printLL_recursively(head, 0);
	printf("\n\n Length: %d", getLength_recursively(head));
	printf("\n Middle element -> %d\n\n", findMiddle(head));
    


	/* TESTING THE INSERT AT POSITION FUNCTION */
	printf ("\n Insert at position (val pos): ");
	scanf("%d %d", &val, &pos);
	insertAtPosition(&head, val, pos);
	printf("\n Current status of DLL:\n ");
	printLL_recursively(head, 0);
	printf("\n\n Length: %d", getLength_recursively(head));
	printf("\n Middle element -> %d\n\n", findMiddle(head));
	

	return 0;
}


void printLL_recursively(DLLNode *head, int desc) {
	if (!head) return;
	
	if (!desc) {
		// Original order
		printf ("%d ", head->data);
		printLL_recursively(head->next, desc);
	} else {
		// Reverse order 
		printLL_recursively(head->next, desc);
		printf ("%d ", head->data);
	}
}
 

void printLL_iteratively(DLLNode *head) {
	if (!head) {
		printf("\n Linked list is empty!\n");
		return;
	}
	for (; printf("%d ",head->data), head = head->next;);
	
}


int getLength_recursively(DLLNode *head) {
	if (!head) return 0;
	return 1 + getLength_recursively(head->next);
}


int getLength_iteratively(DLLNode *head) {
	int len = 0;
	if (!head) return len;
	for (;len += 1, head = head->next;);
	return len;
}


void insertAtStart(DLLNode **head, int val) {
	DLLNode *newNode = (DLLNode *)malloc(sizeof(DLLNode));
	newNode->data = val;

	if (*head)
		(*head)->prev = newNode;
	newNode->next = *head;
	newNode->prev = NULL;
	*head = newNode;
}


void insertAtEnd(DLLNode **head, int val) {
	DLLNode *newNode = (DLLNode *)malloc(sizeof(DLLNode));
	newNode->data = val;

	if (!*head) {
		newNode->next = newNode->prev = NULL;
		*head = newNode;
		return;
	}

	DLLNode *temp = *head;
	while (temp->next) 
		temp = temp->next;
	
	newNode->next = NULL;
	newNode->prev = temp;
	temp->next = newNode;
}


void insertAtPosition(DLLNode **head, int val, int pos) {
	if (!*head && pos >= 1) {
		printf("Empty linked list! Can't insert at position '%d'!\n",pos);
		return;
	}

	DLLNode *newNode = (DLLNode *)malloc(sizeof(DLLNode));
	if (!newNode) {
		printf("Memory full! Can't create a new node!\n");
		return;
	}

	// Insert at start
	if (pos == 1 || pos == 0) {
		insertAtStart(head, val);
		return;
	}
	// Insert at end
	else if (pos == -1) {
		insertAtEnd(head, val);
		return;
	}
	
	else if (pos > 1) {
		newNode->data = val;
		DLLNode *temp = *head;

		int k = 1; 
		while (temp->next && k++ != pos-1)
			temp = temp->next; 
		
		if (pos-k <= 1) {
			newNode->next = temp->next;
			newNode->prev = temp;
			temp->next = newNode;
			if (temp->next)
				temp->next->prev = newNode; 
		} else {
			printf("\n Invalid position entered. The linked list isn't\n "
				"sufficiently long to insert element at position '%d'!\n", pos);
			return;
		}
	} else {
		printf("\n Invalid position entered.\n");
		return;
	}
}


void updateAtPosition(DLLNode **head, int updVal, int pos) {
	if (!*head) {
		printf("Linked list is empty!\n");
		return;
	}

	if (pos == 0 || pos == 1) {
		(*head)->data = updVal;
		return;
	}
	else {
		DLLNode *temp = *head;
		while (temp && --pos)
			temp = temp->next;

		if (pos > 0) 
			printf("\n Invalid position entered!\n");
		else
			temp->data = updVal;

		return;
	} 
}


void deleteAtPosition(DLLNode **head, int pos) {
	if (!*head) {
		printf("Linked list is empty!\n");
		return;
	}

	DLLNode *temp = *head;

	if (pos == 0 || pos == 1) {
		(*head)->next->prev = NULL;
		*head = (*head)->next;
		free(temp);
		return;
	}
	else {
		while (temp->next && --pos > 1)
			temp = temp->next;

		if (pos == 1) {
			DLLNode *p = temp->next;
			if (temp->next->next)
				p->next->prev = p->prev;
			temp->next = p->next;
			free(p);
			return;
		}
		else{
			printf("\n Invalid position enetered!\n");
			return;
		}
	} 
}


int findMiddle(DLLNode *head) {
	if (!head) {
		printf("Linked list is empty!\n");
		return -1;
	}

	DLLNode *fast_ptr = head, *slow_ptr = head;

	while (fast_ptr->next && fast_ptr->next->next) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
	}

	return slow_ptr->data;
}


void reverseLL_recursively(DLLNode **head, DLLNode *p) {
	// if prev is pointing at NULL right at the start
	if (!p) {
		printf("\nLinked list is empty!!\n");
		return;
	}
	// upon reaching the last node
	if (p->next == NULL) {
		*head = p;
		(*head)->prev = NULL;
		return;
	}
	reverseLL_recursively(head, p->next);
	p->next->next = p;
	p->prev = p->next;
	p->next = NULL;
}

void reverseLL_iteratively(DLLNode **head) {
	if (!*head) {
		printf("Linked list is empty!!\n");
		return;
	}

	DLLNode *prev = *head, *curr = prev->next; 
	while (curr) {
		prev->next = curr->next;	// node before curr gets connected to curr's next
		curr->next = *head;			// Append curr before head
		*head = curr;				// curr becomes the new head
		curr = prev->next;			// updated next of the prev node becomes the new curr
	}
	return;
}


void deleteLL(DLLNode **head) {
	if (!*head) {
		printf("Linked list is already empty!!\n");
		return;
	}

	while (*head) {
		DLLNode *temp = *head;
		*head = temp->next;
		free(temp);
	}
	printf(" Linked List has been successfully deleted!\n");
	return;
}


