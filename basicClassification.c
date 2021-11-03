#include<stdio.h>
#include<math.h>
#include "NumClass.h"


/* will return if a number is prime*/
int isPrime(int x) {
    int ans = 1;
    int sqrtX = sqrt(x);
    int i = 2;
    if (x == 0){
        return 0;
    }
    while (i <= sqrtX){
        if (x%i == 0){
            ans = 0;
            break;
        }
        i++;
    }

    return ans;
}

/*Strong number is a special number whose sum of the factorial of digits is equal to the original 
number. For Example: 145 is strong number
1! + 4! + 5! = 145
*/
int isStrong(int x) {
    int ans = 0;
    int dupX = x, sum=0, fact=1;
    int tempDigit;
//    int i=0;

    while (dupX > 0){
        tempDigit = dupX % 10;
        if (tempDigit == 0){
            tempDigit++;
        }
        for (int j=1; j <= tempDigit; j++){ //factorial for that digit
            fact = fact * j; 
        }
        sum += fact; 
        fact = 1;
        dupX = dupX / 10;
    }

    if (x == sum){
        ans = 1;
    }
    return ans;
}
