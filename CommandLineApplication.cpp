#include <iostream>

#include "Move.h"
int main(){
    typedef enum{
        WHITE,
        BLACK
    }Turn;
    ChessBoard board = ChessBoard();

    HumanPlayer player1 = HumanPlayer();
    HumanPlayer player2 = HumanPlayer();

    while(!board.gameIsOver()){ // maybe save check mate in board and just check it
        Player player = (turn==WHITE) ? player1:player2;
        while(true) {
            ChessMove move = player.requestMove(board);
            if(board.isLegalMove()){
                board.applyMove(move);
                break;
            }
        }
        turn=(turn+1)%2;
        board.changeTurn(turn);
    }
    board.announceWinner();
}