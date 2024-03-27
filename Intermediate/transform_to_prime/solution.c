#include <stdbool.h>
#include <stdio.h>
#include <math.h>

bool isprime(int num)
{
    if(num<=1)
        return false;

    for(int i =2;i<= sqrt(num);i++)
    {
        if(num %i == 0)
            return false;
    }
    return true;
}

int minimumNumber(int Numbers[],int count)
{
    int sum =0;
    for(int i = 0; i<count;i++)
        sum += Numbers[i];

    if(isprime(sum))
        return 0;

    int i =0;
    int next_prime = sum;

    while(!isprime(next_prime))
    {
        i++;
        next_prime += i;
    }
    printf("Result: %i\n",next_prime);
    return next_prime -sum;
}

int main()
{
    int Numbers[] = {10,4};
    int nxt = minimumNumber(Numbers,2);
    printf("Add %i to make prime!\n",nxt); 
}
