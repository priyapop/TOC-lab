#include <stdio.h>
#include <string.h>

#define MAX_STATES 10

// Add a state to the list if it's not already there
void add_state(int states[], int *count, int state) {
    for (int i = 0; i < *count; i++) {
        if (states[i] == state) return;
    }
    states[(*count)++] = state;
}

// Check if the given state is accepting
int is_accepting_state(int state) {
    return state == 2;
}

// Transition function for the NFA
void transition(int current[], int current_count, char input, int next[], int *next_count) {
    *next_count = 0;

    for (int i = 0; i < current_count; i++) {
        int state = current[i];
        switch (state) {
            case 0:
                if (input == '0') add_state(next, next_count, 1);
                if (input == '1') add_state(next, next_count, 0);
                break;
            case 1:
                if (input == '0') add_state(next, next_count, 1);
                if (input == '1') add_state(next, next_count, 2);
                break;
            case 2:
                // No transitions from q2
                break;
        }
    }
}

int main() {
    char input[100];
    printf("Enter a binary string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    int current_states[MAX_STATES] = {0}; // Start at q0
    int next_states[MAX_STATES];
    int current_count = 1, next_count;

    for (int i = 0; input[i] != '\0'; i++) {
        transition(current_states, current_count, input[i], next_states, &next_count);

        // Copy next_states to current_states
        memcpy(current_states, next_states, sizeof(int) * next_count);
        current_count = next_count;
    }

    // Check if any current state is accepting
    int accepted = 0;
    for (int i = 0; i < current_count; i++) {
        if (is_accepting_state(current_states[i])) {
            accepted = 1;
            break;
        }
    }

    if (accepted)
        printf("Accepted by the NFA (ends with 01)\n");
    else
        printf("Rejected by the NFA\n");

    return 0;
}
