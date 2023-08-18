#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_ALPHABET 2 // Assuming binary alphabet: 0 and 1

// Define the transition function as a 3D array
int delta[MAX_STATES][MAX_ALPHABET][MAX_STATES];

int main() {
    int n, m;
    int i, j, k;
    char psc, fsc;
    int ps, fs;

    printf("Enter the number of states: ");
    scanf("%d", &n);
    char state[n];
    for (i = 0; i < n; i++) {
        scanf(" %c", &state[i]);
    }

    // Define the alphabet
    char alphabet[MAX_ALPHABET] = {'0', '1'};

    // Initialize the transition function
    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX_ALPHABET; j++) {
            printf("For state %c and input %c, Enter the number of states in the transition (0-%d): ", state[i], alphabet[j], n - 1);
            int num_states;
            scanf("%d", &num_states);
            for (k = 0; k < num_states; k++) {
                printf("Enter the value of delta[%d][%c][%d]: ", i, alphabet[j], k);
                scanf("%d", &delta[i][j][k]);
            }
        }
    }

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

    // Input: Input string
    char input[100];
    printf("Enter the input string: ");
    scanf("%s", input);

    // Simulation: Follow transitions based on input string
    int len = strlen(input);
    bool accepted = false;
    for (i = 0; i < len; i++) {
        int next_states[MAX_STATES];
        int num_next_states = 0;
        int input_index = -1;
        for (j = 0; j < MAX_ALPHABET; j++) {
            if (input[i] == alphabet[j]) {
                input_index = j;
                break;
            }
        }

        if (input_index == -1) {
            printf("Invalid input symbol: %c\n", input[i]);
            return 1; // Exit with error code
        }

        for (k = 0; k < MAX_STATES; k++) {
            if (delta[ps][input_index][k] != -1) {
                next_states[num_next_states++] = delta[ps][input_index][k];
            } else {
                break;
            }
        }

        // Follow all possible transitions and update the current state
        printf("Transition: %c -> {", input[i]);
        for (j = 0; j < num_next_states; j++) {
            if (j > 0) {
                printf(", ");
            }
            printf("%c", state[next_states[j]]);
        }
        printf("}\n");

        if (num_next_states == 0) {
            break; // No valid transitions found
        }

        ps = next_states[0]; // Update current state to the first next state
    }

    // Check if the final state is reached and ends in "01"
    if (ps == fs && input[len - 2] == '0' && input[len - 1] == '1') {
        accepted = true;
    }

    // Output: Acceptance or rejection
    if (accepted) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
