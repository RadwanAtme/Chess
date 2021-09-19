#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H

#include <iostream>
#include <string>
#include <sstream>
using std::string;
// I made an abstract Player class so i can -perhaps later on- add an AI PLayer class
class Player {
public:
    virtual ChessMove requestMove(ChessBoard board) = delete;

};

class HumanPlayer: public Player{
    string name;
public:
    HumanPlayer(string name):Player(),name(name){}
    ChessMove requestMove(ChessBoard board){
        string input;
        std::cout<<"Your turn "<<name<<" please choose your next move"<<std::endl;
        string source;
        string destination;

        std::getline(std::cin,input);
        std::stringstream ss(input);
        ss>>source>>destination;


    }
};

#endif //CHESS_PLAYER_H
