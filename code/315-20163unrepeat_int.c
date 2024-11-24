#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000000

int main() {
    char* p_data = NULL;
    p_data = malloc(sizeof(char) * N );
    memset(p_data, 49, N);
    int i = 0;
    int j = 0;
    FILE* file = fopen("data.txt", "w+");
    srand((int)time(0));
    while ( i < N) {
        //j=1+(int)(N*rand()/(RAND_MAX+1.0));
        j=rand() % N;
        if (p_data[j] == '1') {
            fprintf(file, "%d\n", j+1);
            p_data[j] = '0';
            i++;
        }
    }
    fclose(file);
    free(p_data);
    return 0;
}

