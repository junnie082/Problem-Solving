N, M = map(int, input().split())
nums = list(map(int, input().split()))
res, backlist = [], []
nums.sort()

def backtrack(count):
    if count == M:
        res.append(backlist.copy())
        return

    for i in nums:
        if i in backlist: continue
        backlist.append(i)
        backtrack(count+1)
        backlist.pop()

    return res

backtrack(0)

for i in res:
    for j in i:
        print(j, end = ' ')
    print()
