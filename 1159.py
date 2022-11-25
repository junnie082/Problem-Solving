N = int(input())
character = [0 for _ in range(26)]
flag = False

for i in range(N):
    letter = input()
    letter = letter[0]
    character[ord(letter) - ord('a')] += 1

for i in range(26):
    if character[i] >= 5:
        flag = True
        print(chr(i + ord('a')), end='')

        
if flag == False:
    print("PREDAJA", end='')
    
