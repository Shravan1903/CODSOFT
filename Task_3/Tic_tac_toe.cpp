/*
TIC-TAC-TOE GAME
Build a simple console-based Tic-Tac-Toe game that
allows two players to play against each other
Game Board: Create a 3x3 grid as the game board.
Players: Assign "X" and "O" to two players.
Display Board: Show the current state of the board.
Player Input: Prompt the current player to enter their move.
Update Board: Update the game board with the player's move.
Check for Win: Check if the current player has won.
Check for Draw: Determine if the game is a draw.
Switch Players: Alternate turns between"X" and "O" players.
Display Result: Show the result of the game (win, draw, or ongoing).
Play Again: Ask if the players want to play another game.
*/

#include <iostream>
#include <vector>
#include <cctype> // for tolower
using namespace std;

// Function to draw the tic-tac-toe board with cell numbers
void drawBoard(const vector<vector<char>>& board) {
    cout << "-------------" << endl;
    int cellNumber = 1;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                cout << cellNumber;
            } else {
                cout << board[i][j];
            }
            cout << " | ";
            cellNumber++;
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

// Function to convert cell number to row and column
bool getRowColFromCellNumber(int cellNumber, int &row, int &col) {
    if (cellNumber < 1 || cellNumber > 9) {
        return false; // Invalid cell number
    }
    cellNumber--; // Convert to 0-based index
    row = cellNumber / 3;
    col = cellNumber % 3;
    return true;
}

// Function to check if the current player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Diagonal win (top-right to bottom-left)
    }
    return false;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    int cellNumber;
    int row, col;
    int moves = 0;
    bool gameOver = false;
    char playAgain;

    cout << "\n Welcome to Tic-Tac-Toe! \n" << endl;

    do {
        // Reset the game
        vector<vector<char>> board(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        moves = 0;
        gameOver = false;

        while (!gameOver) {
            drawBoard(board);
            cout << "Player " << currentPlayer << ", enter the cell number you want to mark (1-9): ";
            cin >> cellNumber;

            if (getRowColFromCellNumber(cellNumber, row, col) && board[row][col] == ' ') {
                board[row][col] = currentPlayer;
                moves++;

                if (checkWin(board, currentPlayer)) {
                    drawBoard(board);
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    gameOver = true;
                } else if (moves == 9) {
                    drawBoard(board);
                    cout << "It's a draw!" << endl;
                    gameOver = true;
                } else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (tolower(playAgain) == 'y');

    return 0;
}