#ifndef CHESS_CHESSBOARD_H
#define CHESS_CHESSBOARD_H

#include <string>
#include <vector>
#include "Types.h"
#include "PlayerMove.h"
using std::vector;
using std::string;

class ChessBoard {
    vector<vector<PieceName>> matrix;
    Turn turn;
    GameState gameFinishState;
    string winnerName;
public:
    ChessBoard();
    ~ChessBoard() = default;

    void changeTurn(Turn turn);
    void printBoard();
    void applyMove(PlayerMove playerMove);
    bool gameIsOver();

    void check



};


#endif //CHESS_CHESSBOARD_H
