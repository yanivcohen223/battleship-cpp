//WROTE BY YANIV COHEN && ROEE BURD
#include "Ship.hpp"
#include <iostream>

using namespace std;

Ship::Ship(const char* shipName, int shipSize) {
    if (!shipName){
        return;
    }
    
    this->name = new char[strlen(shipName)+1];
    strcpy(name, shipName);

    this->size = shipSize;
}

Ship::~Ship(){
    delete[] this->name;
}

Ship::Ship(const Ship& other) : name(nullptr), size(other.size), hitsTaken(other.hitsTaken)
    {
        name = new char[std::strlen(other.name) + 1];
        std::strcpy(name, other.name);
    }

Ship& Ship::operator=(const Ship& other) {
        if (this == &other) return *this;

        char* newName = new char[std::strlen(other.name) + 1];
        std::strcpy(newName, other.name);

        delete[] name;
        name = newName;
        size = other.size;
        hitsTaken= other.hitsTaken;

        return *this;
    }

bool Ship::isSunk() const{
    return hitsTaken >= size;
}

bool Ship::isHorizontal() const {
    return horizontal;
}

bool Ship::occupies(int r, int c) const {
    if (horizontal) {
        return r == startRow &&
               c >= startCol &&
               c < startCol + size;
    } else {
        return c == startCol &&
               r >= startRow &&
               r < startRow + size;
    }
}

void Ship::takeHit(){
    if (hitsTaken < size){
        hitsTaken++;
        cout << name << " got hit!\n";
    }
}

void Ship::setPlacement(int row, int col, bool isHorizontal) {
    startRow = row;
    startCol = col;
    horizontal = isHorizontal;
}

int Ship::getSize() const {
    return size;
}

int Ship::getHitsTaken() const {
    return hitsTaken;
}

char* Ship::getName() const {
    return name;
}

int Ship::getStartRow() const {
    return startRow;
}

int Ship::getStartCol() const {
    return startCol;
}
