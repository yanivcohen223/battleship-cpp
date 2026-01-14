//WROTE BY YANIV COHEN && ROEE BURD
#include "Game.hpp"
#include <iostream>

using namespace std;

Game::Game(Player* I_player1, Player* I_player2) : player1(I_player1), player2(I_player2){
}

void Game::setup(){
    cout << "\n===== " << player1->getName() << " setup your ships =====\n";
    player1->placeAllShips();
    cout << "\n===== " << player2->getName() << " setup your ships =====\n";
    player2->placeAllShips();
}

void Game::start() {
    int round = 1;
    while (!isGameOver()) {
        cout << "\n========== Round " << round++ << " ==========\n";
        cout << "\n===== " << player1->getName() << "'s turn =====\n";
        player1->makeMove(player2);
        if (player2->allShipsSunk()) {
            cout << "\n*** " << player1->getName() << " won the game! ***\n";
            player1->displayTrackingGrid();
            player2->displayTrackingGrid();
            break;
        }


        cout << "\n===== " << player2->getName() << "'s turn =====\n";
        player2->makeMove(player1);
        if (player1->allShipsSunk()) {
            cout << "\n*** " << player2->getName() << " won the game! ***\n";
            player1->displayTrackingGrid();
            player2->displayTrackingGrid();
            break;
        }
        player1->displayTrackingGrid();
        player2->displayTrackingGrid();

    }
}

bool Game::isGameOver() const {
    return  player1->allShipsSunk() || player2->allShipsSunk();
}
