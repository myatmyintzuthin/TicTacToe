#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "classes.hpp"
#define AI 1
#define HUMAN 2
using namespace std;

void play_tictactoe(gameBoard board,int turn){
    Player computer('X'), human('O');
    while(board.check_winner() == false){
        if(turn == AI){
            computer.displayturn();
            int move = board.bestMove(0);
            cout << move << endl;
            board.take_position(computer,move);
            board.display_board();
            turn = HUMAN;                       
        }
        else if(turn == HUMAN){
            int move = human.getmove();
            board.take_position(human, move);
            board.display_board();
            turn = AI;
        }
    }
    board.result(turn);
}
int main(){
    char choice;
    gameBoard board;
    
    board.greeting();
    board.display_board();
    cout << "Do you want to go first?[y/n] " << endl;
    cin >> choice;
    if(choice == 'y')
        play_tictactoe(board,HUMAN);
    else if(choice == 'n')
        play_tictactoe(board,AI);
    else
        cout << "Invalid choice!" << endl;
}