#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long sum_two_smallest_numbers(size_t n, const int numbers[n]) 
{
    int diff,sorted[n];
    memcpy(sorted,numbers,sizeof(int)*n);
    for(size_t i=0;i<n;i++)
    {
        for(size_t s=0;s<n;s++)
        {
            if(sorted[s]>sorted[i])
            {
                int pos = sorted[i];
                sorted[i] = sorted[s];
                sorted[s] = pos;
            }

        }
    }
    long int smallest = (long int)sorted[0] + sorted[1];
    return smallest;
}

int main()
{
   int numbers[] = {5,3,6,1,7,2};
   long int small = sum_two_smallest_numbers(6,numbers);
   printf("Result %ld\n",small);
}