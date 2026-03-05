#include <iostream>
#include <cmath>
using namespace std;

void convertWeight(int pounds, int ounces, int &kg, int &g);

int main() {
    int pounds, ounces;
    int kg, g;

    while (true) {
        cout << "Enter weight (pounds ounces). Use negative pounds to quit: ";
        cin >> pounds >> ounces;

        if (pounds < 0) {
            cout << "Exiting.\n";
            break;
        }

        // Basic validation
        if (ounces < 0 || ounces >= 16) {
            cout << "Invalid ounces. Ounces must be 0-15.\n\n";
            continue;
        }

        convertWeight(pounds, ounces, kg, g);

        cout << pounds << " lb " << ounces << " oz = "
             << kg << " kg " << g << " g\n\n";
    }

    return 0;
}

void convertWeight(int pounds, int ounces, int &kg, int &g) {
    // Convert total weight to pounds
    double totalPounds = pounds + (ounces / 16.0);

    // Convert pounds to kilograms 
    double totalKg = totalPounds / 2.2046;

    // Split into kg and grams
    kg = static_cast<int>(totalKg);

    // Round grams to nearest int to avoid floating issues
    g = static_cast<int>(round((totalKg - kg) * 1000.0));

    // Handle rounding edge case: 999.6g -> 1000g
    if (g == 1000) {
        kg += 1;
        g = 0;
    }
}