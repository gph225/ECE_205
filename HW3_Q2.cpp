#include <iostream>
#include <cmath>
using namespace std;

void triangleCalc(double a, double b, double c, double &area, double &perimeter);

int main() {
    double a, b, c;
    double area, perimeter;

    cout << "Enter three side lengths (a b c): ";
    cin >> a >> b >> c;

    triangleCalc(a, b, c, area, perimeter);

    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl;

    return 0;
}

void triangleCalc(double a, double b, double c, double &area, double &perimeter) {
    // Requirement: zeros for illegal combinations
    area = 0.0;
    perimeter = 0.0;

    // Sides must be positive
    if (a <= 0 || b <= 0 || c <= 0) return;

    // Triangle inequality
    if (a + b <= c || a + c <= b || b + c <= a) return;

    perimeter = a + b + c;
    double s = perimeter / 2.0; // semi-perimeter (used only internally)

    area = sqrt(s * (s - a) * (s - b) * (s - c));
}