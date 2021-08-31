/*
	@author: Megha Verma
	July 2021
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} CLLNode;


void printLL_iteratively(CLLNode *);
int getLength_iteratively(CLLNode *);
void insertAtStart(CLLNode **, int);
void insertAtEnd(CLLNode **, int);
void deleteAtPosition(CLLNode **, int);
void insertAtPosition(CLLNode **, int, int);


void updateAtPosition(CLLNode **, int, int);
// void reverseLL_iteratively(CLLNode **);
// int findMiddle(CLLNode *);
// void deleteLL(CLLNode **);


// int getLength_recursively(CLLNode *);
// void printLL_recursively(CLLNode *, int);
// void reverseLL_recursively(CLLNode **, CLLNode *);


int main() {

	int val, pos;

	CLLNode *n1 = (CLLNode *)malloc(sizeof(CLLNode));
	CLLNode *n2 = (CLLNode *)malloc(sizeof(CLLNode));
	CLLNode *n3 = (CLLNode *)malloc(sizeof(CLLNode));
	CLLNode *n4 = (CLLNode *)malloc(sizeof(CLLNode));

	CLLNode *head = n1; 

	n1->data = 10; n1->next = n2;
	n2->data = 20; n2->next = n3; 
	n3->data = 30; n3->next = n4; 
	n4->data = 40; n4->next = head;

	printf(" Existing CLL: ");


	/* TESTING LL DISPLAY FUNCTIONS */
	// printf(" Printing in original order (recursively):\n ");
	// printLL_recursively(head, 0);
	// deleteAtPosition(&head, -1);
	// deleteAtPosition(&head, -1);
	// deleteAtPosition(&head, -1);
	// deleteAtPosition(&head, -1);
	printf("\n Printing in original order (iteratively):\n ");
	printLL_iteratively(head);
	printf("\n");

	// printf("\n Printing in reverse order (recursively):\n ");
	// printLL_recursively(head, 1);
	// /*printf("\n Printing in reverse order (iteratively):\n ");
	// printLL_iteratively(head, 1); */
	// printf("\n");

	// printf("\n Length(computed recursively): %d", getLength_recursively(head));
	printf("\n Length(computed iteratively): %d\n", getLength_iteratively(head));
	// printf("\n Middle element -> %d\n\n", findMiddle(head));

	
	/* TESTING LL INSERT FUNCTION */
	// printf ("\n Insert at start: ");
	// scanf("%d", &val);
	// insertAtStart(&head, val);
	// printf("\n Current status of CLL:\n ");
	// printLL_iteratively(head);
	// printf("\n Length: %d\n", getLength_iteratively(head));
	// printf("\n Middle element -> %d\n\n", findMiddle(head));


	// printf ("\n Insert at end: ");
	// scanf("%d", &val);
	// insertAtEnd(&head, val);
	// printf(" Current status of CLL:\n ");
	// printLL_iteratively(head);
	// printf("\n Length: %d\n", getLength_iteratively(head));
	// printf("\n Middle element -> %d\n\n", findMiddle(head));


	// printf ("\n Insert at position (val pos): ");
	// scanf("%d %d", &val, &pos);
	// insertAtPosition(&head, val, pos);
	// printf("\n Current status of CLL:\n ");
	// printLL_iteratively(head);
	// printf("\n Length: %d\n", getLength_iteratively(head));
	// printf("\n Middle element -> %d\n\n", findMiddle(head));
	

	// printf ("\n Insert at position (val pos): ");
	// scanf("%d %d", &val, &pos);
	// insertAtPosition(&head, val, pos);
	// printf("\n Current status of CLL:\n ");
	// printLL_iteratively(head);
	// printf("\n Length: %d\n", getLength_iteratively(head));
	// printf("\n Middle element -> %d\n\n", findMiddle(head));



	// /* TESTING THE UPDATE VALUE FUNCTION */
	printf ("\n Update at position (val pos): ");
	scanf("%d %d", &val, &pos);
	updateAtPosition(&head, val, pos);
	printf("\n Current status of CLL:\n ");
	printLL_iteratively(head);
	printf("\n Length: %d\n", getLength_iteratively(head));
	// printf("\n Middle element -> %d\n\n", findMiddle(head));



	/* TESTING THE DELETE NODE AT POSITION FUNCTION */
	// printf ("\n Delete node at position: ");
	// scanf("%d", &pos);
	// deleteAtPosition(&head, pos);
	// printf("\n Printing in original order (iteratively):\n ");
	// printLL_iteratively(head);
	// printf(" Length: %d\n", getLength_iteratively(head));
	// printf("\n Middle element -> %d\n\n", findMiddle(head));

	

	// /* TESTING THE REVERSE LL FUNCTIONS */
	// reverseLL_iteratively(&head);
	// printf("\n Printing (iteratively) reversed linked list:\n ");
	// printLL_recursively(head, 0);
	// printf("\n Length: %d\n", getLength_recursively(head));
	// printf("\n Middle element -> %d\n", findMiddle(head));

	// printf("\n NOTE: Further round of reversing should restore the original order of LL.\n");

	// reverseLL_recursively(&head, head);
	// printf("\n Printing (recursively) reversed linked list (original order restored): ");
	// printLL_recursively(head, 0);
	// printf("\n Length: %d\n", getLength_recursively(head));
	// printf("\n Middle element -> %d\n\n", findMiddle(head));



	/* TESTING THE DELETE LL FUNCTION */ 
	// deleteLL(&head);
	// printf("\n Status of CLL after performing deletion: ");
	// printLL_iteratively(head);
	// printf("\n Length: %d\n", getLength_iteratively(head));
	
	return 0;
}


void printLL_iteratively(CLLNode *head) {
	if (!head) {
		printf("\n Linked list is empty!\n");
		return;
	}
	CLLNode *temp = head;
	do {
		printf("%d ", temp->data);
		temp = temp->next;
	} while (temp != head);
	printf("\n");
}


// void printLL_recursively(CLLNode *head, int desc) {
// 	if (!head) return;

// 	if (desc != ) {
// 		// Original order
// 		printf ("%d ", head->data);
// 		printLL_recursively(head->next, desc);
// 	} else {
// 		// Reverse order 
// 		printLL_recursively(head->next, desc);
// 		printf ("%d ", head->data);
// 	}
// }
 


// int getLength_recursively(CLLNode *head) {
// 	if (!head) return 0;
// 	return 1 + getLength_recursively(head->next);
// }


int getLength_iteratively(CLLNode *head) {
	if (!head) 
		return 0;
	if (head == head->next) 
		return 1;
	int len = 0;
	CLLNode *temp = head;
	do {
		len++;
		temp = temp->next;
	} while (temp != head);

	return len;
}


void insertAtStart(CLLNode **head, int val) {
	CLLNode *newNode = (CLLNode *)malloc(sizeof(CLLNode));
	if(!*head) {
		newNode->data = val;
		*head = newNode;
		newNode->next = *head;
	
	} else {
		newNode->next = (*head)->next;
		(*head)->next = newNode;
		newNode->data = (*head)->data;
		(*head)->data = val;
	}
}


void insertAtEnd(CLLNode **head, int val) {
	CLLNode *newNode = (CLLNode *)malloc(sizeof(CLLNode));
	if(!*head) {
		newNode->data = val;
		*head = newNode;
		newNode->next = *head;
	
	} else {
		newNode->next = (*head)->next;
		(*head)->next = newNode;
		newNode->data = (*head)->data;
		(*head)->data = val;
		*head = newNode;
	}
}


void insertAtPosition(CLLNode **head, int val, int pos) {
	if (!*head) {
		if (pos > 1) {
			printf(" Linked list is empty! Can't insert at position '%d'!\n",pos);
			return;
		} else if (pos == 0 || pos == 1) {
			insertAtStart(head, val);
			return;
		} else if (pos == -1) {
			insertAtEnd(head, val);
			return;
		}
	}
	CLLNode *newNode = (CLLNode *)malloc(sizeof(CLLNode));
	if (!newNode) {
		printf("Memory full! Can't create a new node!\n");
		return;
	}
	if (pos == 1 || pos == 0) {
		insertAtStart(head, val);
		return;
	}
	else if (pos == -1) {
		insertAtEnd(head, val);
		return;
	}
	else if (pos > 1) {
		newNode->data = val;
     	CLLNode *p = *head;
		while (p->next != *head && --pos > 1)
			p = p->next; 
		
		if (pos > 2) {
			printf("\n Invalid position entered. The linked list isn't\n "
				"sufficiently long to insert element at this position!\n");
			return;
		} else {
			newNode->next = p->next;	
			p->next = newNode;
		}
	} else {
		printf(" Invalid position entered.\n");
		return;
	}
}


void updateAtPosition(CLLNode **head, int updVal, int pos) {
	if (!*head) {
		printf("Linked list is empty!\n");
		return;
	}

	if (pos == -1) {
		CLLNode *p = *head;
		do {
			p = p->next;
		} while (p != *head);
		p->data = updVal;
		return;
	}
	else if (pos == 0 || pos == 1) {
		(*head)->data = updVal;
		return;
	}
	else if (pos > 1) {
		CLLNode *temp = *head;
		while (temp && --pos)
			temp = temp->next;

		if (pos > 0) 
			printf(" Invalid position entered!\n");
		else
			temp->data = updVal;

		return;
	} 
	else {
		printf(" Invalid position entered!\n");	
	}
}


void deleteAtPosition(CLLNode **head, int pos) {
	if (!*head) {
		printf("Linked list is empty!\n");
		return;
	}
	if (pos == 0 || pos == 1) {
		if (*head == (*head)->next)
			*head = NULL;
		else {
			(*head)->data = (*head)->next->data;
			CLLNode *temp = (*head)->next;
			(*head)->next = temp->next;
			free(temp);	
		}
	} 
	else if (pos == -1) {
		if ((*head)->next == *head)
			*head = NULL;
		else {
			CLLNode *p = *head;
			while(p->next->next != *head)
				p = p->next;
			free(p->next);
			p->next = *head;
		}
	}
	else if (pos > 1) {
		CLLNode *p = *head;
		while (p->next != *head && --pos > 1)
			p = p->next;

		if (pos > 1) {
			printf("\n Invalid position entered. The linked list isn't\n "
 				"sufficiently long to insert element at this position!\n");
 			return;
		} else {
			CLLNode *temp = p->next;
			p->next = temp->next;
			free(temp);
		}
	} 
	else {
		printf(" Invalid position entered\n");
		return;
	}
}


// int findMiddle(CLLNode *head) {
// 	if (!head) {
// 		printf("Linked list is empty!\n");
// 		return -1;
// 	}
// 	CLLNode *fast_ptr = head, *slow_ptr = head;
// 	while (fast_ptr->next && fast_ptr->next->next) {
// 		slow_ptr = slow_ptr->next;
// 		fast_ptr = fast_ptr->next->next;
// 	}
// 	return slow_ptr->data;
// }



// void deleteLL(CLLNode **head) {
// 	if (!*head) {
// 		printf("Linked list is already empty!!\n");
// 		return;
// 	}
// 	CLLNode *newHead= (*head)->next;
// 	while(newHead) { 
// 		CLLNode *temp = newHead;
// 		newHead = newHead->next;
// 		free(temp);
// 	}
// 	free(*head);
// }


// void reverseLL_iteratively(CLLNode **head) {
// 	if (!*head) {
// 		printf("Linked list is empty!!\n");
// 		return;
// 	}
// 	CLLNode *prev = *head, *curr = prev->next; 
// 	while (curr) {
// 		prev->next = curr->next;
// 		curr->next = *head;	
// 		*head = curr;		
// 		curr = prev->next;
// 	}
// 	return;
// }


// void reverseLL_recursively(CLLNode **head, CLLNode *prev) {
// 	if (!prev) {
// 		printf("\nLinked list is empty!!\n");
// 		return;
// 	}
// 	if (prev->next == NULL) {
// 		*head = prev;
// 		return;
// 	}
// 	reverseLL_recursively(head, prev->next);
// 	prev->next->next = prev;
// 	prev->next = NULL;
// }




