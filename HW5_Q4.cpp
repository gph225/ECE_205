#include <iostream>
#include <cmath>
using namespace std;

// Helper function
bool isPrime(int n) {
    if (n < 2) return false;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

class PrimeNumber {
private:
    int num;

public:
    // Default constructor
    PrimeNumber() {
        num = 1;
    }

    // Parameterized constructor
    PrimeNumber(int n) {
        num = n;
    }

    int getPrime() {
        return num;
    }

    // Prefix ++
    PrimeNumber operator++() {
        int temp = num + 1;
        while (!isPrime(temp)) {
            temp++;
        }
        num = temp;
        return *this;
    }

    // Postfix ++
    PrimeNumber operator++(int) {
        PrimeNumber old = *this;
        ++(*this);
        return old;
    }

    // Prefix --
    PrimeNumber operator--() {
        int temp = num - 1;
        while (temp > 1 && !isPrime(temp)) {
            temp--;
        }
        num = temp;
        return *this;
    }

    // Postfix --
    PrimeNumber operator--(int) {
        PrimeNumber old = *this;
        --(*this);
        return old;
    }
};

int main() {
    PrimeNumber p(13);

    cout << "Starting Prime: " << p.getPrime() << endl;

    ++p;
    cout << "After prefix ++: " << p.getPrime() << endl;

    p++;
    cout << "After postfix ++: " << p.getPrime() << endl;

    --p;
    cout << "After prefix --: " << p.getPrime() << endl;

    p--;
    cout << "After postfix --: " << p.getPrime() << endl;

    return 0;
}