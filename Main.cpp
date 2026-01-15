//WROTE BY YANIV COHEN && ROEE BURD
// Git URL: https://github.com/yanivcohen223/battleship-cpp
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Game.hpp"
#include "HumanPlayer.hpp"
#include "AiPlayer.hpp"

using namespace std; 

int main(int argc, char const *argv[]){
    srand(time(nullptr));  

    bool playAgain = true;

    while (playAgain){
        HumanPlayer* player1 = new HumanPlayer("Human");
        AiPlayer* player2 = new AiPlayer();

        Game* game = new Game(player1, player2);
        game->setup();
        game->start();

        delete player1;
        delete player2;

        cout << "Play Again (y/n)" << endl;
        char c;
        cin >> c;
        playAgain = (c == 'y' || c == 'Y');
    }
    



    return 0;
}
