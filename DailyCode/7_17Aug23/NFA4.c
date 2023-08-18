#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 100
#define MAX_ALPHABET 2

typedef struct {
    char state[MAX_STATES][10]; // Increase size if needed
    char alphabet[MAX_ALPHABET];
    int transitions[MAX_STATES][MAX_ALPHABET][MAX_STATES];
    int start_state;
    int final_state;
} NFA;

void initializeNFA(NFA *nfa) {
    strcpy(nfa->state[0], "q0");
    strcpy(nfa->state[1], "q1");
    strcpy(nfa->state[2], "q2");

    strcpy(nfa->alphabet, "01");

    nfa->start_state = 0;
    nfa->final_state = 2;

    // Initialize all transitions to -1
    for (int i = 0; i < MAX_STATES; i++) {
        for (int j = 0; j < MAX_ALPHABET; j++) {
            for (int k = 0; k < MAX_STATES; k++) {
                nfa->transitions[i][j][k] = -1;
            }
        }
    }

    // Transition table
    nfa->transitions[0][0][0] = 0;
    nfa->transitions[0][0][1] = 0;
    nfa->transitions[0][1][0] = 0;
    nfa->transitions[0][1][1] = 1;

    nfa->transitions[1][0][0] = -1;
    nfa->transitions[1][0][1] = -1;
    nfa->transitions[1][1][0] = -1;
    nfa->transitions[1][1][1] = -1;

    nfa->transitions[2][0][0] = 0;
    nfa->transitions[2][0][1] = 0;
    nfa->transitions[2][1][0] = 2;
    nfa->transitions[2][1][1] = 2;
}

bool processInput(NFA *nfa, char input_string[]) {
    int current_states[MAX_STATES];
    int current_states_count = 1;
    current_states[0] = nfa->start_state;

    for (int i = 0; input_string[i] != '\0'; i++) {
        int new_states[MAX_STATES];
        int new_states_count = 0;

        for (int j = 0; j < current_states_count; j++) {
            int state = current_states[j];
            int symbol_idx = input_string[i] - '0';

            for (int k = 0; nfa->transitions[state][symbol_idx][k] != -1; k++) {
                new_states[new_states_count++] = nfa->transitions[state][symbol_idx][k];
            }
        }

        current_states_count = new_states_count;
        memcpy(current_states, new_states, sizeof(int) * new_states_count);
    }

    for (int i = 0; i < current_states_count; i++) {
        if (current_states[i] == nfa->final_state) {
            return true;
        }
    }

    return false;
}

int main() {
    NFA nfa;
    initializeNFA(&nfa);

    char input_string[100];
    printf("Enter an input string: ");
    scanf("%s", input_string);

    if (processInput(&nfa, input_string)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
