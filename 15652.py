N, M = map(int, input().split())

backlist = []

def backtrack():
    if len(backlist) == M:
        for i in backlist:
            print(i, end = ' ')
        print()
        return

    for i in range(1, N+1):
        if len(backlist)-1 >= 0 and i < backlist[len(backlist)-1]:
            continue
        backlist.append(i)
        backtrack()
        backlist.pop()

backtrack()
