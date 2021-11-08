#include <math.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int _numCount(int x){
    if(x>9)
        return 1 + _numCount(x/10);
    return 1;
}

int _powSum(int x, int l){
    if(x>9){
        return pow((x%10), l) + _powSum(x/10, l);
    }
    return pow(x, l);
}

int isArmstrong(int x){
    return(x == _powSum(x,_numCount(x)));
}

int _reverse(int x){
    int len=_numCount(x);
    if(x==0)
        return 0;

    return (x%10 * pow(10, len-1)) + _reverse(x/10);
}

int isPalindrome(int x){
    if(x == _reverse(x))
        return TRUE;
    
    return FALSE;
}