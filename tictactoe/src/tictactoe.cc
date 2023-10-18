#include <iostream>
#include <string>

using namespace std;
    char board[3][3] = {{'1','2','3'},
                        {'4','5','6'}, 
                        {'7','8','9'}};
char current_player = 'X';
bool winner;
string p1, p2;
bool isTie = false;

void printBoard(){
    cout << "   |   |    \n";
    cout << " " << board[0][0] << " | " << board[0][1]  <<" | " << board[0][2] << "\n";
    cout << "___|___|____\n";
    cout << "   |   |    \n";
    cout << " " << board[1][0] << " | " << board[1][1]  <<" | " << board[1][2] << "\n";
    cout << "___|___|____\n";
    cout << "   |   |    \n";
    cout << " " << board[2][0] << " | " << board[2][1]  <<" | " << board[2][2] << "\n";
    cout << "   |   |    \n";
}
bool validMove(int row, int col, char currentP){
    if(currentP == 'X' && board[row][col] != 'X' && board[row][col] != 'O'){
        return true;
    } else if (currentP == 'O' && board[row][col] != 'X' && board[row][col] != 'O'){
        return true;
    } else {
        return false;
    }
    return false;
}

void getPlayerMove(char &player, char board[3][3]){
    int input;
    int row, col;
    
    while(true){
        cout << "Player " << player << ", enter a move 1-9:\n";
        cin >> input;

        switch (input) {
            case 1: row = 0; col = 0; break;
            case 2: row = 0; col = 1; break;
            case 3: row = 0; col = 2; break;
            case 4: row = 1; col = 0; break;
            case 5: row = 1; col = 1; break;
            case 6: row = 1; col = 2; break;
            case 7: row = 2; col = 0; break;
            case 8: row = 2; col = 1; break;
            case 9: row = 2; col = 2; break;
            default:
                std::cout << "Invalid input. Please choose a number between 1 and 9." << std::endl;
                continue; // Continue the loop for invalid input
        }
        if(validMove(row, col, player)){
            board[row][col] = player;
            player = (player == 'X') ? 'O' : 'X';
            printBoard();
        } else {
            cout << "Move is occupied by: " << board[row][col] << '\n';
        }
    }
}


bool gameOver(){
    // check rows and cols
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]
        || board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            bool winner = true;
            return true;
        }
    }
    //check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]
    || board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        bool winner = true;
        return true;
    }
    //check for ties;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != 'X' && board[i][j] != 'O'){
                return false;
            }
        }
    }
    isTie = true;
    return false;
}
void start(){
    cout << "Welcome to Tic Tac Toe\n";
    cout << '\n';
    cout << "Player 1, enter your name\n";
    getline(cin, p1);
    cout << "Player 2, enter your name\n";
    getline(cin, p2);
    cout << p1 << " is X and will play first\n";
    cout << p2 << " is O and will play second\n";
}

int main(){
    start();
    while(!gameOver()){
        printBoard();
        getPlayerMove(current_player, board);
        current_player = (current_player == 'X') ? 'O' : 'X';
        
        if(current_player == 'X' && winner){
            cout << p2 << " Wins!\n";
        } else if (current_player == 'O' && winner){
            cout << p1 << " Wins!\n";
        } else {
            cout << "It is a Draw\n";
        }
    }
    return 0;
}