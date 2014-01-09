#ifndef GROUP_H
#define GROUP_H

#include "nonclass.h"
#include <iostream>
#include <vector>

class PieceGroup
{
public:
    PieceGroup(PieceColor);
    PieceGroup(int, int, PieceColor);
    ~PieceGroup();

    int getSize();
    int getLocation(int);
    bool contains(int, int);
    bool isConnected(int, int);
    void addPiece(int, int);
    PieceGroup combine(PieceGroup);
    PieceColor getColor() { return color; }
    void printSelf();
private:
    std::vector<int> locations;
    PieceColor color;
};

#endif // GROUP_H
