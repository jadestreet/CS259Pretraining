#include <stdio.h>


int main()
{
    long i, largest, maxchain, currchain;

    maxchain = 0;
    for (i = 1000000; i > 0; i--) {
        currchain = seriesLen(i);
        if (currchain > maxchain) {
            largest = i;
            maxchain = currchain;
        }
    }
    printf("%i has produced the longest chain (%i items)\n", largest, maxchain);

}


/* Given a number, produces the collatz series and returns the number
of nums in the chain */
int seriesLen(long num)
{
    int i;
    for (i=0; num != 1; i++) {
        if (num % 2 == 0)
            num /= 2;
        else {
            num *= 3;
            num += 1;
       }
    }
    return i;
}

