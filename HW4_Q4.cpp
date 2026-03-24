#include <iostream>
using namespace std;

const int SIZE = 9;

void initializeBoard(char board[]);
void displayBoard(char board[]);
bool validMove(char board[], int position);
void placeMove(char board[], int position, char player);
bool checkWinner(char board[], char player);
bool boardFull(char board[]);

int main() {
    char board[SIZE];
    char player = 'X';
    int position;

    initializeBoard(board);

    while (true) {
        displayBoard(board);

        cout << endl;
        cout << "Player " << player << ", enter a position (1-9): ";
        cin >> position;

        while (position < 1 || position > 9 || !validMove(board, position)) {
            cout << "Invalid move. Enter a position from 1 to 9 that is available: ";
            cin >> position;
        }

        placeMove(board, position, player);

        if (checkWinner(board, player)) {
            displayBoard(board);
            cout << endl;
            cout << "Player " << player << " wins!" << endl;
            break;
        }

        if (boardFull(board)) {
            displayBoard(board);
            cout << endl;
            cout << "The game is a draw." << endl;
            break;
        }

        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    return 0;
}

void initializeBoard(char board[]) {
    int i;

    for (i = 0; i < SIZE; i++) {
        board[i] = '1' + i;
    }
}

void displayBoard(char board[]) {
    int i;

    cout << endl;
    for (i = 0; i < SIZE; i++) {
        cout << board[i] << " ";
        if ((i + 1) % 3 == 0)
            cout << endl;
    }
}

bool validMove(char board[], int position) {
    if (board[position - 1] == 'X' || board[position - 1] == 'O')
        return false;
    else
        return true;
}

void placeMove(char board[], int position, char player) {
    board[position - 1] = player;
}

bool checkWinner(char board[], char player) {
    if (board[0] == player && board[1] == player && board[2] == player)
        return true;
    if (board[3] == player && board[4] == player && board[5] == player)
        return true;
    if (board[6] == player && board[7] == player && board[8] == player)
        return true;
    if (board[0] == player && board[3] == player && board[6] == player)
        return true;
    if (board[1] == player && board[4] == player && board[7] == player)
        return true;
    if (board[2] == player && board[5] == player && board[8] == player)
        return true;
    if (board[0] == player && board[4] == player && board[8] == player)
        return true;
    if (board[2] == player && board[4] == player && board[6] == player)
        return true;

    return false;
}

bool boardFull(char board[]) {
    int i;

    for (i = 0; i < SIZE; i++) {
        if (board[i] != 'X' && board[i] != 'O')
            return false;
    }

    return true;
}