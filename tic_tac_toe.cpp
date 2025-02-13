/* TIC-TAC-TOE GAME
 Build a simple console-based Tic-Tac-Toe game that
 allows two players to play against each other
 Game Board: Create a 3x3 grid as the game board.
 Players: Assign "X" and "O" to two players.
 Display Board: Show the current state of the board.
 Player Input: Prompt the current player to enter their move.
 Update Board: Update the game board with the player's move.
 Check for Win: Check if the current player has won.
 Check for Draw: Determine if the game is a draw.
 Switch Players: Alternate turns between "X" and "O" players.
 Display Result: Show the result of the game (win, draw, or ongoing).
 Play Again: Ask if the players want to play another game.*/
#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'},
                     {'4', '5', '6'},
                     {'7', '8', '9'}};
char currentPlayer = 'X';

void displayBoard() {
    system("cls"); 
    cout << "\n Tic-Tac-Toe\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "---|---|---\n";
    }
}

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }

        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void resetBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
    currentPlayer = 'X';
}

void makeMove() {
    int choice;
    cout << "Player " << currentPlayer << " - Enter a number (1-9): ";
    while (!(cin >> choice) || choice < 1 || choice > 9) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a number between 1 and 9: ";
    }

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
    } else {
        cout << "Cell already taken! Try again.\n";
        makeMove();
    }
}

int main() {
    char playAgain;
    do {
        resetBoard();
        bool gameOver = false;
        while (!gameOver) {
            displayBoard();
            makeMove();
            if (checkWin()) {
                displayBoard();
                cout << "\nPlayer " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "\nIt's a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
