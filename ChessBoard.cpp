#include "ChessBoard.h"
const int boardSize = 8;
#include <iostream>

static void printRowNumber(int index);
static void printColLetters();
static void printVerticalLine();
static void printPiece(PieceName piece);


static PieceName getPieceName(PieceName color,int index){
    if(color==WHITE_PIECE_ZONE){
        switch(index){
            case 0:
            case 7:
                return WHITE_ROOK;
            case 1:
            case 6:
                return WHITE_KNIGHT;
            case 2:
            case 5:
                return WHITE_BISHOP;
            case 3:return WHITE_QUEEN;
            case 4:return WHITE_KING;
            default:return NO_PIECE;
        }
    }else{
        switch(index){
            case 0:
            case 7:
                return BLACK_ROOK;
            case 1:
            case 6:
                return BLACK_KNIGHT;
            case 2:
            case 5:
                return BLACK_BISHOP;
            case 3:return BLACK_QUEEN;
            case 4:return BLACK_KING;
            default:return NO_PIECE;
        }
    }
}

ChessBoard::ChessBoard(): matrix(boardSize,vector<PieceName> (boardSize, NO_PIECE)), turn(WHITE),
                          gameFinishState(NOT_FINISHED), winnerName() {
    int whitePawnsRow = 1;
    int whitePiecesRow = 0;
    int blackPawnsRow=boardSize-2;
    int blackPiecesRow = boardSize-1;
    for(int col=0;col<boardSize;col++){
        matrix[whitePawnsRow][col]=WHITE_PAWN;
        matrix[blackPawnsRow][col]=BLACK_PAWN;
        matrix[whitePiecesRow][col] =getPieceName(WHITE_PIECE_ZONE,col);
        matrix[blackPiecesRow][col] =getPieceName(BLACK_PIECE_ZONE,col);
    }
}

void ChessBoard::changeTurn(Turn turn) {
    this->turn=turn;
}

bool ChessBoard::gameIsOver() {
    // TODO: implement functions that check if the game state is over(draw or someone won)
    return (gameFinishState!=NOT_FINISHED);
}

void ChessBoard::applyMove(PlayerMove playerMove) {
    PieceName piece = matrix[playerMove.source.row][playerMove.source.col];
    matrix[playerMove.source.row][playerMove.source.col] = NO_PIECE;
    matrix[playerMove.destination.row][playerMove.destination.col] = piece;
}

static void printRowNumber(int index){
    std::cout<<index<<"  ";
}
static void printColLetters(){
    std::cout<<"       a       b       c       d       e       f       g       h"<<std::endl;
}
static void printVerticalLine(){
    std::cout<<"|";
}
static void printPiece(PieceName piece){
    if(piece>=BLACK_PIECE_ZONE){
        std::cout << "\033[30m";
    }
    switch(piece){
        case WHITE_BISHOP:
        case BLACK_BISHOP:
            std::cout<<"Bishop ";
            break;

        case WHITE_KING:
        case BLACK_KING:
            std::cout<<" King  ";
            break;

        case WHITE_KNIGHT:
        case BLACK_KNIGHT:
            std::cout<<"Knight ";
            break;

        case WHITE_PAWN:
        case BLACK_PAWN:
            std::cout<<" Pawn  ";
            break;

        case WHITE_QUEEN:
        case BLACK_QUEEN:
            std::cout<<" Queen ";
            break;

        case WHITE_ROOK:
        case BLACK_ROOK:
            std::cout<<" Rook  ";
            break;

        default:
            std::cout<<"       ";
            break;
    }
    std::cout<<"\033[0m";
}

void ChessBoard::printBoard() {
    printColLetters();
    for(int row=8;row>0;row--){
        printRowNumber(row);
        for(int col=0;col<boardSize;col++){
            printVerticalLine();
            printPiece(matrix[row-1][col]);
        }
        printVerticalLine();
        std::cout<<std::endl;
    }
    printColLetters();
}

