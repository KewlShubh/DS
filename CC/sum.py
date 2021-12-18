a = int(input())
f = 0
l = []
s = []


def sum(num):
    if num == 0:
        return 0
    else:
        return num+sum(num-1)


def check(num, c):
    return num-c


for i in range(a):
    x = input()
    x = x.split(" ")
    l.append(int(x[0]))
    s.append(int(x[1]))

for i in range(len(l)):
    for j in range(l[i]):
        if(s[i]-check(sum(l[i]), j+1) == 0):
            f = f+1
            print(j+1, end=" ")
    if f == 0:
        print("-1")
    print()
