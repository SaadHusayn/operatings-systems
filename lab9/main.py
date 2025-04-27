import graphviz

class NFA:
    def _init_(self, states, alphabet, transitions, initial_state, accepting_states):
        self.states = states
        self.alphabet = alphabet
        self.transitions = transitions
        self.initial_state = initial_state
        self.accepting_states = accepting_states

    def epsilon_closure(self, states):
        epsilon_closure_set = set(states)
        stack = list(states)

        while stack:
            state = stack.pop()
            if state in self.transitions and '' in self.transitions[state]:
                for epsilon_state in self.transitions[state]['']:
                    if epsilon_state not in epsilon_closure_set:
                        epsilon_closure_set.add(epsilon_state)
                        stack.append(epsilon_state)

        return epsilon_closure_set

    def compute_transition(self, states, symbol):
        result_set = set()
        for state in states:
            if state in self.transitions and symbol in self.transitions[state]:
                result_set |= self.transitions[state][symbol]
        return self.epsilon_closure(result_set)

    def convert_to_dfa(self):
        dfa_states = []
        dfa_transitions = {}
        dfa_initial_state = self.epsilon_closure({self.initial_state})
        dfa_accepting_states = []

        stack = [dfa_initial_state]
        visited = set()

        while stack:
            current_states = stack.pop()
            if current_states in visited:
                continue
            visited.add(current_states)
            dfa_states.append(current_states)

            for symbol in self.alphabet:
                new_state = self.compute_transition(current_states, symbol)
                if new_state:
                    dfa_transitions.setdefault(current_states, {})[symbol] = new_state
                    if new_state not in visited:
                        stack.append(new_state)

            if any(state in self.accepting_states for state in current_states):
                dfa_accepting_states.append(current_states)

        return DFA(dfa_states, self.alphabet, dfa_transitions, dfa_initial_state, dfa_accepting_states)

class DFA:
    def _init_(self, states, alphabet, transitions, initial_state, accepting_states):
        self.states = states
        self.alphabet = alphabet
        self.transitions = transitions
        self.initial_state = initial_state
        self.accepting_states = accepting_states

    def to_dot(self):
        dot = graphviz.Digraph(format='png')
        dot.attr('node', shape='circle')
        
        for state in self.states:
            if state in self.accepting_states:
                dot.node(state, shape='doublecircle')
            else:
                dot.node(state)
        
        for start_state, transitions in self.transitions.items():
            for symbol, end_state in transitions.items():
                dot.edge(start_state, end_state, label=symbol)
        
        return dot

def get_user_input():
    states = input("Enter states separated by commas: ").split(',')
    alphabet = input("Enter alphabet symbols separated by commas: ").split(',')
    transitions = {}
    for state in states:
        transitions[state] = {}
        for symbol in alphabet:
            transitions[state][symbol] = set(input(f"Enter transitions from state {state} with symbol {symbol} (separated by commas): ").split(','))
    initial_state = input("Enter initial state: ")
    accepting_states = input("Enter accepting states separated by commas: ").split(',')
    return NFA(states, alphabet, transitions, initial_state, accepting_states)

nfa = get_user_input()
dfa = nfa.convert_to_dfa()
dfa_dot = dfa.to_dot()
dfa_dot.render('dfa_output', view=True)