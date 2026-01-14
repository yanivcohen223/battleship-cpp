//WROTE BY YANIV COHEN && ROEE BURD
#pragma once
#include "Player.hpp"

class Game
{
private:
    Player* player1;
    Player* player2;
public:
    Game(Player* player1, Player* player2);
    ~Game() = default;
    void setup();
    void start();
    bool isGameOver() const;

};

