//WROTE BY YANIV COHEN && ROEE BURD
#include "Player.hpp"

#include "Battleship1.hpp"
#include "Carrier.hpp"
#include "Cruiser.hpp"
#include "Destroyer.hpp"
#include "Submarine.hpp"

#include <iostream>

using namespace std;

Player::Player(const char* name) {
    if (!name) { return; }
    
    playerName = new char[strlen(name) +1];
    strcpy(playerName, name);

    ships[0] = new Battleship1();
    ships[1] = new Destroyer();
    ships[2] = new Carrier();
    ships[3] = new Submarine();
    ships[4] = new Cruiser();
    
    aliveShips = 5;
}

Player::~Player(){
    delete[] playerName;
    for (int i = 0; i < Max_Ships; i++)
    {
        delete ships[i];
        ships[i] = nullptr;
    }
}

bool Player::allShipsSunk() const {
    if (aliveShips > 0){
        return false;
    }
    return true;
}

void Player::displayTrackingGrid(){
    cout << this->getName() << "'s Tracking Board" << endl;
    trackingBoard.printGrid();
}

void Player::displayShipsBoard(){
    cout << this->getName() << "'s Ships Board" << endl;
    trackingBoard.printGrid();
}

Grid& Player::getGrid() {
    return grid;
}

const Grid& Player::getGrid() const {
    return grid;
}

Grid& Player::getTrackingGrid() {
    return trackingBoard;
}

const Grid& Player::getTrackingGrid() const {
    return trackingBoard;
}

void Player::registerHitAt(int row, int col) {
    for (int i = 0; i < aliveShips; ++i) {
        if (ships[i] && ships[i]->occupies(row, col)) {

            bool wasSunk = ships[i]->isSunk(); 
            ships[i]->takeHit();
            bool nowSunk = ships[i]->isSunk();


            if (!wasSunk && nowSunk) {
                int lastAlive = aliveShips - 1;
                Ship* sunkShip = ships[i];

                ships[i] = ships[lastAlive];
                ships[lastAlive] = sunkShip;

                aliveShips--;
                cout << sunkShip->getName() << " has been sunk" << endl;
            }

            return; 
        }
    }
}

const char* Player::getName() const {
    return playerName;
}
