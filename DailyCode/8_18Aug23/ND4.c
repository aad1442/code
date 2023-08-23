#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_ALPHABET 10

typedef struct {
    int count;
    char symbols[MAX_ALPHABET];
} Alphabet;

typedef struct {
    int count;
    char states[MAX_STATES];
} StateSet;

typedef struct {
    StateSet states[MAX_STATES];
    Alphabet alphabet;
    char table[MAX_STATES][MAX_ALPHABET][MAX_STATES + 1]; // +1 for '\0'
    char startState;
    StateSet finishingStates;
} NFA;

typedef struct {
    StateSet states[MAX_STATES];
    Alphabet alphabet;
    int transitions[MAX_STATES][MAX_ALPHABET];
    int startState;
    StateSet acceptStates;
} DFA;

StateSet epsilonClosure(NFA *nfa, StateSet states) {
    // Similar to the previous example
    // Implement epsilonClosure function here
}

StateSet move(NFA *nfa, StateSet states, char symbol) {
    // Similar to the previous example
    // Implement move function here
}

// Function to convert NFA to DFA
DFA convertNFAtoDFA(NFA *nfa) {
    DFA dfa;
    // Initialize DFA based on NFA
    // Implement the DFA conversion logic here
    
    return dfa;
}

int main() {
    NFA nfa;
    // Input NFA details from the user
    // ...
    
    DFA dfa = convertNFAtoDFA(&nfa);
    
    // Print DFA details
    // ...
    
    return 0;
}
