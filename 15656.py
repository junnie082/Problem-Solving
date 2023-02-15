N, M = map(int, input().split())
nums = list(map(int, input().split()))
nums.sort()
res, backlist = [], []

def backtrack(count):
    if count == M:
        res.append(backlist.copy())
        return
    for i in nums:
        backlist.append(i)
        backtrack(count+1)
        backlist.pop()

    return res

backtrack(0)

for i in res:
    for j in i:
        print(j, end=' ')
    print()
