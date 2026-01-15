//WROTE BY YANIV COHEN && ROEE BURD
#include "AiPlayer.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

AiPlayer::AiPlayer() : Player("Computer"){
}

int AiPlayer::getRandomCoordinate() {
    return std::rand() % 10;
}

bool AiPlayer::getRandomOrientation(){
    return (std::rand() % 2) == 1 ; 
}

void AiPlayer::placeAllShips() {
    for (int i = 0; i < Max_Ships; i++){
        int size = ships[i]->getSize();

        while(true){
            int row = getRandomCoordinate();
            int col = getRandomCoordinate();
            bool hor = getRandomOrientation(); // true = horizontal, false = vertical
        
            if (grid.canPlaceShip(row,col, size, hor)) {
                grid.placeShip(row, col, size, hor);
                ships[i]->setPlacement(row, col, hor);
                break;
            }
        }
    }
}

void AiPlayer::makeMove(Player* opponent) {
    Grid& enemyGrid = opponent->getGrid();
       
    int row, col;
    while(true){
        row = getRandomCoordinate();
        col = getRandomCoordinate();


        char enemyTile = enemyGrid.getCell(row, col);
        char trackingTile = trackingBoard.getCell(row, col);

        if (trackingTile == trackingBoard.getHitMark() || trackingTile == trackingBoard.getMissMark()){
            continue;
        }
        
        if (enemyTile == enemyGrid.getShipMark()){
            opponent->registerHitAt(row, col);
            trackingBoard.markTrackingHit(row, col);
            enemyGrid.markHit(row, col);
            cout << "\nAI hit!\n";
            break;
            
        }
        else if (enemyTile == enemyGrid.getEmptyMark()) {
            trackingBoard.markMiss(row, col);
            enemyGrid.markMiss(row, col);
            cout << "\nAI miss.\n";
            break;
        }
    }

}