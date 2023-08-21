#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STATES 10
#define MAX_ALPHABETS 10
#define MAX_TRANSITIONS 10

struct StateSet {
    int states[MAX_STATES];
    int size;
};

int compareChars(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}

int main()
{
    freopen("ND.txt", "r", stdin);
    int nState, nAlphabets, nFinishStates;
    char startState;
    char states[MAX_STATES];
    char alphabets[MAX_ALPHABETS];
    char table[MAX_STATES][MAX_ALPHABETS][MAX_TRANSITIONS];
    char finishingStates[MAX_STATES];
    StateSet DFA_table[MAX_STATES][MAX_ALPHABETS];
    //--------------------------------------INPUT---------------------------------------
    printf("Enter number of states: ");
    scanf("%d", &nState);

    for (int i = 0; i < nState; i++)
    {
        printf("State %d: ", i + 1);
        scanf(" %c", &states[i]);
    }

    printf("Enter number of alphabets: ");
    scanf("%d", &nAlphabets);

    for (int i = 0; i < nAlphabets; i++)
    {
        printf("Alphabet %d: ", i + 1);
        scanf(" %c", &alphabets[i]);
    }

    printf("Enter the state Transition Table:\n");
    for (int i = 0; i < nState; i++)
    {
        printf("State %c transitions:\n", states[i]);
        for (int j = 0; j < nAlphabets; j++)
        {
            printf("For Alphabet %c\n", alphabets[j]);
            scanf(" %c", &table[i][j][0]); // First transition state
            if (table[i][j][0] == 'x')
            {
                table[i][j][0] = '\0'; // Empty transition
            }
            else
            {
                int k = 1;
                while (true)
                {
                    char next_state;
                    scanf(" %c", &next_state);
                    if (next_state == 'x')
                    {
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

    for (int i = 0; i < nFinishStates; i++)
    {
        printf("Finishing state %d: ", i + 1);
        scanf(" %c", &finishingStates[i]);
    }

    //--------------------------------------OUTPUT 1---------------------------------------
    printf("\nTransition Table for NFA\n");
    // header of the table
    printf("\t\t");
    for (int i = 0; i < nAlphabets; i++)
    {
        printf("%c\t\t", alphabets[i]);
    }
    printf("\n-----------------------------------------\n");

    // table info
    for (int i = 0; i < nState; i++)
    {
        bool isStartState = (states[i] == startState);
        bool isFinishState = false;
        for (int j = 0; j < nFinishStates; j++)
        {
            if (states[i] == finishingStates[j])
            {
                isFinishState = true;
                break;
            }
        }

        if (isStartState)
            printf("->%c\t\t", states[i]);
        else
        {
            if (isFinishState)
                printf(" *%c\t\t", states[i]);
            else
                printf("  %c\t\t", states[i]);
        }

        for (int j = 0; j < nAlphabets; j++)
        {
            // Check if the transition has multiple states
            if (strlen(table[i][j]) > 0)
            {
                printf("{%s}\t\t", table[i][j]);
            }
            else
            {
                printf("-\t\t"); // No transition
            }
        }

        printf("\n");
    }

    //--------------------------------------NFA to DFA Conversion---------------------------------------
    for (int i = 0; i < MAX_STATES; i++)
    {
        for (int j = 0; j < MAX_ALPHABETS; j++)
        {
            DFA_table[i][j].size = 0;
        }
    }

    // Convert NFA to DFA
    StateSet startSet;
    startSet.states[0] = startState - 'a';
    startSet.size = 1;
    DFA_table[0][0] = startSet;

    int dfaStateCount = 1;
    for (int i = 0; i < dfaStateCount; i++)
    {
        for (int j = 0; j < nAlphabets; j++)
        {
            StateSet combinedSet;
            combinedSet.size = 0;

            for (int k = 0; k < DFA_table[i][0].size; k++)
            {
                int nfaState = DFA_table[i][0].states[k];
                for (int l = 0; l < MAX_TRANSITIONS && table[nfaState][j][l] != '\0'; l++)
                {
                    int nextState = table[nfaState][j][l] - 'a';
                    combinedSet.states[combinedSet.size++] = nextState;
                }
            }

            // Remove duplicates from the combined set
            qsort(combinedSet.states, combinedSet.size, sizeof(int), compareChars);
            int newSize = 0;
            for (int k = 0; k < combinedSet.size; k++)
            {
                if (k == 0 || combinedSet.states[k] != combinedSet.states[k - 1])
                {
                    combinedSet.states[newSize++] = combinedSet.states[k];
                }
            }
            combinedSet.size = newSize;

            // Check if the combined set is a new state
            bool isNewState = true;
            for (int k = 0; k < dfaStateCount; k++)
            {
                if (memcmp(&DFA_table[k][0], &combinedSet, sizeof(StateSet)) == 0)
                {
                    DFA_table[i][j] = DFA_table[k][0];
                    isNewState = false;
                    break;
                }
            }

            if (isNewState)
            {
                memcpy(&DFA_table[dfaStateCount][0], &combinedSet, sizeof(StateSet));
                DFA_table[i][j] = combinedSet;
                dfaStateCount++;
            }
        }
    }

    //--------------------------------------OUTPUT 2---------------------------------------
    printf("\nDFA Transition Table\n");
    // header of the table
    printf("\t\t");
    for (int i = 0; i < nAlphabets; i++)
    {
        printf("%c\t\t", alphabets[i]);
    }
    printf("\n-----------------------------------------\n");

    // table info
    for (int i = 0; i < dfaStateCount; i++)
    {
        printf("State ");
        for (int k = 0; k < DFA_table[i][0].size; k++)
        {
            printf("%c", states[DFA_table[i][0].states[k]]);
            if (k < DFA_table[i][0].size - 1)
            {
                printf(",");
            }
        }
        printf(":\t");
        for (int j = 0; j < nAlphabets; j++)
        {
            int nextState = DFA_table[i][j].states[0];
            printf("%c\t\t", states[nextState]);
        }
        printf("\n");
    }

    return 0;
}