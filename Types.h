#ifndef CHESS_TYPES_H
#define CHESS_TYPES_H
#define MAKE_ENUM(STR) STR##_KING,STR##_ROOK,STR##_BISHOP,STR##_QUEEN,STR##_KNIGHT,STR##_PAWN
typedef enum{
    WHITE,
    BLACK
}Turn;

typedef enum{
    NOT_FINISHED,
    WHITE_WON,
    BLACK_WON,
    DRAW
}GameState;

typedef enum{
    NO_PIECE,
    MAKE_ENUM(WHITE),
    WHITE_PIECE_ZONE,
    BLACK_PIECE_ZONE,
    MAKE_ENUM(BLACK)
}PieceName;
#endif //CHESS_TYPES_H
