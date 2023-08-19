#include <stdio.h>
#include <math.h>

const char alpha[] = {'0', '1'};
const int alpha_size = 2;

void setOfStrings(int k) {
    int l = (int)pow(2,k);
    printf("%d\n", l);
    char arr[l][k + 1]; // Add 1 to accommodate the null terminator

    // Initialize all strings with '0'
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < k; j++) {
            arr[i][j] = alpha[0];
        }
        arr[i][k] = '\0'; // Null-terminate the string
    }

    for(int i=0;i<l;i++){
        int num=i;
        int j=k-1;
        while(num>0){
            arr[i][j--]=alpha[num %2];
            num/=2;
        }
    }

    for (int i = 0; i < l; i++) {
        printf("adnan");
        printf("adnan -- %s\n", arr[i]);
    }
}

int main() {
    int k = 3;
    setOfStrings(k);
    return 0;
}
