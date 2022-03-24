#include <iostream>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
using namespace std;
class Player{
    public:
        char name;
        int move;
        Player(char names){
            name = names;
        };
        int getmove(){
            cout << "Player " << name << " turn: ";
            cin >> move;
            cout << move << endl;
            return move;
        };   
        
};
class gameBoard{

    private: 
        int translate_move(int move){
            if(move > 0 && move < 9){
                row = move/numb;
                col = move%numb;
            }
            else{
                row = -1;
                col = -1;
            }
           return row, col;
        }

    public:
        char board[3][3] = {{'0','1','2'},{'3','4','5'},{'6','7','8'}};
        int numb, row, col;
        bool draw;
        
        gameBoard(){
            draw = FALSE;
            numb = sizeof(board) / sizeof(board[0]);
        }
        void greeting(){
            cout << "Tic Tac Toe Game Start!" << endl << "Enter the position [number] you want to place! " << endl; 
            cout << "**********************************************" << endl;
        }
        void display_board(){
            cout << "" << endl;
            cout << "Current Board:" << endl;
            for(int i=0; i < numb; i++){
                for(int j=0; j < numb; j++){

                    cout << " " << board[i][j] << "  ";  
                }
                cout << "" << endl;
                cout << "---" << " " << "---" << " " << "---" << endl;  
            }
            cout << "" << endl;
        }

        int find_available_move(){
            int count = 0;  
            for(int i=0; i < numb; i++){
                for(int j=0; j< numb; j++){
                    if(board[i][j] != 'X' && board[i][j] != 'O'){
                        count++;
                    }
                }
            }
            return count;
        }
        void take_position(Player player,int move_id){
            row, col = translate_move(move_id);

            if(board[row][col] != 'X' && board[row][col] != 'O' && row != -1 && col != -1 )
                board[row][col] = player.name;
            else{
                cout << "Invalid position, re-enter: " << endl;  
                move_id = player.getmove(); 
                take_position(player,move_id);
            }     
        }

        bool check_winner(){

            for(int i=0; i < numb; i++){
                if((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || (board[0][i] == board[1][i] && board[1][i] == board[2][i])){
                    return FALSE;
                }
            }
            if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) && board[0][0] || (board[0][2] == board[1][1] && board[1][1] == board[2][0])){
                return FALSE;
            }
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(board[i][j]!='X' && board[i][j]!='O')
                        return TRUE;
               }
            }
            draw=TRUE;
            return FALSE;
        }
        void result(Player player){
            
            if(player.name == 'X' && draw == FALSE)
                cout << "Player (O) Wins!!" << endl;
            else if(player.name == 'O' && draw == FALSE)
                cout << "Player (X) Wins!!" << endl;
            else
                cout << "This is a Draw!" << endl;
        }  
};

