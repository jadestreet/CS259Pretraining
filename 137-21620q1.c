/**Problem 1:If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
//The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.

Solved By: Shengyuan Guo in 2013
**/

#include <stdio.h>

int main()
{
    
    printf("Sum of all multiples of 3 or 5 below 1000: %d", natural35(1000));
}
int natural35(int num)
{
    int sum=0;
    int i;
    for(i=3;i<1000;i=i+3)
    {
    sum+=i;
    }
    for(i=5; i<1000;i=i+5)
    {
        if(!(i%3==0))
        sum+=i;
    }
    return sum;
}
