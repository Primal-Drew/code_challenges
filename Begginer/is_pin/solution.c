#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool validate_pin(const char *pin)
{
    size_t len = strlen(pin);
    char pin_storage[len];
    char numbers[] = "1234567890";
    strcpy(pin_storage, pin);

    for (size_t i = 0; i < len; i++)
    {
        if ((strchr(numbers, pin_storage[i])) == NULL)
        {
            printf("false\n");
            return false;
        }
    }
    if (len == 4 || len == 6)
    {
        printf("true\n");
        return true;
    }
    printf("false\n");
    return false;
}

int main()
{
    const char *pin = "123a";
    bool is_pin = validate_pin(pin);
    return 0;
}