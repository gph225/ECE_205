#include <iostream>
using namespace std;

int main() 
{
    int totalSeconds;

    cout << "Enter time in seconds: ";
    cin >> totalSeconds;

    const int SECONDS_PER_MIN = 60;
    const int SECONDS_PER_HOUR = 3600;

    int hours = totalSeconds / SECONDS_PER_HOUR;
    int remaining = totalSeconds % SECONDS_PER_HOUR;
    int minutes = remaining / SECONDS_PER_MIN;
    int seconds = remaining % SECONDS_PER_MIN;

    double hoursReal = totalSeconds / 3600.0;
    double minutesReal = totalSeconds / 60.0;

    cout << "\n" << hours << " hours, " << minutes << " minutes, " << seconds << " seconds\n";

    // Format real numbers: 4 digits past decimal 
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    cout << hoursReal << " hours\n";
    cout << minutesReal << " minutes\n";

    return 0;
}

