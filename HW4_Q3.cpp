#include <iostream>
using namespace std;

const int ROWS = 10;
const int COLS = 4;

void initializeSeats(char seats[][COLS]);
void displaySeats(char seats[][COLS]);
int getColumn(char letter);
bool seatAvailable(char seats[][COLS], int row, char letter);
void reserveSeat(char seats[][COLS], int row, char letter);
bool allSeatsTaken(char seats[][COLS]);

int main() {
    char seats[ROWS][COLS];
    int row;
    char letter;
    char again;

    initializeSeats(seats);
    again = 'Y';

    while ((again == 'Y' || again == 'y') && !allSeatsTaken(seats)) {
        displaySeats(seats);

        cout << endl;
        cout << "Enter row number (1-10): ";
        cin >> row;
        cout << "Enter seat letter (A-D): ";
        cin >> letter;

        while (row < 1 || row > 10 || getColumn(letter) == -1 ||
               !seatAvailable(seats, row, letter)) {
            cout << "Invalid or taken seat. Enter again." << endl;
            cout << "Enter row number (1-10): ";
            cin >> row;
            cout << "Enter seat letter (A-D): ";
            cin >> letter;
        }

        reserveSeat(seats, row, letter);

        if (!allSeatsTaken(seats)) {
            cout << "Do you want another seat? (Y/N): ";
            cin >> again;
        }
    }

    cout << endl;
    cout << "Final Seat Chart:" << endl;
    displaySeats(seats);

    return 0;
}

void initializeSeats(char seats[][COLS]) {
    int i, j;
    char letters[COLS] = {'A', 'B', 'C', 'D'};

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            seats[i][j] = letters[j];
        }
    }
}

void displaySeats(char seats[][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        cout << i + 1 << " ";
        for (j = 0; j < COLS; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

int getColumn(char letter) {
    if (letter == 'A' || letter == 'a')
        return 0;
    else if (letter == 'B' || letter == 'b')
        return 1;
    else if (letter == 'C' || letter == 'c')
        return 2;
    else if (letter == 'D' || letter == 'd')
        return 3;
    else
        return -1;
}

bool seatAvailable(char seats[][COLS], int row, char letter) {
    int col = getColumn(letter);

    if (seats[row - 1][col] == 'X')
        return false;
    else
        return true;
}

void reserveSeat(char seats[][COLS], int row, char letter) {
    int col = getColumn(letter);
    seats[row - 1][col] = 'X';
}

bool allSeatsTaken(char seats[][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (seats[i][j] != 'X')
                return false;
        }
    }

    return true;
}