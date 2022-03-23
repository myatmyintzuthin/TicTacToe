#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "classes.hpp"
#define TRUE 1
#define FALSE 0
using namespace std;

int main(){
    
    gameBoard board;
    Player player1('X'), player2('O');
    Player players[2]= {player1,player2};
    Player current_player = player1;
    int total_move = 0;
    int move_id,steps;

    board.greeting();
    board.display_board();
    while(board.check_winner() == TRUE){
        move_id = current_player.getmove();
        board.take_position(current_player, move_id);
        steps = board.find_available_move();
        cout << "Number of next available moves: " << steps << endl;
        board.display_board();
        total_move++;
        board.check_winner();
        current_player = players[total_move%2];
    }
    board.result(current_player);
}