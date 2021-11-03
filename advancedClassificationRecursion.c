#include <stdio.h>
#include <math.h>
#include "NumClass.h"


/**
 * the recursive func, will switch the input number sides
*/
int reverseNum(int num){
    if (num == 0){
        return 0;
    }
    int numOfDigits = log10(num);
    int a = num % 10;
    return a*pow(10, numOfDigits) + reverseNum(num/10);
}
/**
 *  will return if a number is prime
 * this time with recursive
 * */ 
int isPalindrome(int x) {
    if (x == reverseNum(x)){
        return 1;
    }
    else {
        return 0;
    }
}




/* will return if a number is Armstrong number 
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
For Example: 407 = 43 + 03 + 73 = 64 + 0 + 343 = 407
*/

int isArmstrongHelper(int num, int d) {
    if (num == 0){
        return 0;
    }
    int currOneness = num % 10;
    return pow(currOneness, d) + isArmstrongHelper(num/10, d);
}


int isArmstrong(int x) {
    int numOfDigits = log10(x) + 1;
    if (x == isArmstrongHelper(x, numOfDigits)){
        return 1;
    }
    else {
        return 0;
    }
}


// void main(){
//     int a = 407;
//     printf("%d", isArmstrong(a));
// }



