#include <iostream>
#include <vector>

using namespace std;

void displayBoard(const vector<vector<char>>& board) {
    cout << "Current board state:\n";
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows
    for (const auto& row : board) {
        if (row[0] == player && row[1] == player && row[2] == player) {
            return true;
        }
    }

    // Check columns
    for (int col = 0; col < 3; ++col) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

void makeMove(vector<vector<char>>& board, char player) {
    int row, col;
    while (true) {
        cout << "Player " << player << ", enter your move (row and column): ";
        cin >> row >> col;
        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row-1][col-1] == ' ') {
            board[row-1][col-1] = player;
            break;
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameOngoing = true;
    char playAgain;

    do {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        gameOngoing = true;

        while (gameOngoing) {
            displayBoard(board);
            makeMove(board, currentPlayer);
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                gameOngoing = false;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "The game is a draw!\n";
                gameOngoing = false;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
