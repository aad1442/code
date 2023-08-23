#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_ALPHABETS 10
#define MAX_TRANSITIONS 10

char *uniqChar(char *x, char *y) {
    char res[MAX_STATES];
    int resSize = 0;

    for (int i = 0; i < strlen(x); i++) {
        bool exists = false;
        for (int j = 0; j < resSize; j++) {
            if (res[j] == x[i]) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            res[resSize++] = x[i];
        }
    }

    for (int i = 0; i < strlen(y); i++) {
        bool exists = false;
        for (int j = 0; j < resSize; j++) {
            if (res[j] == y[i]) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            res[resSize++] = y[i];
        }
    }

    char *ans = (char *)malloc((resSize + 1) * sizeof(char));
    strncpy(ans, res, resSize);
    ans[resSize] = '\0';
    return ans;
}

int main() {
    int nState, nAlphabets, nFinishStates;
    char startState;
    char states[MAX_STATES];
    char alphabets[MAX_ALPHABETS];
    char table[MAX_STATES][MAX_ALPHABETS][MAX_TRANSITIONS];
    char finishingStates[MAX_STATES];
    int dfaCount = 0;
    char dTable[MAX_STATES][MAX_ALPHABETS][MAX_STATES];
    bool done[MAX_STATES];
    char DFA[MAX_STATES][MAX_ALPHABETS][MAX_STATES];
    char track[MAX_STATES][MAX_ALPHABETS][MAX_STATES];

    //--------------------------------------INPUT---------------------------------------
    printf("Enter number of states: ");
    scanf("%d", &nState);

    for (int i = 0; i < nState; i++) {
        printf("State %d: ", i + 1);
        scanf(" %c", &states[i]);
    }

    printf("Enter number of alphabets: ");
    scanf("%d", &nAlphabets);

    for (int i = 0; i < nAlphabets; i++) {
        printf("Alphabet %d: ", i + 1);
        scanf(" %c", &alphabets[i]);
    }

    printf("Enter the state Transition Table:\n");
    for (int i = 0; i < nState; i++) {
        printf("State %c transitions:\n", states[i]);
        for (int j = 0; j < nAlphabets; j++) {
            scanf(" %c", &table[i][j][0]); // First transition state
            if (table[i][j][0] == 'X') {
                table[i][j][0] = '\0'; // Empty transition
            } else {
                int k = 1;
                while (true) {
                    char next_state;
                    scanf(" %c", &next_state);
                    if (next_state == 'X') {
                        break;
                    }
                    table[i][j][k++] = next_state;
                }
                table[i][j][k] = '\0';
            }
        }
    }

    printf("Enter the start state: ");
    scanf(" %c", &startState);

    printf("How many finishing states do you have: ");
    scanf("%d", &nFinishStates);

    for (int i = 0; i < nFinishStates; i++) {
        printf("Finishing state %d: ", i + 1);
        scanf(" %c", &finishingStates[i]);
    }

    //--------------------------------------OUTPUT 1---------------------------------------

printf("\nTransition Table for NFA\n");
// header of the table
printf("\t\t");
for (int i = 0; i < nAlphabets; i++) {
    printf("%c\t\t", alphabets[i]);
}
printf("\n-----------------------------------------\n");

// table info
for (int i = 0; i < nState; i++) {
    bool isStartState = (states[i] == startState);
    bool isFinishState = false;
    for (int j = 0; j < nFinishStates; j++) {
        if (states[i] == finishingStates[j]) {
            isFinishState = true;
            break;
        }
    }

    if (isStartState)
        printf("->%c\t\t", states[i]);
    else {
        if (isFinishState)
            printf(" *%c\t\t", states[i]);
        else
            printf("  %c\t\t", states[i]);
    }

    for (int j = 0; j < nAlphabets; j++) {
        // Check if the transition has multiple states
        if (strlen(table[i][j]) > 0) {
            printf("{%s}\t\t", table[i][j]);
        } else {
            printf("-\t\t"); // No transition
        }
    }

    printf("\n");
}

printf("\n\n");


    //--------------------------------------NFA TO DFA PROCESSING---------------------------------------

    // now making the dfa table from NFA
    strcpy(dTable[0][0], table[0][0]);
    strcpy(dTable[0][1], table[0][1]);

    strcpy(dTable[1][0], table[0][2]);
    strcpy(dTable[1][1], table[0][1] + 1);

    dfaCount++;

    // ... (remaining code)

    //--------------------------------------FINAL OUTPUT---------------------------------------

    printf("\nTransition Table for DFA\n");
    // header of the table
    printf("\t\t");
    for (int i = 0; i < nAlphabets; i++) {
        printf("%c\t\t", alphabets[i]);
    }
    printf("\n-----------------------------------------\n");

    // DFA table info
    for (int i = 0; i < dfaCount; i++) {
        bool isStartState = (i == 0);
        bool isFinishState = false;
        for (int j = 0; j < nFinishStates; j++) {
            if (DFA[i][0][0] == finishingStates[j]) {
                isFinishState = true;
                break;
            }
        }

        if (isStartState)
            printf("->%c\t\t", DFA[i][0][0]);
        else {
            if (isFinishState)
                printf(" *%c\t\t", DFA[i][0][0]);
            else
                printf("  %c\t\t", DFA[i][0][0]);
        }

        for (int j = 0; j < nAlphabets; j++) {
            printf("%s\t\t", DFA[i][j]);
        }

        printf("\n");
    }

    return 0;
}
