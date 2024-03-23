#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* disemvowel(const char* str)
{
    size_t len = strlen(str);
    char *result = calloc(strlen(str)+1,sizeof(char));
    int result_indx = 0;
    char vowels[] = "AaEeIiOoUu";
    for(size_t i = 0;i<len;i++)
    {
        static int s = 0;
        if((strchr(vowels,str[i]))!=NULL)
            continue;
        else
             s++;
        result[result_indx++] = str[i];
    }
    result[result_indx+1] ='\0';
    return result;
}

int main()
{ 
    const char* str = "Andrew was a fool for this";
    char *result = disemvowel(str);
    printf("Result: %s\n",result);
    free(result);
    return 0;
}