//WROTE BY YANIV COHEN && ROEE BURD
#include "Grid.hpp"
#include <iostream>

using namespace std;


Grid::Grid(){
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            cells[i][j] = this->emptyMark;
        }
        
    }
    
}

bool Grid::isTileOccupied(int row, int col) const {

    char tmpTile = getCell(row, col);
    if (tmpTile ==  hitMark || tmpTile == shipMark)
    {
        return true;
    }
    return false;
}

bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const {
    if (!isInside(row, col)) {
        return false;
    }

    if (horizontal){
        return  col + shipSize <= BOARD_SIZE;
    }
    else {
        return row + shipSize <= BOARD_SIZE;
    }
    
}

void Grid::placeShip(int row, int col, int shipSize, bool horizontal, char symbol) {
    if (!inBounds(row, col, shipSize, horizontal)){
            return;
    }
    if (horizontal){
        for (int i = col; i < col + shipSize; i++){
            cells[row][i] = symbol;
        }
    }
    else{
        for (int i = row; i < row + shipSize; i++){
            cells[i][col] = symbol;
        }
    }
}

void Grid::markHit(int row, int col) {
    if (isInside(row, col) && getCell(row, col) == shipMark){
        cells[row][col] = hitMark;
    }
}

void Grid::markMiss(int row, int col) {
    if (isInside(row, col) && getCell(row, col) == emptyMark){
        cells[row][col] = missMark;
    }
    
}

char Grid::getCell(int row, int col) const{
    return cells[row][col];
}

bool Grid::isInside(int row, int col) const {
    return row >= 0 && row < BOARD_SIZE &&
           col >= 0 && col < BOARD_SIZE;
}

void Grid::printGrid() const{

    cout << "   ";
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << i +1  << ' ';
    }
    cout << endl;

    for (int i = 0; i < BOARD_SIZE; i++){
        cout << i+1 << "  ";
        for (int j = 0; j < BOARD_SIZE; j++){
            cout << cells[i][j] << ' ';
        }
        cout << endl;
    }
}

bool Grid::canPlaceShip(int row, int col, int shipSize, bool horizontal) const{
    if (!inBounds(row, col, shipSize, horizontal)){
            return false;
    }
    if (horizontal){
        for (int i = col; i < col + shipSize; i++){
             if(isTileOccupied(row, i)) {
                return false;
             }
        }
    }
    else{
        for (int i = row; i < row + shipSize; i++){
            if(isTileOccupied(i, col)) {
                return false;
            }
        }
    }

    return true;
}


char Grid::getEmptyMark() {
    return emptyMark;
}

char Grid::getShipMark() {
    return shipMark;
}

char Grid::getHitMark() {
    return hitMark;
}

char Grid::getMissMark() {
    return missMark;
}

void Grid::markTrackingHit(int row, int col) {
    if (isInside(row, col) && getCell(row, col) == emptyMark) {
        cells[row][col] = hitMark;   
    }
}