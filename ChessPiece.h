#ifndef CHESS_CHESSPIECE_H
#define CHESS_CHESSPIECE_H
#include "ChessBoard.h"
#include "PlayerMove.h"

class ChessPiece {
public:
    ChessPiece() = delete;

    virtual bool moveIsLegal(ChessBoard board, PlayerMove move);
};
//
//class Rook:public ChessPiece{
//    Rook()=default;
//    virtual bool moveIsLegal(int board, int move) override;
//};
//
//class Bishop:public ChessPiece{
//    Bishop()=default;
//    virtual bool moveIsLegal(int board, int move) override;
//};
//class Pawn:public ChessPiece{
//    Pawn()=default;
//    virtual bool moveIsLegal(int board, int move) override;
//};
//class Queen:public ChessPiece{
//    Queen()=default;
//    virtual bool moveIsLegal(int board, int move) override;
//};
//class King:public ChessPiece{
//    King()=default;
//    virtual bool moveIsLegal(int board, int move) override;
//};
//class Knight:public ChessPiece{
//    Knight()=default;
//    virtual bool moveIsLegal(int board, int move) override;
//};

#endif //CHESS_CHESSPIECE_H
