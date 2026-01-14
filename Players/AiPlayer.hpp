//WROTE BY YANIV COHEN && ROEE BURD
#pragma once
#include "Player.hpp"

class AiPlayer : public Player
{
private:
    
public:
    AiPlayer();
    ~AiPlayer() override = default;

    bool getRandomOrientation();
    
    void placeAllShips() override;
    void makeMove(Player* opponent) override;
    
    int getRandomCoordinate();
};

