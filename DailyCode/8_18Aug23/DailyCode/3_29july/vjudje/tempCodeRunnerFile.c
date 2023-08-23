#include<stdio.h>

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    int number[n];
    int prefixSum[n + 1]; // Array to store the prefix sum

    for (int i = 0; i < n; i++) {
        scanf("%d", &number[i]);
    }

    // Calculate prefix sum
    prefixSum[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + number[i - 1];
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        int sum = prefixSum[b] - prefixSum[a - 1]; // Calculate the sum in O(1) time

        printf("%d\n", sum);
    }

    return 0;
}
