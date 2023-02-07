import copy
N, M = map(int, input().split())

res = []
backlist = []
count = 0

def backtrack():
    if (len(backlist) == M):
#        res.append(copy.deepcopy(backlist))
        for i in backlist:
            print(i, end = ' ')
        print()
        return

    for i in range(1, N+1):
        backlist.append(i)
        backtrack()
        backlist.pop()

    return res

backtrack()

#for i in res:
#    for j in i:
#        print(j, end = ' ')
#    print()


