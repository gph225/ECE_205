#include <iostream>
using namespace std;

int minutesBetweenTimes(int startTime, int endTime);

int main() {
    int startTime, endTime;

    cout << "Enter start time (0000-2359): ";
    cin >> startTime;

    cout << "Enter end time (0000-2359): ";
    cin >> endTime;

    int minutes = minutesBetweenTimes(startTime, endTime);

    if (minutes < 0) {
        cout << "Invalid input time(s).\n";
    } else {
        cout << "Minutes between: " << minutes << endl;
    }

    return 0;
}

int minutesBetweenTimes(int startTime, int endTime) {
    int sh = startTime / 100;
    int sm = startTime % 100;

    int eh = endTime / 100;
    int em = endTime % 100;

    // Validate ranges
    if (sh < 0 || sh > 23 || eh < 0 || eh > 23) return -1;
    if (sm < 0 || sm > 59 || em < 0 || em > 59) return -1;

    int startTotal = sh * 60 + sm;
    int endTotal = eh * 60 + em;

    // If end is "earlier", it's the next day
    if (endTotal < startTotal) endTotal += 24 * 60;

    return endTotal - startTotal;
}