#include <iostream>
#include "game.h"
#include "board.h"


using namespace std;

/**
 * Main program for playing a chess game.
 */
int main (int argc, char * const argv[]) 
{
    Player* currentPlayer = NULL;
        
    string name1;
    string name2;
    
    cout << "Enter the 1st player's name: " << endl;
    cin >> name1;
    
    cout << "Enter the 2nd player's name: " << endl;
    cin >> name2;
    
    // initialize a chess game and display the initial state
    Game::initialize(name1, name2);
    Board::getBoard()->display(cout);
    
    // game loop in which players alternate making moves
    while(true)
    {
        currentPlayer = Game::getNextPlayer();
        while(!currentPlayer->makeMove())
        {
            cerr << "Invalid move... Try again." << endl;
        }
        Board::getBoard()->display(cout);
    }
    
    return 0;
}
