#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *disemvowel(const char* str)
{
    char* result = calloc(strlen(str),sizeof(char));
    size_t len = strlen(str);
    int result_indx = 0;
    for(size_t i = 0;i<len;i++)
    {
        switch (str[i])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            continue;
        }
        result[result_indx++] = str[i];
    }
    result[result_indx+1] = '\0';
    return result;
}

int main()
{
    const char* str = "You a genious";
    char * result = disemvowel(str);
    printf("Result: %s",result);
    free(result);
}