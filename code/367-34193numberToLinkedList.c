/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	struct node* head = NULL;
	int digit_to_be_inserted;
	struct node* walker = NULL;
	struct node* new = NULL;
	
	if(N<0){
		N = -N;
	}
	
	reverse_number(&N);
	
	while(N){
		digit_to_be_inserted = N % 10;
		N = N / 10 ;

		new = (struct node*) malloc(sizeof(struct node));
		new->data = digit_to_be_inserted;
		new->next = NULL;

		if(head == NULL){
			head = new;
			walker = head;
		}
		else{
			walker->next = new;
			walker = new;
		}
	}
	
	return head;
}

void reverse_number(int* N){
	int result = 0;
	while(*N){
		result = (result*10) + ((*N)%10);
		*N = (*N) / 10;
	}
	*N = result;
}

/* test driver	*/
int main(){
	struct node *head = numberToLinkedList(-25478);
	
	while(head != NULL){
		printf("%d ,",head->data);
		head = head->next;
	}
} 
	
