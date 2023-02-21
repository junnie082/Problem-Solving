N, M = map(int, input().split())
nums = list(map(int, input().split()))
nums.sort()
visited = [False] * N
res = []

def backtrack(cmp, backlist):
    if len(backlist) == M:
        res.append(backlist.copy())
        return

    prev = -1
    for i in range(len(nums)):
        if nums[i] < cmp: continue
        if visited[i] == False and prev != nums[i]:
            visited[i] = True
            prev = nums[i]
            backlist.append(nums[i])
            backtrack(nums[i], backlist)
            visited[i] = False
            backlist.pop()

backtrack(nums[0], [])

for i in res:
    for j in i:
        print(j, end=' ')
    print()
