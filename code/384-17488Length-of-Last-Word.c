#include <ctype.h>

int lengthOfLastWord(char *s) {
    char *start = s, *end = s;
    
    while(*s){
        if(*s == ' ' && isalpha(*(s+1)))
            start = s+1;
            
        if(!isalpha(*(s+1)) && isalpha(*s))
            end = s+1;
            
        ++s;
    }
    
    return end>start ? end-start : 0;
}

int main(int argc, char const *argv[])
{
    char *s = "    as     ddfdf fss       ";
    printf("%d\n", *s);
    printf("%d\n", lengthOfLastWord(s));
    return 0;
}