#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef set<int> StateSet;
typedef vector<StateSet> TransitionTable;

struct NFA {
    int numStates;
    int startState;
    StateSet finalStates;
    TransitionTable transitions;
};

NFA convertToNFA(NFA nfa) {
    // Step 1: Create a copy of the original NFA
    NFA nfa0 = nfa;

    // Step 2: Add states to the final state set
    bool addedNewState;
    do {
        addedNewState = false;
        for (int q : nfa0.finalStates) {
            for (int r = 0; r < nfa0.numStates; r++) {
                if (nfa0.transitions[r][0].count(q) > 0 && nfa0.finalStates.count(r) == 0) {
                    nfa0.finalStates.insert(r);
                    addedNewState = true;
                }
            }
        }
    } while (addedNewState);

    // Step 3: Add missing transitions
    for (int q = 0; q < nfa0.numStates; q++) {
        for (int r = 0; r < nfa0.numStates; r++) {
            for (int s = 0; s < nfa0.numStates; s++) {
                for (int a = 1; a < nfa0.transitions[0].size(); a++) {
                    if (nfa0.transitions[q][0].count(r) > 0 &&
                        nfa0.transitions[r][a].count(s) > 0 &&
                        nfa0.transitions[q][a].count(s) == 0) {
                        nfa0.transitions[q][a].insert(s);
                    }
                }
            }
        }
    }

    // Step 4: Remove epsilon transitions
    for (int q = 0; q < nfa0.numStates; q++) {
        nfa0.transitions[q][0].clear();
    }

    // Step 5: Return the converted NFA
    return nfa0;
}

int main() {
    // Create a sample NFA
    NFA nfa;
    nfa.numStates = 3;
    nfa.startState = 0;
    nfa.finalStates = {2};
    nfa.transitions = {
        {{1}},  // transitions from state 0
        {{2}},  // transitions from state 1
        {{}}    // transitions from state 2
    };

    // Convert the NFA to an equivalent one without epsilon transitions
    NFA nfa0 = convertToNFA(nfa);

    // Print the converted NFA
    cout << "Number of states: " << nfa0.numStates << endl;
    cout << "Start state: " << nfa0.startState << endl;
    cout << "Final states: ";
    for (int q : nfa0.finalStates) {
        cout << q << " ";
    }
    cout << endl;
    cout << "Transitions:" << endl;
    for (int q = 0; q < nfa0.numStates; q++) {
        cout << "From state " << q << ":" << endl;
        for (int a = 0; a < nfa0.transitions[q].size(); a++) {
            cout << "  On input " << a << ": ";
            for (int r : nfa0.transitions[q][a]) {
                cout << r << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
