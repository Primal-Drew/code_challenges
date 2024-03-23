#include <stddef.h>
// Using qsort

int cmpnum(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

long sum_two_smallest_numbers(size_t n, const int numbers[n])
{
    qsort(numbers, n, sizeof(int), cmpnum);
    long num1 = (long)numbers[0];
    long num2 = (long)numbers[1];
    return num1 + num2;
}