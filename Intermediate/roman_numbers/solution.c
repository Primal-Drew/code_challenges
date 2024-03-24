#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 1. Test if number is greater than e.g 1000
 * 2. Divide by the place value(e.g 1000) to get num
 * 3. Use case selection e.g in the case of greater than 1000 2 is MM and store in result array keeping in mind the current index.
 * 4. Return the answer.
 *                      ***I AM NOT PROUD OF THIS***
 * */

char *thousandths[] = {"", "M", "MM", "MMM"};
char *hundredths[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
char *tenths[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
char *oneths[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

char *solution(int n)
{
    if (n > 3999)
    {
        return NULL;
    }
    char *roman = calloc(17, sizeof(char));
    int indx = 0;
    int thousands = n / 1000;
    int hundreds = (n / 100) % 10;
    int tens = (n / 10) % 10;
    int ones = n % 10;

    strcpy(roman, thousandths[thousands]);
    indx += strlen(thousandths[thousands]);
    strcpy(roman + indx, hundredths[hundreds]);
    indx += strlen(hundredths[hundreds]);
    strcpy(roman + indx, tenths[tens]);
    indx += strlen(tenths[tens]);
    strcpy(roman + indx, oneths[ones]);
    indx += strlen(oneths[ones]);

    roman[indx] = '\0';
    return roman;
}

int main()
{
    char *roman = solution(3999);
    printf("%s\n", roman);
    free(roman);
}