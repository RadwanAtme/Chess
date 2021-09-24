#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H

#include <iostream>
#include <string>
#include <sstream>
#include "PlayerMove.h"
#include "ChessBoard.h"

using std::string;
// I made an abstract Player class so i can -perhaps later on- add an AI PLayer class
class Player {
public:
    Player()=default;
    virtual PlayerMove requestMove(ChessBoard board) = 0;

};

class HumanPlayer: public Player{
    string name;
public:
    HumanPlayer(string name);
    virtual PlayerMove requestMove(ChessBoard board)override;
};

#endif //CHESS_PLAYER_H
