import copy

def make_pair(item):
    if item[1] == "M":
        pair = item[0] + "G"
    else:
        pair = item[0] + "M"
    return pair

def find_unpaired(floor):
    rtn = []
    for item in floor:
        if make_pair(item) not in floor:
            rtn.append(item)
    return rtn

def allowed_states(state):
    rtn = []
    elevator = state[4]
    for item in state[elevator]:
        for i in [-1,1]:
            if elevator+i >= 0 and elevator+i <= 3:
                state_copy = copy.deepcopy(state)
                unpaired_list = find_unpaired(state_copy[elevator+i])
                pair = make_pair(item)
                if pair in unpaired_list:
                    state_copy[elevator+i].append(item)
                    state_copy[elevator].remove(item)
                    state_copy[4] = elevator + i
                    rtn.append(state_copy)
                else:
                    for unpaired in unpaired_list:
                        if unpaired[1] == pair[1]:
                            break
                    else:
                        state_copy[elevator+i].append(item)
                        state_copy[elevator].remove(item)
                        state_copy[4] = elevator + i
                        rtn.append(state_copy)
    return rtn


def run(test_mode = True):
    if test_mode:
        from inputs import test as input_state
    else:
        from inputs import advent_input as input_state
    elevator = 0
    frontier = [input_state]
    past = [input_state]
    level = 0
    while level < 11:
        next_level = []
        for state in frontier:
                for allowed_state in allowed_states(state):
                    if allowed_state not in past:
                        past.append(state)
                        next_level.append(allowed_state)
        level += 1
        for state in next_level:
            print(state)
        print("-----")
        frontier = next_level
