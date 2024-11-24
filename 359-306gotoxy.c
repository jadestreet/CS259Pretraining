#include<stdio.h>
#include<stdlib.h>
int lasti=0,lastj=0;
void goback(int x,int y)
{ 
printf("\033[%dA",x);
printf("\033[%dD",y);
}
void gotoxy(int x,int y)
{ 
extern int lasti, lastj;
int i;
goback(lasti, lastj);

for(i=0;i<x;i++)
printf("\n");
for(i=0;i<y;i++)
printf("\t");
lasti=x;
lastj=y;

}

int main ()
{
int i=0;
do
{ i=i+1;
gotoxy(12,5);
printf("hello i=%d\r",i); 
gotoxy(10,5);
printf("hello i-1=%d\r",i-1); 
usleep(3*1000);
}while(0);
}