#include <math.h>

#define TRUE 1
#define FALSE 0

int isPrime(int x){
    int i;

    for(i=sqrt(x); i>1; i--){
        if(x%i == 0){
            return FALSE;
        }
    }
    return TRUE;
}

int _factorial(int x){
    if(x == 0)
        return 1;
    else 
        return (x * _factorial(x-1));
}

int isStrong(int x){
    int sum=0, o=x;
    if(x <= 0)
        return FALSE;

    while(x > 0){
        sum = sum + _factorial(x%10);
        x = x/10;
    }
    if(sum == o)
        return TRUE;

    return FALSE;
}

