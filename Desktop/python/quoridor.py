class Player:
    def __init__(self, name, iPos, jPos, shape):
        self.name = name
        self.iPos = iPos
        self.jPos = jPos
        self.shape = shape
        

class Board:
    def __init__(self):
        self.board = [ ["+" for _ in range(1, 11)] for _ in range(1, 11)]
        self.board[0][0] = ""
        for i in range(1, 10):
            self.board[0][i] = i
        for i in range(1, 10):
            self.board[i][0] = i

    def reset(self, player):
        self.board[player.iPos][player.jPos] = "+"

    def playerPos(self, player):
        self.board[player.iPos][player.jPos] = player.shape


    #plank 라는 객체를 따로 만드는 것은 어떨까?
    def plank(self, indexI, indexJ, direction):
            if direction == "w":
                self.board[indexI][indexJ] = "|"
                self.board[indexI-1][indexJ] = "|"
                
            elif direction == "s":
                self.board[indexI][indexJ] = "|"
                self.board[indexI+1][indexJ] = "|"
               
            elif direction == "a":
                self.board[indexI][indexJ] = "_"
                self.board[indexI][indexJ-1] = "_"
               
            elif direction == "d":
                self.board[indexI][indexJ] = "_"
                self.board[indexI][indexJ+1] = "_"


    
theBoard = Board()
p1 = Player("player1", 1, 5, "o")
p2 = Player("player2", 9, 5, "x")

theBoard.playerPos(p1)
theBoard.playerPos(p2)

for i in range(0, 10):
    for j in range(0, 10):
        print(theBoard.board[i][j], end = "   ")
    print()


turn = [p1, p2]
indexI, indexJ, a, t, outOfRange = 0, 0, 0, 0, 0



while True:





    outOfRange = 1
    p = turn[t]
    print("|||||||||||", p.name, "의 차례!", "||||||||||||", end = "\n")
    key = input('---------------------명령어를 입력하세요. \nw: 상\ts: 하 \ta: 좌\td: 우\t혹은 좌표 (i, j) direction ex) 4 4 d \n--------')
    print(":")
    theBoard.reset(p)

    try:
        if key == "w":  
            if p.iPos - 1 < 1:
                raise Exception()
            else:
                p.iPos -= 1
                if theBoard.board[p.iPos][p.jPos] == "o" or theBoard.board[p.iPos][p.jPos] == "x" and p.iPos - 1 > 1:
                    p.iPos -= 1
                
        elif key == "a":
            if p.jPos - 1 < 1:
                raise Exception()
            else:
                p.jPos -= 1
                if theBoard.board[p.iPos][p.jPos] == "o" or theBoard.board[p.iPos][p.jPos] == "x" and p.jPos - 1 > 1:
                    p.jPos -= 1
                
        elif key == "s":
            if p.iPos + 1 > 9:
                raise Exception()
            else:
                p.iPos += 1
                if theBoard.board[p.iPos][p.jPos] == "o" or theBoard.board[p.iPos][p.jPos] == "x" and p.iPos  + 1 < 9:
                    p.iPos += 1
                
        elif key == "d":
            if p.jPos + 1 > 9:
                raise Exception()
            else:
                p.jPos += 1
                if theBoard.board[p.iPos][p.jPos] == "o" or theBoard.board[p.iPos][p.jPos] == "x" and p.jPos + 1 < 9:
                    p.iPos += 1
                
        else:
            indexI, indexJ, keyForCo = key.split()
            m, n = int(indexI), int(indexJ)
            
            try:
                 if m>9 or m<1 or n>9 or n<1:
                     raise IndexError()
                 theBoard.plank(m, n, keyForCo)
            except IndexError as e:
                theBoard.board[m][n] = "+"
                print("판자가 보드를 벗어납니다. 다시 입력하세요: ", e)
                outOfRange = 0




        
    except Exception:
        print("플레이어의 말이 보드를 벗어납니다. 다시입력하세요: ")
        outOfRange = 0
        
    theBoard.playerPos(p)


    for i in range(0, 10):
        for j in range(0, 10):
            print(theBoard.board[i][j], end = "     ")
        print("\n")

    if p == p1 and p1.iPos == 9:
        print("=============player1 wins!!=================")
        break
    elif p == p2 and p2.iPos == 1:
        print("=============player2 wins!!=================")
        break

    t = not t if outOfRange else t
    
        
