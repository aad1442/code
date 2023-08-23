#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to calculate the unique characters in two strings
void uniqChar(char *x, char *y, char *result) {
    int resIndex = 0;
    bool charSet[256] = {false}; // Assuming ASCII characters

    // Process string x
    for (int i = 0; i < strlen(x); i++) {
        if (!charSet[x[i]]) {
            result[resIndex++] = x[i];
            charSet[x[i]] = true;
        }
    }

    // Process string y
    for (int i = 0; i < strlen(y); i++) {
        if (!charSet[y[i]]) {
            result[resIndex++] = y[i];
            charSet[y[i]] = true;
        }
    }

    result[resIndex] = '\0'; // Null-terminate the resulting string
}

int main() {
    char x[] = "abcdef";
    char y[] = "defgh";
    char result[256]; // Assuming maximum length of the resulting string

    uniqChar(x, y, result);

    printf("Unique characters: %s\n", result);

    return 0;
}
