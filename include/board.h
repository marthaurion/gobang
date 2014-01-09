#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include "nonclass.h"
#include "group.h"
#include <vector>

class Board {
public:
	Board();
	PieceColor getPiece(int, int);
	PieceColor oppositeColor(PieceColor);
	void removePiece(int, int);
    void placePiece(int, int, PieceColor);
	void processGroups(int, int, PieceColor);
	void checkCaptures(int, int, PieceColor);
	void removeGroup(int, int);
	int calcLiberties(PieceGroup);
	int calcLiberties(int, int);
	void printSelf();
	void printDebug();
private:
    std::vector<PieceGroup> groups;
	PieceColor board[19][19];
	PieceColor turn;
};


#endif // BOARD_H_INCLUDED
