#include<stdio.h>

unsigned long intmain() {
    unsigned long int n, q;
    scanf("%lu%lu", &n, &q);

    unsigned long int number[n];
    unsigned long int prefixSum[n + 1]; // Array to store the prefix sum

    for ( unsigned long int i = 0; i < n; i++) {
        scanf("%lu", &number[i]);
    }

    // Calculate prefix sum
    prefixSum[0] = 0;
    for (unsigned long int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + number[i - 1];
    }

    for (unsigned long int i = 0; i < q; i++) {
        unsigned long int a, b;
        scanf("%lu%lu", &a, &b);

        unsigned long int sum = prefixSum[b] - prefixSum[a - 1]; // Calculate the sum in O(1) time

        printf("%lu\n", sum);
    }

    return 0;
}
