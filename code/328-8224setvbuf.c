
#include <stdio.h>
#include <string.h>

int main()
{
	char buffer[1024];

	memset(buffer, '\0', sizeof(buffer));

	fprintf(stdout, "set full buffer\n");
	setvbuf(stdout, buffer, _IOFBF, 1024);

	fprintf(stdout, "Linkerist Heracles\n");
	fprintf(stdout, "This output will go into buff\n");
	fflush(stdout);

	fprintf(stdout, "just a test line for sleep\n");
	fprintf(stdout, "will come after sleeping 5 seconds\n");

	sleep(5);

	return(0);
}

