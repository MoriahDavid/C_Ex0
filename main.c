#include <stdio.h>
#include <stdlib.h>
#include "NumClass.h"

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int main(void){
    int x;
    int y;

    scanf("%d%d", &x, &y);
    int range = abs(y-x);
    int j = min(x,y);
    printf("The Armstrong numbers are:");
    for(int i = j; i < j+range+1; i++){
        if(isArmstrong(i)){
            printf(" %d", i);
        }
    }
    printf("\nThe Palindromes are:");

       for(int i = j; i < j+range+1; i++){
        if(isPalindrome(i)){
            printf(" %d", i);
        }
    }
    printf("\nThe Prime numbers are:");
    for(int i = j; i < j+range+1; i++){
        if(isPrime(i)){
            printf(" %d", i);
        }
    }
    printf("\nThe Strong numbers are:");
    for(int i = j; i < j+range+1; i++){
        if(isStrong(i)){
            printf(" %d", i);
        }
    }
    printf("\n");

    return 0;
}