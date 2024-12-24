#include <iostream>
#include <iomanip> // For formatting output
#include <string>
using namespace std;

const int ROWS = 4;
const int COLS = 4;

// Function declarations
void display_board(string board[ROWS][COLS]);
bool is_move_valid(int move, string board[ROWS][COLS]);
void make_move(int move, string player, string board[ROWS][COLS]);
bool check_win(string board[ROWS][COLS], string player);
bool is_board_full(string board[ROWS][COLS]);

int main() {
    string board[ROWS][COLS] = {
        {"1", "2", "3", "4"},
        {"5", "6", "7", "8"},
        {"9", "10", "11", "12"},
        {"13", "14", "15", "16"}
    };

    string player = "X";
    int move;
    bool game_won = false;

    while (true) {
        display_board(board);
        cout << "Player " << player << ", enter your move (1-16) or '0' to quit: ";
        cin >> move;

        if (move == 0) {
            cout << "Game exited. Goodbye!" << endl;
            break;
        }

        if (!is_move_valid(move, board)) {
            cout << "Invalid move, try again." << endl;
            continue;
        }

        make_move(move, player, board);

        if (check_win(board, player)) {
            display_board(board);
            cout << "Player " << player << " wins!" << endl;
            game_won = true;
            break;
        }

        if (is_board_full(board)) {
            display_board(board);
            cout << "It's a draw!" << endl;
            break;
        }

        player = (player == "X") ? "O" : "X"; // is player == x? yes switch to o, no make him x
    }

    return 0;
}

// Function definitions
void display_board(string board[ROWS][COLS]) {
    cout << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << setw(4) << board[i][j];  // Use setw(4) for better alignment
        }
        cout << endl;
    }
    cout << endl;
}

bool is_move_valid(int move, string board[ROWS][COLS]) {
    if (move < 1 || move > 16) {
        return false;
    }
    int row = (move - 1) / COLS;
    int col = (move - 1) % COLS;
    return board[row][col] != "X" && board[row][col] != "O";
}

void make_move(int move, string player, string board[ROWS][COLS]) {
    int row = (move - 1) / COLS;
    int col = (move - 1) % COLS;
    board[row][col] = player;
}

bool check_win(string board[ROWS][COLS], string player) {
    // Check rows and columns
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player &&
            board[i][2] == player && board[i][3] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player &&
            board[2][i] == player && board[3][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player &&
        board[2][2] == player && board[3][3] == player) {
        return true;
    }
    if (board[0][3] == player && board[1][2] == player &&
        board[2][1] == player && board[3][0] == player) {
        return true;
    }

    return false;
}

bool is_board_full(string board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] != "X" && board[i][j] != "O") {
                return false;
            }
        }
    }
    return true;
}
