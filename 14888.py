N = int(input())
nums = list(map(int, input().split()))
plus, minus, multi, nanu = map(int, input().split())

count = 0
maxVal = float('-inf')
minVal = float('inf')

def backtrack(count, calculate):
    global maxVal, minVal, plus, minus, multi, nanu
    
    if count == len(nums):
        # 최댓값인지를 확인.
        if calculate > maxVal:
            maxVal = calculate
        # 최솟값인지를 확인.
        if calculate < minVal:
            minVal = calculate
        return

    if plus > 0:
        plus -= 1
        backtrack(count + 1, int(calculate + nums[count]))
        plus += 1
    if minus > 0:
        minus -= 1
        backtrack(count + 1, int(calculate - nums[count]))
        minus += 1
    if multi > 0:
        multi -= 1
        backtrack(count + 1, int(calculate * nums[count]))
        multi += 1
    if nanu > 0:
        nanu -= 1
        backtrack(count + 1, int(calculate / nums[count]))
        nanu += 1

backtrack(1, nums[0])

print(maxVal)
print(minVal)
    
