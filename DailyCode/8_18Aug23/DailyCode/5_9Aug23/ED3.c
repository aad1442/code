#include <stdio.h>
#include <string.h> // Include the string.h header

int s_x = 6, s_y = 5;
char x[20], y[20];

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

// void printDE(char c[][20],char arrow[][], int i,int j){
//     if(i==0 || j== 0 ){
//         return ;
//     }else if(arrow[i][j]=='I'){

//     }
// }

int main() {
    //freopen("Ed.txt", "r", stdin);
    //int s_x, s_y;
    //scanf("%d", &s_x);
    //scanf("%d", &s_y);

    // Initialize string arrays using double quotes
    strcpy(x, "Heater");
    strcpy(y, "Speak");

    //scanf("%s %s", x, y);
    printf("%d %d %s %s\n", s_x, s_y, x, y); // Print the input values

    int c[s_x + 1][s_y + 1]; // Adding +1 to create a matrix of size (s_x + 1) x (s_y + 1)
    char arrow[s_x + 1][s_y + 1]; // Using char to store operation symbols

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
                if (c[i][j] == c[i - 1][j - 1]) {
                    arrow[i][j] = 'S';
                } else if (c[i][j] == c[i - 1][j]) {
                    arrow[i][j] = 'D';
                } else if (c[i][j] == c[i][j - 1]) {
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

    return 0;
}
