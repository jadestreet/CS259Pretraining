#include <stdio.h>
#include <stdlib.h>


int romanToInt(char* s) {
	int i, r = 0,pre = 0, now = 0, sum = 0, temp = 0;
	int len = strlen(s);
	for(i = 0; i < len; i++){
		if(s[i] == 'I') r = 1;
		if(s[i] == 'V') r = 5;
		if(s[i] == 'X') r = 10;
		if(s[i] == 'L') r = 50;
		if(s[i] == 'C') r = 100;
		if(s[i] == 'D') r = 500;
		if(s[i] == 'M') r = 1000;
		now = r;
		if(i == 0){
			pre = now; temp = r; continue;
		}
		if(now == pre)	temp += now;
		if(now > pre)	temp = now - temp;
		if(now < pre){
			sum += temp;
			temp = now;
		}
		pre = now;
	}
	sum += temp;
    return sum;
}


int main(){
	char *input = "DCXXI"; //621
	//printf("%d", strlen(input));
	printf("%d", romanToInt(input));
}

