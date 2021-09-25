#ifndef CHESS_PLAYERMOVE_H
#define CHESS_PLAYERMOVE_H

struct Point{
    int row;
    int col;
    Point(int row,int col):row(row),col(col){}
    bool operator==(const Point& point){
        return ((this->row==point.row)&&(this->col==point.col))
    }
};

struct PlayerMove {
    Point source;
    Point destination;
    PlayerMove(Point source,Point destination): source(source), destination(destination){}
};


#endif //CHESS_PLAYERMOVE_H
