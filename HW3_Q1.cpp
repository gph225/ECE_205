#include <iostream>
#include <iomanip>
using namespace std;

void inputTime(int &hour24, int &minute);
void convert24to12(int hour24, int minute, int &hour12, char &ampm);
void outputTime(int hour12, int minute, char ampm);

int main() {
    int hour24, minute;
    int hour12;
    char ampm;

    while (true) {
        inputTime(hour24, minute);

        // Allow user to end with a negative integer input
        if (hour24 < 0 || minute < 0) {
            cout << "Goodbye.\n";
            break;
        }

        // Validity check 
        if (hour24 > 23 || minute > 59) {
            cout << "Invalid time. Try again.\n\n";
            continue;
        }

        convert24to12(hour24, minute, hour12, ampm);
        outputTime(hour12, minute, ampm);
        cout << "\n";
    }

    return 0;
}

void inputTime(int &hour24, int &minute) {
    cout << "Enter hour (0-23) then minute (0-59) in 24-hour time or enter a negative integer to end: ";
    cin >> hour24 >> minute;
}

void convert24to12(int hour24, int /*minute*/, int &hour12, char &ampm) {
    // Determine AM/PM (single char)
    if (hour24 >= 12) ampm = 'P';
    else ampm = 'A';

    // Convert hour
    if (hour24 == 0) hour12 = 12;       // midnight -> 12 AM
    else if (hour24 > 12) hour12 = hour24 - 12;
    else hour12 = hour24;               // 1-12 stays
}

void outputTime(int hour12, int minute, char ampm) {
    cout << "12-hour time: " << hour12 << ":"
         << setw(2) << setfill('0') << minute
         << " " << ampm << "M";
}