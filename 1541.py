string = input()
stack = [0]

# 파이썬 스택.
# list.append(): 괄호 안의 요소를 리스트 맨 뒤에 넣음
# list.pop(): 리스트의 맨 뒤에 요소를 꺼내고 리스트에서 삭제함
def cal(recentOp, num):

    if recentOp == '-':
        stack.append(int(num))
    else:
        stack[len(stack)-1] += int(num)

num = ""
recentOp = ""
for s in string:
    if s == '-':
        cal(recentOp, num)
        recentOp = '-'
        num = ""
    elif s == '+':
        cal(recentOp, num)       
        recentOp = '+'
        num = ""
    else:
        num += s

cal(recentOp, num)

result = stack[0]
for i in range(1, len(stack)):
    result -= stack[i]
    
print(result)
        
