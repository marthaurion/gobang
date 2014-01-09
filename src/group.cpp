#include "group.h"

PieceGroup::PieceGroup(PieceColor col) {
    color = col;
}

PieceGroup::PieceGroup(int x, int y, PieceColor col) {
    color = col;
    locations.push_back(y*19+x); //easier than storing two different numbers
}

PieceGroup::~PieceGroup() {
}

//return the number of pieces in the group
int PieceGroup::getSize() {
    return locations.size();
}

//returns the location at a given index
int PieceGroup::getLocation(int index) {
    if(index >= 0 && index < getSize()) {
        return locations[index];
    }
    else return -1;
}

//returns whether the group contains a particular spot on the board
bool PieceGroup::contains(int x, int y) {
    for(std::vector<int>::iterator it = locations.begin(); it != locations.end(); ++it) {
        if((y*19+x) == (*it)) return true;
    }
    return false;
}


void PieceGroup::addPiece(int x, int y) {
    locations.push_back(y*19+x);
}

//put the contents of this group to the input group and return the result
//should I check for duplicates?
PieceGroup PieceGroup::combine(PieceGroup other) {
    int tempx, tempy;
    for(std::vector<int>::iterator it = locations.begin(); it != locations.end(); ++it) {
        tempx = (*it)%19;
        tempy = (*it)/19;
        other.addPiece(tempx, tempy);
    }
    return other;
}

//returns whether the input piece is connected to this group
bool PieceGroup::isConnected(int x, int y) {
    int tempx, tempy;
    for(std::vector<int>::iterator it = locations.begin(); it != locations.end(); ++it) {
        tempx = (*it)%19;
        tempy = (*it)/19;

        //at least one of the coordinates should be the same
        if(tempx != x && tempy != y) continue;

        //only reaches this point if tempx equals x or tempy equals y
        //if that's the case, check whether the other coordinate is one away
        if(tempx - x == 1 || x - tempx == 1 || tempy - y == 1 || y - tempy == 1) return true;
    }

    return false;
}

//debug functions
void PieceGroup::printSelf() {
    for(std::vector<int>::iterator it = locations.begin(); it != locations.end(); ++it) {
        std::cout << (*it)%19 << " " << (*it)/19 << std::endl;
    }
}
