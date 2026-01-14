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
            displayWinningState(player1, player2);
            break;
        }
        cout << "\n===== " << player2->getName() << "'s turn =====\n";
        player2->makeMove(player1);
        if (player1->allShipsSunk()) {
            displayWinningState(player2, player1);
            break;
        }

        player1->displayTrackingGrid();
        player2->displayTrackingGrid();
    }
}

bool Game::isGameOver() const {
    return  player1->allShipsSunk() || player2->allShipsSunk();
}

//p1 winner 
void displayWinningState(Player* p1, Player* p2){

        cout << "\n***** " << p1->getName() << " won the game! ******\n";
        p1->displayTrackingGrid();
        p2->displayTrackingGrid();

        cout << "\n***** "  << " Ships boards! *****\n";
        p1->displayShipsBoard();
        p2->displayShipsBoard();
}