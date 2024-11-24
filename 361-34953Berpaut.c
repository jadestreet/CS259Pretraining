/* Cipta Senarai, Jejak, dan Selit dalam Senarai Berpaut (Linked List) */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct nod {
	int data;
	struct nod *next;
} NOD, *NODPTR;

void CiptaSenarai(NODPTR *s)
{
	*s = NULL;
}

NODPTR NodBaru(int m)
{
	NODPTR n;
		
		n = (NODPTR) malloc(sizeof(NOD));
	
		if(n != NULL) {
		n -> data = m;
		n -> next = NULL;
}

return n;
}

void SelitSenarai (NODPTR *s, NODPTR t, NODPTR p)
{
	if (p==NULL) {
		t -> next = *s;
		*s = t;
	}

	else {
		t -> next = p -> next;
		p ->next = t;
	}
}

void JejakSenarai (NODPTR s)
{
	NODPTR ps;
	for (ps = s; ps != NULL; ps = ps -> next)
		printf("%d -->", ps -> data);
		printf("NULL\n");
}

int main ()
{
	NODPTR pel;
	NODPTR n;

	CiptaSenarai(&pel);
	n = NodBaru(55);
	SelitSenarai(&pel, n, NULL);
	n= NodBaru(75);
	SelitSenarai(&pel, n, NULL);
	JejakSenarai(pel);

	return 0;
}
