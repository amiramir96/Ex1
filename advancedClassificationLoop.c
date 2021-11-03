#include<stdio.h>
#include<math.h>
#include "NumClass.h"


/* will return if a number is prime*/ 
int isPalindrome(int x) {
    int ans = 1;
    if (x==0){
        return ans;
    }
    int digitNum = log10(x) + 1;
    int arr[digitNum];
    for (int i=0; x>0; i++, x = x/10){
        arr[i] = x % 10;
    }  
    for (int j=0, k=digitNum-1; j < digitNum/2; j++, k--){
        if (arr[j] != arr[k]){
            ans = 0;
            break;
        }
    }
    return ans;
}

/* will return if a number is Armstrong number 
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
For Example: 407 = 43 + 03 + 73 = 64 + 0 + 343 = 407
*/
int isArmstrong(int x) {
    int ans = 0;
    int dupX = x;
    if (x == 0){
        return ans;
    }
    int amountOfDigits = log10(x)+1;
    int sum = 0;
    int tempDigit;

    while (dupX > 0){
        tempDigit = dupX % 10;
        sum += pow(tempDigit, amountOfDigits);
        dupX = dupX / 10;
    }
    if (sum == x){
        ans = 1;
    }
    return ans;
}