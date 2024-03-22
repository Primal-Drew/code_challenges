#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// returned string has to be dynamically allocated and will be freed by the caller
char *alphabet_position(const char *text)
{
    char *alphabet_pos = malloc(strlen(text) * 3); // Malloc size of array since resultant size is unknown.
    int pos = 0;                                   // Used to set position for null terminating the array.

    if (alphabet_pos == NULL)
    {
        fprintf(stderr, "malloc failed!\n"); // Error handling the malloc.
        return NULL;
    }
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            pos += sprintf(alphabet_pos + pos, "%d ", (text[i] - 'a' + 1));
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {

            pos += sprintf(alphabet_pos + pos, "%d ", (text[i] - 'A' + 1));
        }
    }
    alphabet_pos[pos] ='\0'; // Null terminating the array.
    return alphabet_pos;
}
