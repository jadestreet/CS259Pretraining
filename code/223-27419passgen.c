#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//# Source configuration stuff
static unsigned char deflen = 12; // Default length of string
static char* prgname = "passgen"; // Name that this program refers to itself by (most useful if collides with actual filename)
static char* validpass = "01234567890qwertyuiopasdfghjklzxcvbnm-_";
//# End source configuration stuff

int chkvalid(unsigned char c, char* list)
{
	int l = strlen(list);
	int i = 0;
	while(i < l)
	{
		if (c == list[i])
			return 1; // Return as valid
		i++;
	}
	return 0; //Return as invalid
}
int main(int argc,  char** args)
{
	
	int i = 0; // Declare for later
	int j = 0;
	srand(time(NULL)); // Initialize random	

	// Ruse to count the size of no string
	if (argc == 1) 
	{
		// "Documentation"
		printf("Usage: %s [length]\nExample: %s 8\nDefault length: %i\n\nUsing default length:\n",prgname,prgname,deflen);
		i = deflen;
	}
	else if (argc == 2) // Two arguments means that the user has bothered to specify length
	{
		i = atoi(args[1]); // I knew i t would come in handy later
	}

	// Validate input
	if ( i <= 0 )
	{
		printf("No funny business!\n");
		return 1;
	} 
	else if (i > 1024)
	{
		printf("Are you trying to cause a stack overflow?\n");
	}
	
	char buf[i+1]; // +1 is the null terminator at the end
	memset(buf,32,i); // Neutralize the buffer
	buf[i] = '\0'; // Null terminator

	while(j < i) // n = 1 not n < i so that the last char would be a null terminator
	{
		unsigned char c = 0;

		while (chkvalid(c, validpass) == 0 || chkvalid(c, buf)) // Trial/Error validity check for password/form safedness and repeating
			c = (unsigned char)(rand() % 176 + 33);

		buf[j] = c;
	
		j++;
	}

	printf("%s\n",buf);

	return 0;
}
