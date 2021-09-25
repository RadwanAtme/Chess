#ifndef CHESS_CHESSPIECE_H
#define CHESS_CHESSPIECE_H
#include "ChessBoard.h"
#include "PlayerMove.h"

class ChessPiece {
public:
    ChessPiece() = delete;

    virtual bool moveIsLegal(ChessBoard board, PlayerMove move)=0;
};
// TODO: check cornor case where the piece is placed in same previous place for all the pieces,might work for some
// TODO: check for out of bounds moves,maybe i can check that before getting here
class Rook:public ChessPiece{
    Rook()=default;
    virtual bool moveIsLegal(ChessBoard board, PlayerMove move) override {
        //TODO: make the code cleaner, maybe write a function SameRow or something like that
            if (move.source.row == move.destination.row) {
                if (NoPiecesInColumnBetweenIndices(board,move)) {
                    return true;
                } else {
                    return false;
                }
            }else if (move.source.col == move.destination.col) {
                if (NoPiecesInRowBetweenIndices(board,move)) {
                    return true;
                } else {
                    return false;
                }
            }
            return false;
    }
    bool NoPiecesInColumnBetweenIndices(ChessBoard chessBoard,PlayerMove move){
        int row = move.source.row;
        int sourceCol = move.source.col;
        int destCol = move.destination.col;
        vector<vector<PieceName>> board = chessBoard.getBoard();
        for(int col = std::min(sourceCol,destCol)+1;col<std::max(sourceCol,destCol);col++){
            if(board[row][col]!=NO_PIECE) {
                return false;
            }
        }
        return true;
    }
    bool NoPiecesInRowBetweenIndices(ChessBoard chessBoard,PlayerMove move){
        int col = move.source.col;
        int sourceRow = move.source.row;
        int destRow = move.destination.row;
        vector<vector<PieceName>> board = chessBoard.getBoard();
        for(int row = std::min(sourceRow,destRow)+1;row<std::max(sourceRow,destRow);row++){
            if(board[row][col]!=NO_PIECE) {
                return false;
            }
        }
        return true;
    }
};

class Bishop:public ChessPiece{
    Bishop()=default;
    virtual bool moveIsLegal(ChessBoard board, PlayerMove move) override{
        //TODO: put this block of code in a function called check if same diagonal
        int diff = std::abs(move.source.row - move.destination.row);
        if(std::abs(move.source.col-move.destination.col)!=diff){
            return false;
        }else{
            vector<vector<PieceName>> matrix = board.getBoard();
            int rowStep = (move.source.row<move.destination.row)?1:-1;
            int colStep = (move.source.col<move.destination.col)?1:-1;
            while(!(move.source==move.destination)){
                if(matrix[move.source.row][move.source.col]!=NO_PIECE){
                    return false;
                }
                move.source.row += rowStep;
                move.source.col += colStep;
            }
            return true;
        }
    }
};
class Pawn:public ChessPiece{
    Pawn()=default;
    virtual bool moveIsLegal(ChessBoard board, PlayerMove move) override{
        // TODO: add a way to check en passante
        // add a way to check starting move,maybe add en passante able to right and left then

    }
};
class Queen:public ChessPiece{
    Queen()=default;
    virtual bool moveIsLegal(ChessBoard board, PlayerMove move) override{
        // if it can move like king or bishop or rook then it passes
    }
};
class King:public ChessPiece{
    King()=default;
    virtual bool moveIsLegal(ChessBoard board, PlayerMove move) override{
        int rowDiff = std::abs(move.source.row - move.destination.row);
        int colDiff = std::abs(move.source.col - move.destination.col);
        return ((rowDiff<=1)&&(colDiff<=1));
    }
};
class Knight:public ChessPiece{
    Knight()=default;
    virtual bool moveIsLegal(ChessBoard board, PlayerMove move) override;
};

#endif //CHESS_CHESSPIECE_H
