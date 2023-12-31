#include<stdio.h>
#define max 100
long int mat[max];

long int fibonacci(int n, int *steps) {
    (*steps)++;
    if(mat[n] != -1){
        return mat[n];
    }
    if(n < 2){
        mat[n] = n;
    }else{
        mat[n] = fibonacci(n - 1, steps) + fibonacci(n - 2, steps);
    }
    return mat[n];
}

int main() {
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    for(int i = 0; i <= n; i++) {
        mat[i] = -1;
    }

    int steps = 0;
    long int fib = fibonacci(n, &steps);
    printf("Fibonacci of %d is %ld\n", n, fib);
    printf("Steps taken: %d\n", steps);

    return 0;
}
