#include <iostream>
#include "board.h"

using namespace std;

int main()
{
    Board b;

    b.placePiece(4, 3, BLACK);
    b.placePiece(4, 4, WHITE);
    b.placePiece(4, 5, BLACK);
    b.placePiece(13, 10, WHITE);
    b.placePiece(5, 4, BLACK);
    b.placePiece(13, 11, WHITE);
    b.placePiece(3, 4, BLACK);

    b.printDebug();
    return 0;
}
