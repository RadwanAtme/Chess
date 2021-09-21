#include "ChessBoard.h"
const int boardSize = 8;
ChessBoard::ChessBoard():matrix(boardSize,vector<ChessPiece> (boardSize,NO_PIECE)),turn(WHITE),
                            gameFinishState(NOT_FINISHED),winnerName() {
    // TODO:fill the board to make standard chess board (16 piece each side)
}

void ChessBoard::changeTurn(Turn turn) {
    this->turn=turn;
}

bool ChessBoard::gameIsOver() {
    return (gameFinishState!=NOT_FINISHED);
}

void ChessBoard::applyMove(PlayerMove playerMove) {
    ChessPiece piece = matrix[playerMove.source.row][playerMove.source.col];
    matrix[playerMove.source.row][playerMove.source.col] = NO_PIECE;
    matrix[playerMove.destination.row][playerMove.destination.col] = piece;
}