#include <iostream>
#define TRUE 1
#define FALSE 0
using namespace std;

bool isdraw(int board[][3],int n){
    for(int i=0; i < n; ++i){
        for(int j=0; j < n; ++j){
            if(board[i][j] == 0){
                return FALSE;
            }
        }
    }
    return TRUE;
}
void display_board(int board[][3],int n){

    cout << "" << endl;
    cout << "Current Board:" << endl;
    for(int i=0; i < n; ++i){
        for(int j=0; j < n; ++j){

            cout << " " << board[i][j] << "  ";  
        }
        cout << "" << endl;
        cout << "---" << " " << "---" << " " << "---" << endl;  
    }
    cout << "" << endl;

};

void place_items(int board[][3],int player,int row,int col){
    
    if(player == 1){
        board[row][col] = 1;
    }
    else{
        board[row][col] = 2;
    }
};

bool isdiagonal(int board[][3],int n)
{
    int first = board[0][0];
    for(int i=1; i<n; i++){
        if(board[i][i] == 0 || first != board[i][i]){
            return FALSE;
        }  
    }
    return TRUE;
};
bool isantidiagonal(int board[][3],int n)
{
    int first = board[0][2];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i+j == n-1){
                if(board[i][j] == 0 || first != board[i][j]){
                    return FALSE;
                }
            }
        } 
    }
    return TRUE;
};

bool ishorizontal(int board[][3],int n){
    
    for(int i=0; i<n; i++){
        if(board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return TRUE;       
        }   
    }   
    return FALSE;
};

bool isvertical(int board[][3],int n){
    
    for(int i=0; i<n; i++){
        if(board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return TRUE;       
        }   
    }   
    return FALSE;
};

bool find_winner(int board[][3], int n){
    if(isdiagonal(board,n) == TRUE){
        return TRUE;
    }
    else if(isantidiagonal(board,n) == TRUE){
        return TRUE;
    }
    else if(ishorizontal(board,n) == TRUE){
        return TRUE;
    }
    else if(isvertical(board,n) == TRUE){
        return TRUE;
    }
    else{
        return FALSE;
    }
    
};