#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num < 2)
        return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int num = 8;
    printf("Enter a number: ");
    
    int fact = factorial(num);
    printf("Factorial of %d is %d\n", num, fact);
    
    if (is_prime(fact))
        printf("The factorial is a prime number.\n");
    else
        printf("The factorial is not a prime number.\n");
    main();
    return 0;
}
