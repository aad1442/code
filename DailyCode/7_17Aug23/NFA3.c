#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 4
#define MAX_ALPHABET 2 // Binary alphabet: 0 and 1

int main() {
    int i, j, k;
    int ps = 0; // Start state
    int fs = 3; // Final state

    // Transition function
    int delta[MAX_STATES][MAX_ALPHABET][MAX_STATES] = {
        {{0}, {0, 1}}, // δ(q0, 0), δ(q0, 1)
        {{}, {2}},     // δ(q1, 0), δ(q1, 1)
        {{3}, {}},     // δ(q2, 0), δ(q2, 1)
        {{3}, {2}}     // δ(q3, 0), δ(q3, 1)
    };

    // Alphabet
    char alphabet[MAX_ALPHABET] = {'0', '1'};

    // Input: Input string
    char input[100];
    printf("Enter the input string: ");
    scanf("%s", input);

    // Simulation: Follow transitions based on input string
    int len = strlen(input);
    bool accepted = false;
    for (i = 0; i < len; i++) {
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

        int next_states[MAX_STATES];
        int num_next_states = 0;
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
            printf("q%d", next_states[j]);
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
