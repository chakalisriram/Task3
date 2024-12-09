#include <iostream.h>
#include <conio.h>


void printBoard(char board[3][3]) {
    clrscr();
    cout << "Tic-Tac-Toe Game\n";
    cout << "Player 1 (X)  -  Player 2 (O)\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

int checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {  
            return 1;  
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) { 
        return 1;  
    }
    return 0;  
}

int checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;  
            }
        }
    }
    return 1; 
}

void playGame() {
    char board[3][3] = {
        {' ', ' ', ' '},  // row 1
        {' ', ' ', ' '},  // row 2
        {' ', ' ', ' '}   // row 3
    };
    int row, col;
    char currentPlayer = 'X';
    int gameWon = 0, gameDraw = 0;
    while (1) {
        printBoard(board);   
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Please try again.\n";
            continue;
        }
        board[row - 1][col - 1] = currentPlayer;
        
        
        gameWon = checkWin(board, currentPlayer);
        if (gameWon) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        
        gameDraw = checkDraw(board);
        if (gameDraw) {
            printBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    
    char playAgain;
    cout << "Do you want to play again? (Y/N): ";
    cin >> playAgain;

    if (playAgain == 'Y' || playAgain == 'y') {
        playGame();  // Restart the game
    } else {
        cout << "Thanks for playing!\n";
    }
}

// Main function to start the game
void main() {
    clrscr();  // Clears the screen (Turbo C++ specific)
    playGame();  // Start the Tic-Tac-Toe game
    getch();  // Wait for a key press before closing the console window
}
