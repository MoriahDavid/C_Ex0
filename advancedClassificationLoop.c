#include <math.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int _intLen (int x){
    int l = 1;
    while(x>9){
        x = x/10;
        l++;
    }
    return l;
}

int isPalindrome (int x){
    int i;
    int num = x;
    int sum = 0;
    while(_intLen(num)!=1){
        i = num%10;
        sum = sum + i*pow(10, _intLen(num)-1);
        num = num/10;
    }
    if(sum+num == x){
        return TRUE;
    }
    return FALSE;
}

int isArmstrong(int x){
    int sum=0;
    int n, o=x;
    int l = _intLen(x);
    while(x>0){
        n = x%10; // the last digit
        sum = sum + (pow(n, l));
        x = x/10;
    }

    if(sum==o){
        return TRUE;
    }
    return FALSE;
}
