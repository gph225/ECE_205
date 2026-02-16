#include <iostream>
using namespace std;

double hatSize(double weight_lb, double height_in);
double jacketSize(double weight_lb, double height_in, int age);
double waistSize(double weight_lb, int age);

int main() {
    double height_in, weight_lb;
    int age;

    cout << "Enter height (inches): ";
    cin >> height_in;
    cout << "Enter weight (pounds): ";
    cin >> weight_lb;
    cout << "Enter age (years): ";
    cin >> age;

    double hat = hatSize(weight_lb, height_in);
    double jacket = jacketSize(weight_lb, height_in, age);
    double waist = waistSize(weight_lb, age);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "\nClothing Sizes\n";
    cout << "Hat size: " << hat << endl;
    cout << "Jacket size: " << jacket << endl;
    cout << "Waist size: " << waist << endl;

    return 0;
}

double hatSize(double weight_lb, double height_in) {
    return 2.9 * weight_lb / height_in;
}

double jacketSize(double weight_lb, double height_in, int age) {
    double size = (height_in * weight_lb) / 288.0;

    if (age > 30) {
        int fullTensOver30 = (age - 30) / 10;      // only full 10-year blocks
        size = size + (fullTensOver30 * (1.0 / 8.0));
    }
    return size;
}

double waistSize(double weight_lb, int age) {
    double size = weight_lb / 5.7;

    if (age > 28) {
        int fullTwosOver28 = (age - 28) / 2;       // only full 2-year blocks
        size = size + (fullTwosOver28 * (1.0 / 10.0));
    }
    return size;
}
