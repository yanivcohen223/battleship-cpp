//WROTE BY YANIV COHEN && ROEE BURD
#pragma once
#include "Player.hpp"

class HumanPlayer : public Player
{
private:
    int availableShips[5];
    int remainingShips;
    void chooseShipIndexFromUser(int& ChosenShip, int &pos);      
    void removeAvailableAt(int pos);
public:
    HumanPlayer(const char* name);
    ~HumanPlayer();

    bool getCoordinates(int& row, int& col);
    bool getOrientation(bool& hor);
   
    void placeAllShips() override;
    void makeMove(Player* opponent) override;

};
