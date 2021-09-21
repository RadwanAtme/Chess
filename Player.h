#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H

#include <iostream>
#include <string>
#include <sstream>
#include "PlayerMove.h"

using std::string;
// I made an abstract Player class so i can -perhaps later on- add an AI PLayer class
class Player {
public:
    virtual PlayerMove requestMove(ChessBoard board) = delete;

};

class HumanPlayer: public Player{
    string name;
public:
    HumanPlayer(string name);
    PlayerMove requestMove(ChessBoard board);
};

#endif //CHESS_PLAYER_H
