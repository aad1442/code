#include <stdio.h>

int main() {
    char* arr[5]; // Declare an array of 5 character pointers

    // Allocate memory for and assign strings to the array elements
    arr[0] = "Hello";
    arr[1] = "World";
    arr[2] = "from";
    arr[3] = "C";
    arr[4] = "programming";

    // Access and print the strings using the array
    for (int i = 0; i < 5; i++) {
        printf("String %d: %s\n", i, arr[i]);
    }

    return 0;
}
