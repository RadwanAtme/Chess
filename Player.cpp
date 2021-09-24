#include "Player.h"
#include "ChessBoard.h"

HumanPlayer::HumanPlayer(string name):Player(),name(name){}

PlayerMove HumanPlayer::requestMove(ChessBoard board) {
    int sourceRow,sourceCol,destinationRow,destinationCol;
    std::cout<<name<<" turn please choose your next move"<<std::endl;
    board.printBoard();
    std::cin>>sourceRow>>sourceCol>>destinationRow>>destinationCol;

    Point source(sourceRow,sourceCol);
    Point destination(destinationRow,destinationCol);
    return PlayerMove(source,destination);
//        string source;
//        string destination;
//        std::getline(std::cin,input);
//        std::stringstream ss(input);
//        ss>>source>>destination;
//        // TODO: check if the input is correct
            // TODO: change the input to the e5 system
//        Point source = translateChessInput()
}