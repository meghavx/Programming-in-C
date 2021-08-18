/*
	@author: Megha Verma
	June 2021
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int data;
	struct node *next;
} SLLNode;


void printLL_recursively(SLLNode *, int);
void printLL_iteratively(SLLNode *);

int getLength_recursively(SLLNode *);
int getLength_iteratively(SLLNode *);

void insertAtPosition(SLLNode **, int, int);
void insertAtStart(SLLNode **, SLLNode *);
void insertAtEnd(SLLNode **, SLLNode *);

void updateAtPosition(SLLNode **, int, int);
void deleteAtPosition(SLLNode **, int);

int findMiddle(SLLNode *);

void reverseLL_iteratively(SLLNode **);
void reverseLL_recursively(SLLNode **, SLLNode *);

void deleteLL(SLLNode **);


int main() {

	int val, pos;

	SLLNode *n1 = (SLLNode *)malloc(sizeof(SLLNode));
	SLLNode *n2 = (SLLNode *)malloc(sizeof(SLLNode));
	SLLNode *n3 = (SLLNode *)malloc(sizeof(SLLNode));
	SLLNode *n4 = (SLLNode *)malloc(sizeof(SLLNode));

	SLLNode *head = n1; 

	n1->data = 10; n1->next = n2;
	n2->data = 20; n2->next = n3; 
	n3->data = 30; n3->next = n4; 
	n4->data = 40; n4->next = NULL;

	printf(" Existing SLL: ");
	printLL_iteratively(head);
	printf("\n Length: %d\n", getLength_recursively(head));
	printf("\n Middle element -> %d\n\n", findMiddle(head));



	/* TESTING LL DISPLAY FUNCTIONS */
	printf(" Printing in original order (recursively):\n ");
	printLL_recursively(head, 0);
	printf("\n Printing in original order (iteratively):\n ");
	printLL_iteratively(head);
	printf("\n");

	printf("\n Printing in reverse order (recursively):\n ");
	printLL_recursively(head, 1);
	/*printf("\n Printing in reverse order (iteratively):\n ");
	printLL_iteratively(head, 1); */
	printf("\n");

	printf("\n Length (computed recursively): %d", getLength_recursively(head));
	printf("\n Length (computed iteratively): %d\n\n", getLength_iteratively(head));
	

	
	/* TESTING LL INSERT FUNCTION */
	printf ("\n Insert at start: ");
	scanf("%d", &val);
	insertAtPosition(&head, val, 1);
	printf("\n Current status of LL:\n ");
	printLL_recursively(head, 0);
	printf("\n\n Length: %d", getLength_recursively(head));
	printf("\n Middle element -> %d\n\n", findMiddle(head));

	printf ("\n Insert at end: ");
	scanf("%d", &val);
	insertAtPosition(&head, val, -1);
	printf("\n Current status of LL:\n ");
	printLL_recursively(head, 0);
	printf("\n\n Length: %d", getLength_recursively(head));
	printf("\n Middle element -> %d\n\n", findMiddle(head));


	printf ("\n Insert at position (val pos): ");
	scanf("%d %d", &val, &pos);
	insertAtPosition(&head, val, pos);
	printf("\n Current status of LL:\n ");
	printLL_recursively(head, 0);
	printf("\n\n Length: %d", getLength_recursively(head));
	printf("\n Middle element -> %d\n\n", findMiddle(head));
	

	printf ("\n Insert at position (val pos): ");
	scanf("%d %d", &val, &pos);
	insertAtPosition(&head, val, pos);
	printf("\n Current status of LL:\n ");
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
	printf("\n Printing in original order (recursively):\n ");
	printLL_recursively(head, 0);
	printf("\n\n Length: %d", getLength_recursively(head));
	printf("\n Middle element -> %d\n\n", findMiddle(head));

	

	/* TESTING THE REVERSE LL FUNCTIONS */
	reverseLL_iteratively(&head);
	printf("\n Printing (iteratively) reversed linked list:\n ");
	printLL_recursively(head, 0);
	printf("\n\n Length: %d", getLength_recursively(head));
	printf("\n Middle element -> %d\n", findMiddle(head));

	printf("\n NOTE: Further round of reversing should restore the original order of LL.\n");

	reverseLL_recursively(&head, head);
	printf("\n Printing (recursively) reversed linked list (original order restored): ");
	printLL_recursively(head, 0);
	printf("\n\n Length: %d", getLength_recursively(head));
	printf("\n Middle element -> %d\n\n", findMiddle(head));



	/* TESTING THE DELETE LL FUNCTION */ 
	deleteLL(&head);
	printf("\n Status of LL after performing deletion: ");
	printLL_iteratively(head);
	printf("\n\n Length: %d\n", getLength_recursively(head));
	
	return 0;
}


void printLL_recursively(SLLNode *head, int desc) {

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
 

void printLL_iteratively(SLLNode *head) {

	if (!head) {
		printf("\n Linked list is empty!\n");
		return;
	}
	for (; printf("%d ",head->data), head = head->next;);
	
}


int getLength_recursively(SLLNode *head) {
	if (!head) return 0;
	return 1 + getLength_recursively(head->next);
}


int getLength_iteratively(SLLNode *head) {
	int len = 0;
	if (!head) return len;
	for (;len += 1, head = head->next;);
	return len;
}


void insertAtStart(SLLNode **head, SLLNode *newNode) {
	newNode->next = *head;
	*head = newNode;	
}


void insertAtEnd(SLLNode **head, SLLNode *newNode) {
	SLLNode *temp = *head;
	
	while (temp->next) 
		temp = temp->next;
	
	temp->next = newNode;
	newNode->next = NULL;
} 


void insertAtPosition(SLLNode **head, int val, int pos) {
	if (!*head && pos >= 1) {
		printf("Empty linked list! Can't insert at position '%d'!\n",pos);
		return;
	}

	SLLNode *newNode = (SLLNode *)malloc(sizeof(SLLNode));
	if (!newNode) {
		printf("Memory full! Can't create a new node!\n");
		return;
	}

	newNode->data = val;
	SLLNode *temp = *head;

	if (pos == 1 || pos == 0) {
		//insertAtStart(head, newNode);
		newNode->next = *head;
		*head = newNode;
	}
	
	else if (pos == -1) {
		//insertAtEnd(head, newNode);
		while (temp->next) 
			temp = temp->next;
	
		temp->next = newNode;
		newNode->next = NULL;
	}
	
	else {
		int k = 1; 
		while (temp->next && k++ != pos-1)
			temp = temp->next; 
		
		if (pos-k <= 1) {
			newNode->next = temp->next;	
			temp->next = newNode;
		} else {
			printf("\n Invalid position entered. The linked list isn't\n "
				"sufficiently long to insert element at position '%d'!\n", pos);
			return;
		}
	}
}


void updateAtPosition(SLLNode **head, int updVal, int pos) {
	if (!*head) {
		printf("Linked list is empty!\n");
		return;
	}

	if (pos == 0 || pos == 1) {
		(*head)->data = updVal;
		return;
	}
	else {
		SLLNode *temp = *head;
		while (temp && --pos)
			temp = temp->next;

		if (pos > 0) 
			printf("\n Invalid position enetered!\n");
		else
			temp->data = updVal;

		return;
	} 
}


void deleteAtPosition(SLLNode **head, int pos) {
	if (!*head) {
		printf("Linked list is empty!\n");
		return;
	}

	SLLNode *temp = *head;

	if (pos == 0 || pos == 1) {
		*head = (*head)->next;
		free(temp);
		return;
	}
	else {
		while (temp->next && --pos > 1)
			temp = temp->next;

		if (pos == 1) {
			SLLNode *p = temp->next;
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


int findMiddle(SLLNode *head) {
	if (!head) {
		printf("Linked list is empty!\n");
		return -1;
	}

	SLLNode *fast_ptr = head, *slow_ptr = head;

	while (fast_ptr->next && fast_ptr->next->next) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
	}

	return slow_ptr->data;
}



void deleteLL(SLLNode **head) {
	if (!*head) {
		printf("Linked list is already empty!!\n");
		return;
	}

	while (*head) {
		SLLNode *temp = *head;
		*head = temp->next;
		free(temp);
	}

	return;
}


void reverseLL_iteratively(SLLNode **head) {
	if (!*head) {
		printf("Linked list is empty!!\n");
		return;
	}

	SLLNode *prev = *head, *curr = prev->next; 
	while (curr) {
		prev->next = curr->next;	// node before curr gets connected to curr's next
		curr->next = *head;			// Append curr before head
		*head = curr;				// curr becomes the new head
		curr = prev->next;			// updated next of the prev node becomes the new curr
	}


	/*SLLNode *prev = *head; 
	while (prev->next) {
		SLLNode *pnext = prev->next;
		prev->next = prev->next->next;
		pnext->next = *head;
		*head = pnext;
	}*/
	return;
}


void reverseLL_recursively(SLLNode **head, SLLNode *prev) {
	// if prev is pointing at NULL right at the start
	if (!prev) {
		printf("\nLinked list is empty!!\n");
		return;
	}
	// upon reaching the last node
	if (prev->next == NULL) {
		*head = prev;
		return;
	}
	reverseLL_recursively(head, prev->next);
	prev->next->next = prev;
	prev->next = NULL;

	/* for the understanding purpose
	SLLNode *curr = prev->next;
	curr->next = prev;
	prev->next = NULL; */
}




