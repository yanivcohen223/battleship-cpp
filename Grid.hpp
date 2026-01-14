//WROTE BY YANIV COHEN && ROEE BURD
#pragma once

class Grid
{
private:
    static constexpr int BOARD_SIZE = 10;
    char cells[BOARD_SIZE][BOARD_SIZE];
    static constexpr char emptyMark = '~';
    static constexpr char shipMark = 'S';
    static constexpr char hitMark = 'X';
    static constexpr char missMark = 'M';
    
public:
    Grid();
    ~Grid() = default;
    
    bool isTileOccupied(int row, int col) const;
    bool inBounds(int row, int col, int shipSize, bool horizontal) const;
    bool isInside(int row, int col) const;
    bool canPlaceShip(int row, int col, int shipSize, bool horizontal) const;
     
    void placeShip(int row, int col, int shipSize, bool horizontal, char symbol = shipMark);
    void markHit(int row, int col);
    void markMiss(int row, int col);
    void markTrackingHit(int row, int col);
    void printGrid() const;

    char getCell(int row, int col) const;
    static char getEmptyMark();
    static char getShipMark();
    static char getHitMark();
    static char getMissMark();

};

