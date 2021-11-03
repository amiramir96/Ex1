#include<stdio.h>
#include<math.h>
#include "NumClass.h"

void main(){
    int start, stop;
    scanf("%d %d", &start, &stop);

    printf("The Armstrong numbers are:");
    for (int j=start; j <= stop; j++){//print armstrongs
        if (1 == isArmstrong(j)){
            printf(" %d ", j);
        }
    }
    printf("\n");

    printf("The Palindromes are:");
    for (int l=start; l <= stop; l++){//print palindromes
        if (1 == isPalindrome(l)){
            printf(" %d ", l);
        }
    }
    printf("\n");

    printf("The Prime numbers are:");
    for (int i=start; i <= stop; i++){//print primes
        if (1 == isPrime(i)){
            printf(" %d ", i);
        }
    }
    printf("\n");

    printf("The Strong numbers are:");
    for (int k=start; k <= stop; k++){//print strongs
        if (1 == isStrong(k)){
            printf(" %d ", k);
        }
    }

}
