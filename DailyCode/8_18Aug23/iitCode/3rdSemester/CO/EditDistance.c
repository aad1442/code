#include <stdio.h>
#include <string.h> // Include the string.h header

int s_x = 6, s_y = 5; // Adjusted lengths for "Heater" and "Speak"
char x[20], y[20];
int c[20][20];
char arrow[20][20];

int min(int a, int b, int c) {
    int min_value = a;

    if (b < min_value) {
        min_value = b;
    }

    if (c < min_value) {
        min_value = c;
    }

    return min_value;
}

void printED(char arrow[][20], int i, int j) {
    if (i== 0 && j == 0) {
        return;
    } else {
        if (arrow[i][j] == 'I') {
            printED(arrow, i, j - 1);
            printf("Insert %c: %s -> %s\n", y[j - 1], x, y);
        } else if (arrow[i][j] == 'D') {
            printED(arrow, i - 1, j);
            printf("Delete %c: %s -> %s\n", x[i - 1], x, y);
        } else if (arrow[i][j] == 'S') {
            printED(arrow, i - 1, j - 1);
            printf("Replace %c by %c: %s -> %s\n", x[i - 1], y[j - 1], x, y);
        } else if (arrow[i][j] == 'N') {
            printED(arrow, i - 1, j - 1);
        }
    }
}

int main() {
    // Initialize string arrays using double quotes
    strcpy(x, "Heater");
    strcpy(y, "Speak");

    printf("%d %d %s %s\n", s_x, s_y, x, y); // Print the input values

    for (int i = 0; i <= s_x; i++) {
        for (int j = 0; j <= s_y; j++) {
            if (i == 0) {
                c[i][j] = j;
                arrow[i][j] = 'I';
            } else if (j == 0) {
                c[i][j] = i;
                arrow[i][j] = 'D';
            } else if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1];
                arrow[i][j] = 'N';
            } else {
                c[i][j] = min(c[i - 1][j - 1], c[i - 1][j], c[i][j - 1]) + 1;
                if (c[i][j] == c[i - 1][j - 1] + 1) {
                    arrow[i][j] = 'S';
                } else if (c[i][j] == c[i - 1][j] + 1) {
                    arrow[i][j] = 'D';
                } else if (c[i][j] == c[i][j - 1] + 1) {
                    arrow[i][j] = 'I';
                }
            }
        }
    }

    for (int i = 0; i <= s_x; i++) {
        for (int j = 0; j <= s_y; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n");

    for (int i = 0; i <= s_x; i++) {
        for (int j = 0; j <= s_y; j++) {
            printf("%c ", arrow[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n");

    printED(arrow, s_x, s_y);

    return 0;
}
