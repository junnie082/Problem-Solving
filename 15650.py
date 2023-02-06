import copy
N, M = map(int, input().split())

res = []
backlist = []
count = 0
def backfunc(count):
    for i in range(1, N+1):
        if count == M:
            count = 0
            res.append(copy.deepcopy(backlist))
            #print("backlist: ", backlist)
            #print("res: ", res)
            return
        
        if len(backlist)-1 >= 0 and i <=backlist[len(backlist)-1]:
            continue

        backlist.append(i)
        backfunc(count + 1)
        backlist.remove(i)
        
    return res

backfunc(0)

for i in res:
    for j in i:
        print(j, end = ' ')
    print()
