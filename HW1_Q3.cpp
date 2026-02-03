#include <iostream>
using namespace std;


double computeInterest(double balance);
double computePayment(double balance, double interest);

int main() {
    double balance = 1000.0;
    int month = 0;

    double totalInterest = 0.0;
    double totalPaid = 0.0;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Month#\tInterest\tPrincipal\tBalance\t\tTotalInterest\tTotalPaid\n";

    // Loop until paid off
    while (balance > 0.0) {
        month++;

        double interest = computeInterest(balance);
        double payment = computePayment(balance, interest);

        double principal = payment - interest;
        balance = balance - principal;

        totalInterest = totalInterest + interest;
        totalPaid = totalPaid + payment;

        cout << month << "\t"
             << interest << "\t\t"
             << principal << "\t\t"
             << balance << "\t\t"
             << totalInterest << "\t\t"
             << totalPaid << endl;
    }

    cout << "\nMonths to pay off: " << month << endl;
    cout << "Total interest paid: " << totalInterest << endl;
    cout << "Overall amount paid: " << totalPaid << endl;

    return 0;
}

// Function definitions
double computeInterest(double balance) {
    const double MONTHLY_RATE = 0.015; // 1.5% per month
    return balance * MONTHLY_RATE;
}

double computePayment(double balance, double interest) {
    const double PAYMENT = 50.0;

    // Last payment may be less than $50, but must include interest
    if (balance + interest < PAYMENT) {
        return balance + interest;
    } else {
        return PAYMENT;
    }
}
