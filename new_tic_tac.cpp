#include <iostream>
#define TRUE 1
#define FALSE 0
using namespace std;

bool isdraw(int board[][3]){
    for(int i=0; i < 3; ++i){
        for(int j=0; j < 3; ++j){
            if(board[i][j] == 0){
                return TRUE;
            }
        }
    }
    return FALSE;
}
void display_board(int board[][3]){

    cout << "Current Board:" << endl;
    for(int i=0; i < 3; ++i){
        for(int j=0; j < 3; ++j){
            cout << board[i][j] << '\t';  
        }
        cout << "" << endl;
    }
};

void place_items(int board[][3],int player,int row,int col){
    
    if(player == 1){
        board[row][col] = 1;
    }
    else{
        board[row][col] = 2;
    }
};

int main(){
    
    int board[3][3] = { 0 };
    int row, col;
    
    cout << "Game Start!" << endl << "Please enter the position [row,column] you want to place! " << endl;
    
    while(isdraw(board) == TRUE){
        static int player = 1;
        cout << "Player " << player << ":";
        cin >> row >> col; 
        while(board[row][col] != 0){
            cout << "Taken position, re-enter: ";
            cin >> row >> col;
        };
        while(row >= 3 || col >= 3 || row < 0 || col < 0){
            cout << "Invalid position, re-enter: ";
            cin >> row >> col;
        };
        place_items(board, player, row, col);
        display_board(board);
        if(player == 1){ player = 2;} else{ player = 1;};
        
    }
    cout << "Game Over! This is a Draw!" << endl;

    return 0;
}