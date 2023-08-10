#include<stdio.h>

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    int number[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &number[i]);
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int sum = 0;
        for (int j = a - 1; j < b; j++) {
            sum += number[j];
        }
        printf("%d\n", sum);
    }

    return 0;
}
