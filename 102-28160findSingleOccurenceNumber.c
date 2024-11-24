/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include <stdio.h>


#define SIZE_OF_INT 32

int findSingleOccurenceNumber(int *A, int len) {
    int i ;
    int once= 0;
    
    if(!A){
        return -1;
    }
    
    for(i = 0; i < SIZE_OF_INT ; i++){
        int sum = 0;
        int j;
        for(j = 0 ; j < len ; j++){
            sum += k_th_bit(A[j], i);
        }
        sum = (sum % 3) > 0;
        once = once | (sum << i);
    }
    
	return once;
}

int k_th_bit(int n, int k){
    int x = (1 << k) & n;
    
    return (x>0);
}

//Test Driver
int main(){
    int A[] = { 2, 2, 2, 3,3,3,7, 6, 6, 6};
    int len = 7;
    printf("%d\n",findSingleOccurenceNumber(A,len));
}
