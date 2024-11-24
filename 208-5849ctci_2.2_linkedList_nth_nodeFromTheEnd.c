#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct linkedList {
int data;
struct linkedList *next;
}linkedList;

insertLl(linkedList** x, int data)
{
linkedList *temp = (linkedList*)malloc(sizeof(linkedList));
temp->data = data;
temp->next = *x;
*x = temp;
}

displayList(linkedList *x)
{
while(x!=NULL)
{
printf("%d ",x->data);
x= x->next;
}
}
int movethefastPointerTo_N_position(linkedList **x, int n)
{
    for(int i =0; i<n; i++)
    {
        if(*x==NULL)
           return 0;
        else
           *x = (*x)->next;
    }
    return 1;
}
findTheNthFromTheLastElement(linkedList *x, int n)
{
linkedList *slow = x, *fast = x;
if(movethefastPointerTo_N_position(&fast,n))
{
while(fast!=NULL)
{
fast=fast->next;
slow=slow->next;
}
printf("%d\n",slow->data);
}
}
int main()
{
linkedList *aList= NULL;
insertLl(&aList, 1);
insertLl(&aList,2);
insertLl(&aList, 3);
insertLl(&aList, 3);
insertLl(&aList, 4);
displayList(aList);
printf("\n");
findTheNthFromTheLastElement(aList,5);
}
