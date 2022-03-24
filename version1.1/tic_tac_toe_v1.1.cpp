#include <iostream>
#define TRUE 1
#define FALSE 0
using namespace std;

class tictactoe{
    public:
        char board[3][3] = {{'0','1','2'},{'3','4','5'},{'6','7','8'}};
        int input,numb, row, col;
        char turn;
        bool draw;
        
        tictactoe(){
            turn = 'X';
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
       void player_turn(){
           if(turn == 'X'){
               cout << "Player 1 (X): " << endl;
               cin >> input;
           }
           else if(turn == 'O'){
               cout << "Player 2 (O): " << endl;
               cin >> input;
           }

           switch (input)
           {
            case 0: row = 0; col = 0; 
                break;
            case 1: row = 0; col = 1;
                break;
            case 2: row = 0; col = 2; 
                break;
            case 3: row = 1; col = 0;
                break;
            case 4: row = 1; col = 1; 
                break;
            case 5: row = 1; col = 2;
                break;
            case 6: row = 2; col = 0; 
                break;
            case 7: row = 2; col = 1;
                break;
            case 8: row = 2; col = 2; 
                break;
            default:
               break;
           }
           if(turn=='X' && board[row][col] != 'X' && board[row][col] != 'O'){
               board[row][col] = 'X';
               turn = 'O';
           }
           else if(turn =='O' && board[row][col] != 'O' && board[row][col] != 'X'){
               board[row][col] = 'O';
               turn = 'X';
           }
           else{
               cout << "Invalid position, re-enter: " << endl;
               player_turn();
           }
           display_board();
        }
        bool check_winner(){
            for(int i=0; i < numb; i++){
                if((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || (board[0][i] == board[1][i] && board[1][i] == board[2][i])){
                    return FALSE;
                }
            }
            if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])){
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
        void result(){
            cout << draw << endl;
            if(turn == 'X' && draw == FALSE)
                cout << "Player 2 (O) Wins!!" << endl;
            else if(turn == 'O' && draw == FALSE)
                cout << "Player 1 (X) Wins!!" << endl;
            else
                cout << "This is a Draw!" << endl;
        }
        
};

int main(){
    tictactoe game;
    game.greeting();
    game.display_board();
    while(game.check_winner() == TRUE){
        game.player_turn();
        game.check_winner();
    }
    game.result();

}