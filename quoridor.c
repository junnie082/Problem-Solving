#include <stdio.h>

int main()
{
    char player1, player2;
    char board[10][10];
    
    for (int i = 1; i<=9; i++) {
        for (int j = 1; j<=9; j++) 
            board[i][j] = "*";
    }

    board[1][5] = player1;
    board[9][5] = player2;

    while (1) {
        
    }
}