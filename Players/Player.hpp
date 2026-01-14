//WROTE BY YANIV COHEN && ROEE BURD
#pragma once
#include "Ship.hpp"
#include "Grid.hpp"

#define Max_Ships 5
class Player
{
private:
    char* playerName;
protected:
    Ship* ships[Max_Ships];
    Grid grid;
    Grid trackingBoard;
    int aliveShips;
public:
    Player(const char* name);
    virtual ~Player();
    
    bool allShipsSunk() const;
    
    virtual void placeAllShips() = 0;
    virtual void makeMove(Player* opponent) = 0;
    void registerHitAt(int row, int col);
    void displayTrackingGrid();
    void displayShipsBoard();

    Grid& getGrid();
    const Grid& getGrid() const;
    Grid& getTrackingGrid();
    const Grid& getTrackingGrid() const;
    const char* getName() const;

};

