#include <iostream>
#include <vector>
using namespace std;

void sieve(int N) {
    if (N <= 2) {
        cout << "No primes less than " << N << endl;
        return;
    }

    vector<bool> isPrime(N, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i < N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    cout << "\nPrimes less than " << N << ": ";
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int N;

    cout << "Enter a number N: ";
    cin >> N;

    sieve(N);
    return 0;
}

