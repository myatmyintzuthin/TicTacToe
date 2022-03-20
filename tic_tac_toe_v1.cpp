#include <iostream>
#include "mylib.hpp"
#define TRUE 1
#define FALSE 0
using namespace std;

int main(){
    
    int board[3][3] = { 0 };
    int row, col;
    int n = sizeof(board)/sizeof(board[0]);
    
    cout << "Game Start!" << endl << "Enter the position [row,column] you want to place! " << endl;
    display_board(board,n);

    while(TRUE){
        static int player = 1;
        cout << "Player " << player << ":";
        cin >> row >> col;

        // check input 
        while(board[row][col] != 0){
            cout << "Taken position, re-enter: ";
            cin >> row >> col;
        };
        while(row >= n || col >= n || row < 0 || col < 0){
            cout << "Invalid position, re-enter: ";
            cin >> row >> col;
        };
        // take positions
        place_items(board, player, row, col);
        // visualize the board
        display_board(board,n);
        // decide the winning situation
        if(find_winner(board,n) == TRUE){
            cout << "Player " << player << " Wins!!" << endl;
            break;
        }
        else if(isdraw(board,n) == TRUE){
            cout << "This is a Draw!" << endl;
            break;
        }
        if(player == 1){ player = 2;} else{ player = 1;};
        
    }
    
    return 0;
}