a = int(input())
l = []
for i in range(a):
    l.append(int(input()))

for i in l:
    c = i % 4
    if c == 0:
        print("North")
    elif c == 1:
        print("East")
    elif c == 2:
        print("South")
    elif c == 3:
        print("West")
