#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H

class Point{
public:
    int row;
    int col;
    Point(int row,int col):row(row),col(col){}
};

class ChessMove {
public:
    Point source;
    Point destination;
    ChessMove(Point source,Point destination): source(source), destination(destination){}
};


#endif //CHESS_MOVE_H
