#include <iostream>
#include <cmath>
using namespace std;

const double G = 6.673e-8; // cm^3/(g*sec^2)

double gravitationalForceDynes(double m1_kg, double m2_kg, double d_cm);

int main() {
    double m1_kg, m2_kg, d_cm;
    char again;

    do {
        cout << "Enter mass m1 (kg): ";
        cin >> m1_kg;
        cout << "Enter mass m2 (kg): ";
        cin >> m2_kg;
        cout << "Enter distance d (cm): ";
        cin >> d_cm;

        double F = gravitationalForceDynes(m1_kg, m2_kg, d_cm);

        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(4);
        cout << "Gravitational force F = " << F << "dynes" << endl;

        cout << "Run again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}

double gravitationalForceDynes(double m1_kg, double m2_kg, double d_cm) {
    // Convert kg to g (1 kg = 1000 g)
    double m1_g = m1_kg * 1000.0;
    double m2_g = m2_kg * 1000.0;

    // F = G*m1*m2 / d^2
    double d2 = pow(d_cm, 2.0);
    return (G * m1_g * m2_g) / d2;
}
