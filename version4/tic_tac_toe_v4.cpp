#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "classes.hpp"
#define AI 2
#define HUMAN 3
using namespace std;

void play_tictactoe(gameBoard board,int turn){
    Player computer('X'), human('O');
    int moveid = 0;
    int available_move = (board.numb * board.numb);
    while(board.check_winner() == FALSE && moveid < available_move){
        if(turn == AI){
            computer.displayturn();
            int move = board.bestMove(moveid);
            cout << move << endl;
            board.take_position(computer,move);
            moveid++;
            board.display_board();
            turn = HUMAN;                       
        }
        else if(turn == HUMAN){
            int move = human.getmove();
            board.take_position(human, move);
            moveid++;
            board.display_board();
            turn = AI;
        }
    }
    if (moveid == available_move)
        board.draw = TRUE;
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