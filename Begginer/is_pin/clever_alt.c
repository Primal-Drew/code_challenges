#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool validate_pin(const char *pin)
{
    int pinLen = strlen(pin);
    if (pinLen == 4 || pinLen == 6)
    {
        for (int i = 0; i < pinLen; i++)
        {
            if (pin[i] < 48 || pin[i] > 57) // Here 48 and 57 are used as ASCII codes for '0' to '9' respectfully.
            {
                return false;
            }
        }
        return true;
    }
    return false;
}