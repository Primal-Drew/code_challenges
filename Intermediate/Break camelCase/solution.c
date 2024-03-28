#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//returned buffer should be dynamically allocated and will be freed by a caller
char* solution(const char *camelCase) 
{
    size_t len = strlen(camelCase);
    char* broken_camelCase = malloc(len+10);
    // Copying values one by one!
    int moves=0;
    int indx =0;
    broken_camelCase[indx++] = camelCase[0];
    printf("Value of indx after 0: %i\n",indx);
    for(int i=1;i<len+moves;i++)
    {
        if(isupper(camelCase[i]))
        {
            broken_camelCase[indx++] = ' ';
            broken_camelCase[indx++] = camelCase[i];
            continue;
        }
            broken_camelCase[indx++] = camelCase[i];
    }
    broken_camelCase[indx]  = '\0';
    return broken_camelCase;
}

int main()
{
    const char* camelCase = "ThisIsCamelCase";
    printf("The Result: %s\n",solution(camelCase));
}