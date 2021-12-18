'''
start:
a -> state1
else -> error

state1:
a ->state1
b->state2
else ->error

state2:
b,c ->state3
else ->error

state3:
a ->state4
else ->error

state4:
else ->error
'''


def start(s):
    if s == "a":
        dfa = 1
    else:
        dfa = -1
    return dfa


def state1(s):
    if s == "a":
        dfa = 1
    elif s == "b":
        dfa = 2
    else:
        dfa = -1
    return dfa


def state2(s):
    if s == "b" or s == "c":
        dfa = 3
    else:
        dfa = -1
    return dfa


def state3(s):
    if s == "a":
        dfa = 4
    else:
        dfa = -1
    return dfa


def state4(s):
    return -1


def acceptString(string):
    dfa = 0
    for i in range(len(string)):
        if dfa == 0:
            dfa = start(string[i])
        elif dfa == 1:
            dfa = state1(string[i])
        elif dfa == 2:
            dfa = state2(string[i])
        elif dfa == 3:
            dfa = state3(string[i])
        elif dfa == 4:
            dfa = state4(string[i])
        else:
            return 0
    if dfa == 3 or dfa == 4:
        return 1
    else:
        return 0


string = input()
if(acceptString(string)):
    print("1")
else:
    print("0")
