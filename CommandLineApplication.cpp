#include <iostream>

#include "Types.h"
#include "PlayerMove.h"
#include "Player.h"
#include "ChessBoard.h"
using std::string;


static string getPlayerName(string color){
    std::cout<<color<<" player,please choose your name"<<std::endl;
    string name;
    std::cin>>name;
    return name;
}

static Turn switchTurn(Turn turn){
    switch(turn){
        case WHITE:return BLACK;
        case BLACK:return WHITE;
        default:return WHITE; // shouldn't get here
    }
}

int main() {
    ChessBoard board;
    HumanPlayer player1("White");
    HumanPlayer player2("Black");
    Turn turn = WHITE;

    while (!board.gameIsOver()) { // maybe save check mate in board and just check it
        HumanPlayer player = (turn == WHITE) ? player1 : player2;
        while (true) {
            PlayerMove playerMove = player.requestMove(board);

            bool isLegalMove = board.isLegalMove(playerMove);
            if (isLegalMove) {
                if (true)
                    board.applyMove(playerMove);
                break;
            }
        }
        turn = switchTurn(turn);
        board.changeTurn(turn);
    }
    board.announceWinner();
    return 0;
}