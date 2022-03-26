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
        void displayturn(){
            cout << "Player " << name << " turn: ";
        }
        int getmove(){
            displayturn();
            cin >> move;
            while (!cin)
            {
                cout << "Invalid position, re-enter: " << endl;
                cin.clear();
                cin.ignore();
                cin >> move;
            }
            
            return move;
        };          
};
class gameBoard{

    private: 
        int translate_move(int move){
            if(move >= 0 && move < 9){
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
        char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
        int numb, row, col;
        bool draw;
        
        gameBoard(){
            draw = FALSE;
            numb = sizeof(board) / sizeof(board[0]);
        }
        void greeting(){
            cout << "****** Tic Tac Toe ****** \n****** Game Start! ******"<< endl; 
            cout << "--------------------------------------" << endl;
            cout << "Player X = Computer \nPlayer O = Human \n";
            cout << "--------------------------------------" << endl;
            cout << "Positions = [0,1,2,3,4,5,6,7,8]" << endl;

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
                if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) // vertical
                    return TRUE;
                if(board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) // horizontal
                    return TRUE;
            }
            if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) // diagonal
                return TRUE;
            if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) // anti-diagonal
                return TRUE;
            
            return FALSE;
        }
        void result(int turn){
            if(turn == 2 && draw == FALSE)
                cout << "Player (O) Wins!!" << endl;
            else if(turn == 3 && draw == FALSE)
                cout << "Player (X) Wins!!" << endl;
            else
                cout << "This is a Draw!" << endl;
        }  
        int minimax(char board[][3],int depth, bool isAI)
        {
            int score = 0;
            int bestScore = 0;
            if (check_winner() == TRUE)
            {
                if (isAI == TRUE)
                    return -1;
                if (isAI == FALSE)
                    return +1;
            }
            else
            {
                if(depth < 9)
                {
                    if(isAI == TRUE)
                    {
                        bestScore = -999;
                        for(int i=0; i< numb; i++)
                        {
                            for(int j=0; j< numb; j++)
                            {
                                if (board[i][j] == ' ')
                                {
                                    board[i][j] = 'X';
                                    score = minimax(board, depth + 1, FALSE);
                                    board[i][j] = ' ';
                                    if(score > bestScore)
                                    {
                                        bestScore = score;
                                    }
                                }
                            }
                        }
                        return bestScore;
                    }
                    else
                    {
                        bestScore = 999;
                        for (int i = 0; i < numb; i++)
                        {
                            for (int j = 0; j < numb; j++)
                            {
                                if (board[i][j] == ' ')
                                {
                                    board[i][j] = 'O';
                                    score = minimax(board, depth + 1, TRUE);
                                    board[i][j] = ' ';
                                    if (score < bestScore)
                                    {
                                        bestScore = score;
                                    }
                                }
                            }
                        }
                        return bestScore;
                    }
                }
                else
                {
                    return 0;
                }
            }
        }

        // Function to calculate best move
        int bestMove(int moveIndex)
        {
            int x = -1, y = -1;
            int score = 0, bestScore = -999;
            for (int i = 0; i < numb; i++){
                for (int j = 0; j < numb; j++){
                    if (board[i][j] == ' '){
                        board[i][j] = 'X';
                        score = minimax(board,moveIndex+1, FALSE);
                        board[i][j] = ' ';
                        if(score > bestScore)
                        {
                            bestScore = score;
                            x = i;
                            y = j;
                        }
                    }
                }
            }
            return x*3+y;
        }
};

