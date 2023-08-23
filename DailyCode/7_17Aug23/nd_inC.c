#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STATES 100
#define MAX_ALPHABET 100

char* uniqChar(char* x, char* y) {
    char* res = (char*)malloc(256 * sizeof(char));
    int resIdx = 0;

    for (int i = 0; i < strlen(x); i++) {
        bool found = false;
        for (int j = 0; j < resIdx; j++) {
            if (res[j] == x[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            res[resIdx++] = x[i];
        }
    }

    for (int i = 0; i < strlen(y); i++) {
        bool found = false;
        for (int j = 0; j < resIdx; j++) {
            if (res[j] == y[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            res[resIdx++] = y[i];
        }
    }
    res[resIdx] = '\0';
    return res;
}

int main() {

    int nState, nAlphabets, nFinishStates;
    char startState[10];
    char states[MAX_STATES][10];
    char alphabets[MAX_ALPHABET][10];
    char table[MAX_STATES][MAX_ALPHABET][10];
    char dTable[MAX_STATES][MAX_ALPHABET][10];
    char finishingStates[MAX_STATES][10];
    char done[MAX_STATES][10];
    char DFA[MAX_STATES][10];
    char track[MAX_STATES][10];

    //--------------------------------------INPUT---------------------------------------
    printf("Enter number of states: ");
    scanf("%d", &nState);

    for (int i = 0; i < nState; i++) {
        printf("State %d: ", i + 1);
        scanf("%s", states[i]);
    }

    printf("Enter number of alphabets: ");
    scanf("%d", &nAlphabets);

    for (int i = 0; i < nAlphabets; i++) {
        printf("Alphabet %d: ", i + 1);
        scanf("%s", alphabets[i]);
    }

    printf("Enter the state Transition Table:\n");
    for (int i = 0; i < nState; i++) {
        scanf("%s", table[i][0]);

        for (int j = 0; j < nAlphabets; j++) {
            scanf("%s", table[i][j + 1]);
        }
    }

    printf("Enter the start state: ");
    scanf("%s", startState);

    printf("How many finishing states do you have: ");
    scanf("%d", &nFinishStates);

    for (int i = 0; i < nFinishStates; i++) {
        scanf("%s", finishingStates[i]);
    }

    //--------------------------------------OUTPUT 1---------------------------------------

    printf("\nTransition Table for NFA\n");
    // header of the table
    for (int i = 0; i < nAlphabets; i++) {
        printf("\t\t%s", alphabets[i]);
    }
    printf("\n-----------------------------------------\n");

    // table info
    for (int i = 0; i < nState; i++) {
        if (strcmp(table[i][0], startState) == 0)
            printf("->%s\t\t", table[i][0]);
        else {
            bool isFinishing = false;
            for (int k = 0; k < nFinishStates; k++) {
                if (strcmp(table[i][0], finishingStates[k]) == 0) {
                    isFinishing = true;
                    break;
                }
            }
            if (isFinishing)
                printf(" *%s\t\t", table[i][0]);
            else
                printf("  %s\t\t", table[i][0]);
        }

        for (int j = 0; j < nAlphabets; j++) {
            printf("%s\t\t", table[i][j + 1]);
        }

        printf("\n");
    }

    printf("\n\n");

    //--------------------------------------NFA TO DFA PROCESSING---------------------------------------

    // now making the dfa table from NFA; a , a bc
    strcpy(dTable[0][0], table[0][0]);
    for (int i = 0; i < nAlphabets; i++)
        strcpy(track[i], table[0][i + 1]);

    strcpy(done[0], table[0][0]);

    while (1) {
        if (track[0][0] == '\0')
            break;

        char pState[10];
        strcpy(pState, track[0]);
        strcpy(track[0], "");

        if (strstr(done[0], pState))
            continue;

        char newDFASubState[10];
        char indivStates[MAX_STATES][10];
        char tmp[MAX_STATES][10];

        int indivStatesCount = 0;
        for (int k = 0; k < strlen(pState); k++) {
            if (isalpha(pState[k])) {
                char xx[2];
                xx[0] = pState[k];
                xx[1] = '\0';
                strcpy(indivStates[indivStatesCount++], xx);
            }
        }

        for (int i = 0; i < nAlphabets; i++) {
            for (int j = 0; j < indivStatesCount; j++) {
                for (int k = 0; k < nState; k++) {
                    if (strcmp(table[k][0], indivStates[j]) == 0 && strcmp(table[k][i + 1], "phi") != 0) {
                        char* tmpRes = uniqChar(newDFASubState, table[k][i + 1]);
                        strcpy(newDFASubState, tmpRes);
                        strcat(newDFASubState, "");
                        free(tmpRes);
                        break;
                    }
                }
            }

            strcpy(tmp[i], newDFASubState);

            int isPresent = 0;
            for (int j = 0; j < MAX_STATES; j++) {
                if (strcmp(DFA[j], newDFASubState) == 0) {
                    isPresent = 1;
                    break;
                }
            }
            if (!isPresent) {
                strcpy(DFA[i], newDFASubState);
                strcpy(track[i], newDFASubState);
            }
            newDFASubState[0] = '\0';
        }

        strcat(done[0], pState);
        strcpy(dTable[0][0], pState);
        for (int i = 0; i < nAlphabets; i++) {
            strcpy(dTable[0][i + 1], tmp[i]);
        }
        for (int i = 0; i < nAlphabets; i++) {
            strcpy(track[i], "");
        }
    }

    //--------------------------------------FINAL OUTPUT---------------------------------------

    printf("Transition Table for DFA\n");
    // header of the table
    for (int i = 0; i < nAlphabets; i++) {
        printf("\t\t%s", alphabets[i]);
    }
    printf("\n-----------------------------------------\n");

    // DFA table info
    for (int i = 0; i < nState; i++) {

        if (i == 0)
            printf("->%s\t\t", dTable[i][0]);
        else {
            int flag = 1;
            for (int j = 0; j < strlen(dTable[i][0]); j++) {
                char ch = dTable[i][0][j];
                char s[2];
                s[0] = ch;
                s[1] = '\0';

                for (int k = 0; k < nFinishStates; k++) {
                    if (strcmp(s, finishingStates[k]) == 0) {
                        printf(" *%s\t\t", dTable[i][0]);
                        flag = 0;
                        break;
                    }
                }
            }

            if (flag)
                printf("%s\t\t", dTable[i][0]);
        }

        for (int j = 0; j < nAlphabets; j++) {
            printf("%s\t\t", dTable[i][j + 1]);
        }

        printf("\n");
    }
    return 0;
}
