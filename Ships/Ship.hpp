//WROTE BY YANIV COHEN && ROEE BURD
#pragma once

class Ship {
private:
    char* name;
    int size;
    int hitsTaken = 0;
protected:
    int startRow;
    int startCol;
    bool horizontal;
public:
    Ship(const char* shipName, int shipSize);
    virtual ~Ship();
    Ship(const Ship& other);
    Ship& operator=(const Ship& other);

    bool isHorizontal() const;
    bool occupies(int r, int c) const;
    bool isSunk() const;

    virtual void takeHit();
    void setPlacement(int row, int col, bool horizontal);
    
    char* getName() const;
    int getHitsTaken() const;
    int  getStartRow() const;
    int  getStartCol() const;
    int getSize() const;

};