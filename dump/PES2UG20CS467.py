def start(ch):
    if ch == "a":
        dfa = 1
    else:
        dfa = -1
    return dfa


def state1(ch):
    if ch == "b":
        dfa = 1
    elif ch == "c":
        dfa = 2
    else:
        dfa = -1
    return dfa


def state2(ch):
    if ch == "b":
        dfa = 3
    else:
        dfa = -1
    return dfa


def state3(ch):
    if ch == "a":
        dfa = 4
    else:
        dfa = -1
    return dfa


def state4(ch):
    return -1


def AccRej(array):
    dfa = 0
    for i in range(len(array)):
        if dfa == 0:
            dfa = start(array[i])
        elif dfa == 1:
            dfa = state1(array[i])
        elif dfa == 2:
            dfa = state2(array[i])
        elif dfa == 3:
            dfa = state3(array[i])
        elif dfa == 4:
            dfa = state4(array[i])
        else:
            return 0
    if dfa == 1 or dfa == 4:
        return 1
    else:
        return 0


array = input()
print(AccRej(array))