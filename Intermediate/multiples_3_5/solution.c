#include <stdio.h>
#include <stdlib.h>

int solution(int number)
{   
    if(number<0)
        return 0;

    int result = 0;
    for(int three =0;three<number;three +=3)
    {
        if(three%5==0)
        {
            continue;
        }
        result += three; 
    }

    for(int five=0;five<number;five +=5)
    {
        result += five;
    }
    return result;
}

int main()
{
    printf("%d",solution(60));
}