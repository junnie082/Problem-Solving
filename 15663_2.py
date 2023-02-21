N, M = map(int, input().split())
nums = list(map(int, input().split()))
nums.sort()
visited = [False] * N
res = []

def backtrack(backlist):
    if len(backlist) == M:
        res.append(backlist.copy())
        return
    
    prev = -1
    for i in range(len(nums)):
        if visited[i] == False and prev != nums[i]:
            visited[i] = True
            prev = nums[i]
            backlist.append(nums[i])
            backtrack(backlist)
            visited[i] = False
            backlist.pop()

backtrack([])
for i in res:
    for j in i:
        print(j, end=' ')
    print()
