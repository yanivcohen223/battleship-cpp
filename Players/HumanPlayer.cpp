//WROTE BY YANIV COHEN && ROEE BURD
#include "HumanPlayer.hpp"
#include <iostream>
 
using namespace std;

HumanPlayer::HumanPlayer(const char* name) : Player(name){
    //init for available ships to deploy
    for (int i = 0; i < 5; ++i) availableShips[i] = i;
    remainingShips = 5;
}

HumanPlayer::~HumanPlayer(){}

bool HumanPlayer::getCoordinates(int& row, int& col ) {

    cout << "Enter row, column (range of 1-10):\n";
    if (!(cin >> row >> col)) {
        cin.clear();
        cin.ignore(1000, '\n');
        return false;
    }
    cin.ignore(1000, '\n');
    return true;
}

bool HumanPlayer::getOrientation(bool& hor){ 
    char c;
    cout << "Enter orientation (H for horizontal, V for vertical):\n";
    if (!(cin >> c)) {
        cin.clear();
        cin.ignore(1000, '\n');
        return false;
    }
    c = static_cast<char>(tolower(static_cast<unsigned char>(c)));

    if (c == 'h') {
        hor = true;
        return true;
    }
    if (c == 'v') {
        hor = false;
        return true;
    }
    return false;
}

void HumanPlayer::placeAllShips() {
    while(remainingShips > 0){
        int chosenShip, pos;
        chooseShipIndexFromUser(chosenShip, pos);
        int row, col;
        bool hor;
        
        while(true){

            grid.printGrid();

            if (!getCoordinates(row, col) ){
                cout << "Invalid coordinates. Try again.\n";
                continue;
            }
            if (!getOrientation(hor))
            {
                cout << "Invalid orientation. Try again.\n";
                continue;
            }

            row--;col--;
            
            int size = ships[chosenShip]->getSize();
            if (grid.isInside(row, col) && grid.canPlaceShip(row,col, size, hor)) {
                grid.placeShip(row, col, size, hor);
                ships[chosenShip]->setPlacement(row, col, hor);
                removeAvailableAt(pos);
                break;
            }
            else {
                cout << "Invalid placement. Try again.\n";
            }

        }
    }
    cout << "final state: \n";
    grid.printGrid();
}

void HumanPlayer::makeMove(Player* opponent) {
    Grid& enemyGrid = opponent->getGrid();
    cout << this->getName() << "'s Tracking Board" << endl;
    trackingBoard.printGrid();
    int row, col;
    while(true){

        if (!getCoordinates(row, col) ){
            cout << "Invalid coordinates. Try again.\n";
            continue;
        }
        row--;col--;
        
        if (!enemyGrid.isInside(row, col)) {
            cout << "Coordinates out of range. Try again.\n";
            continue;
        }

        char enemyTile = enemyGrid.getCell(row, col);
        char playerTile = trackingBoard.getCell(row, col);

        if (playerTile == trackingBoard.getHitMark() || playerTile == trackingBoard.getMissMark()){
            cout << "This tile already discovered \n";
            continue;
        }
        
        if (enemyTile == enemyGrid.getShipMark()){
            opponent->registerHitAt(row, col);
            trackingBoard.markTrackingHit(row, col);
            enemyGrid.markHit(row, col);
            cout << this->getName() << " HITS!! \n";
            break;
            
        }
        else if (enemyTile == enemyGrid.getEmptyMark()) {
            trackingBoard.markMiss(row, col);
            enemyGrid.markMiss(row, col);
            cout << this->getName() << " MISS!! \n";
            break;
        }
    }
    cout << this->getName() << "'s Tracking Board" << endl;
    trackingBoard.printGrid();

}

void HumanPlayer::removeAvailableAt(int pos) {
    availableShips[pos] = availableShips[remainingShips - 1];
    remainingShips--;
}

void HumanPlayer::chooseShipIndexFromUser(int& chosenShip, int& pos) {
    cout << "Choose a ship to place:\n";
    for (int i = 0; i < remainingShips; ++i) {
        int shipIdx = availableShips[i];
        cout << (i + 1) << ") " << ships[shipIdx]->getName()
             << " (size " << ships[shipIdx]->getSize() << ")\n";
    }
    
    int choice = 0;
    while (true) {
        cout << "Enter choice (1-" << remainingShips << "): ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }
        if (choice >= 1 && choice <= remainingShips) break;
        cout << "Out of range. Try again.\n";
    }

    pos = choice - 1;
    chosenShip = availableShips[pos];
}