#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 10
#define MAX_ALPHABET 10

int main() {
    int n, m;
    int i, j, k;
    char psc, fsc;
    int ps, fs;

    // Input: Number of states
    printf("Enter the number of states: ");
    scanf("%d", &n);
    char state[n];
    for (i = 0; i < n; i++) {
        scanf(" %c", &state[i]);
    }

    // Input: Number of alphabet symbols
    printf("Enter the number of alphabet symbols: ");
    scanf("%d", &m);
    char alphabet[m];
    for (i = 0; i < m; i++) {
        scanf(" %c", &alphabet[i]);
    }

    int mat[MAX_STATES][MAX_ALPHABET][MAX_STATES];

    // Initialize transition matrix
    for (i = 0; i < MAX_STATES; i++) {
        for (j = 0; j < MAX_ALPHABET; j++) {
            for (k = 0; k < MAX_STATES; k++) {
                mat[i][j][k] = -1;
            }
        }
    }

    // Input: Starting state and final state
    printf("Enter the starting state: ");
    scanf(" %c", &psc);
    printf("Enter the final state: ");
    scanf(" %c", &fsc);
    for (i = 0; i < n; i++) {
        if (psc == state[i]) {
            ps = i;
        }
        if (fsc == state[i]) {
            fs = i;
        }
    }

    // Input: Transition table
    printf("Enter the transition table:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("For state %c and alphabet %c, Enter the number of states in the transition (0-10): ", state[i], alphabet[j]);
            int num_states;
            scanf("%d", &num_states);
            for (k = 0; k < num_states; k++) {
                printf("Enter the value of mat[%d][%d][%d]: ", i, j, k);
                scanf("%d", &mat[i][j][k]);
            }
        }
    }

    // Input: Input string
    int strlength;
    printf("Enter the string length: ");
    scanf("%d", &strlength);
    char str[strlength + 1]; // +1 for null-terminator
    scanf("%s", str);

    // Simulation: Follow transitions based on input string
    for (i = 0; str[i] != '\0'; i++) {
        int next_states[MAX_STATES];
        int num_next_states = 0;

        // Collect next states based on current state and input symbol
        for (k = 0; k < MAX_STATES; k++) {
            if (mat[ps][str[i] - '0'][k] != -1) { // Convert char to integer
                next_states[num_next_states++] = mat[ps][str[i] - '0'][k];
            } else {
                break;
            }
        }

        // Follow all possible transitions and update the current state
        for (j = 0; j < num_next_states; j++) {
            ps = next_states[j];
            printf("Transition: %c -> %c\n", str[i], state[ps]);
        }
    }

    // Check if the final state is reached
    bool isAccepted = false;
    for (k = 0; k < MAX_STATES; k++) {
        if (ps == fs) {
            isAccepted = true;
            break;
        }
    }

    // Output: Acceptance or rejection
    if (isAccepted) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
