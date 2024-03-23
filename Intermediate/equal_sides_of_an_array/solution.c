#include <stdio.h>
#include <stdlib.h>

/**
 * 1. Big loop mantains current index.
 * 2. Two loops one that adds before indx -- and other thats adds after inx ++
 * 3. A condition that tests whether b4 sum == after sum if not - continue ;if true return it.
 * 4. If all is false return -1
 */

int find_even_index(const int *values, int length)
{
    for (int indx = 0; indx < length; indx++)
    {
        int b4sum = 0, aftsum = 0;
        for (int b4 = 0; b4 < indx; b4++)
        {
            b4sum = values[b4] + b4sum;
            printf("b4:%d || values[%d] = %d\n",b4,b4,values[b4]);
        }

        for (int aft = length-1; aft > indx; aft--)
        {
            aftsum =+ values[aft] + aftsum;
            printf("aft:%d || values[%d] = %d\n",aft,aft,values[aft]);
        }

        printf("indx = %d || b4sum = %d || aftsum = %d\n\n",indx,b4sum,aftsum);
        if (b4sum == aftsum)
            return indx;
    }
    return -1;
}

int main()
{
    int numbers[] = {1,100,50,-51,1,1 };
    int indx = find_even_index(numbers, 6);
    printf("Result %d\n", indx);
}