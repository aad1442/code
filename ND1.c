#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_ALPHABETS 10
#define MAX_TRANSITIONS 10

int compareChars(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}

int main()
{
    //freopen("ND.txt","r",stdin);
    int nState, nAlphabets, nFinishStates;
    char startState;
    char states[MAX_STATES];
    char alphabets[MAX_ALPHABETS];
    char table[MAX_STATES][MAX_ALPHABETS][MAX_TRANSITIONS];
    char finishingStates[MAX_STATES];
    int DFA_table[MAX_STATES][MAX_ALPHABETS];

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

    printf("\n\n");

    for (int i = 0; i < MAX_STATES; i++)
    {
        for (int j = 0; j < MAX_ALPHABETS; j++)
        {
            DFA_table[i][j] = -1;
        }
    }

    // Convert NFA to DFA
    for (int i = 0; i < nState; i++)
    {
        for (int j = 0; j < nAlphabets; j++)
        {
            char combinedStates[MAX_STATES * MAX_TRANSITIONS];
            int combinedCount = 0;

            for (int k = 0; k < MAX_TRANSITIONS && table[i][j][k] != '\0'; k++)
            {
                int nextState = table[i][j][k] - 'A'; // Convert state character to index
                for (int l = 0; l < MAX_TRANSITIONS && table[nextState][j][l] != '\0'; l++)
                {
                    bool exists = false;
                    for (int m = 0; m < combinedCount; m++)
                    {
                        if (combinedStates[m] == table[nextState][j][l])
                        {
                            exists = true;
                            break;
                        }
                    }
                    if (!exists)
                    {
                        combinedStates[combinedCount++] = table[nextState][j][l];
                    }
                }
            }

            combinedStates[combinedCount] = '\0';

            // Find the corresponding state index for the combined states in DFA
            int nextStateIndex = -1;
            for (int k = 0; k < nState; k++)
            {
                if (strcmp(table[k][j], combinedStates) == 0)
                {
                    nextStateIndex = k;
                    break;
                }
            }

            DFA_table[i][j] = nextStateIndex;
        }
    }

    // Print the DFA transition table
    printf("\nDFA Transition Table\n");
    for (int i = 0; i < nState; i++)
    {
        printf("State %c:\t", states[i]);
        for (int j = 0; j < nAlphabets; j++)
        {
            printf("%c -> %c\t", alphabets[j], states[DFA_table[i][j]]);
        }
        printf("\n");
    }

    return 0;
}