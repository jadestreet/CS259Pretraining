#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define QUANTIDADE 200000

void heapsort(int array[], int n)
{
 int i,t;
 
 heapify(array,n);
 
 for(i=n-1 ; i>0 ; i--)
 {
  t = array[0];
  array[0] = array[i];
  array[i] = t;
  adjust(array,i);
 }
}
 
 
void heapify(int array[], int n)
{
 int item,i,j,k;
 
 for(k=1 ; k<n ; k++)
 {
  item = array[k];
  i = k;
  j = (i-1)/2;
 
  while( (i>0) && (item>array[j]) )
  {
   array[i] = array[j];
   i = j;
   j = (i-1)/2;
  }
  array[i] = item;
 }
}
 
void adjust(int array[], int n)
{
 int item,i,j;
 
 j = 0;
 item = array[j];
 i = 2*j+1;
 
  while(i<=n-1)
 {
  if(i+1 <= n-1)
   if(array[i] < array[i+1])
    i++;
  if(item < array[i])
  {
   array[j] = array[i];
   j = i;
   i = 2*j+1;
  }
  else
   break;
 }
 array[j] = item;
}


int main()
{
    int vetor[QUANTIDADE];
    int i, alea, qtd=0;
    
    srand(time(NULL));
    
    for(i=0; i<QUANTIDADE; i++)
    {
        alea = rand()%1000000;
	// vetor[i] = alea;
    }    

    printf("Executando HeapSort...\n");
    heapsort(vetor, QUANTIDADE);
    return 0;
}
