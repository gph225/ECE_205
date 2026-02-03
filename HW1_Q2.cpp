#include <iostream>
using namespace std;

int main() {
    double hoursWorked;
    int dependents;

    cout << "Enter hours worked this week: ";
    cin >> hoursWorked;
    cout << "Enter number of dependents: ";
    cin >> dependents;

    const double RATE = 36.75;
    const double OT_MULT = 1.5;

    double grossPay;

    // if-else flow control
    if (hoursWorked <= 40.0) {
        grossPay = hoursWorked * RATE;
    } else {
        double overtimeHours = hoursWorked - 40.0;
        grossPay = (40.0 * RATE) + (overtimeHours * RATE * OT_MULT);
    }

    // Withholdings
    double socialSecurity = 0.06 * grossPay;
    double federalTax     = 0.15 * grossPay;
    double stateTax       = 0.04 * grossPay;
    double localTax       = 0.01 * grossPay;
    double unionDues      = 20.0;

    double healthInsurance;
    if (dependents >= 2) {
        healthInsurance = 40.0;
    } else {
        healthInsurance = 0.0;
    }

    double totalDeductions = socialSecurity + federalTax + stateTax + localTax + unionDues + healthInsurance;
    double netPay = grossPay - totalDeductions;

    // 2 digits of precision
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "\nGross Pay: " << grossPay << endl;
    cout << "Social Security (6%): " << socialSecurity << endl;
    cout << "Federal Income (15%): " << federalTax << endl;
    cout << "State Tax (4%): " << stateTax << endl;
    cout << "Bethlehem Local (1%): " << localTax << endl;
    cout << "Union Dues: " << unionDues << endl;
    cout << "Health Insurance: " << healthInsurance << endl;
    cout << "Net Take-Home Pay: " << netPay << endl;

    return 0;
}
