#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char alphabet[] = {'0', '1'};
const int alphabetSize = 2;

// Function to generate a random integer between 'minLength' and 'maxLength'
int randomLength(int minLength, int maxLength) {
    return rand() % (maxLength - minLength + 1) + minLength;
}

// Function to generate a random binary string of given length
void generateRandomBinaryString(int length, char* result) {
    for (int i = 0; i < length; i++) {
        char randomChar = alphabet[rand() % alphabetSize];
        result[i] = randomChar;
    }
    result[length] = '\0'; // Null-terminate the string
}

int main() {
    srand((unsigned)time(NULL)); // Seed the random number generator with current time

    const int numStrings = 5;
    const int minLength = 1;
    const int maxLength = 10;

    printf("Five random binary strings from the alphabet Σ = {0, 1}:\n");
    for (int i = 0; i < numStrings; i++) {
        int length = randomLength(minLength, maxLength);
        char randomBinaryString[length + 1]; // +1 for the null terminator
        generateRandomBinaryString(length, randomBinaryString);
        printf("%s\n", randomBinaryString);
    }

    return 0;
}
