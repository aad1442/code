#include<stdio.h>
#define max 100
int mat[max];

int fibonacci(int n, int *steps) {
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
    int fib = fibonacci(n, &steps);
    printf("Fibonacci of %d is %d\n", n, fib);
    printf("Steps taken: %d\n", steps);

    return 0;
}
