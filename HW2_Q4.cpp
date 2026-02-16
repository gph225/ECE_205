#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUM_FINALISTS = 25;
const int NUM_PRIZES = 4;

bool alreadyPicked(const int picks[], int count, int candidate);

int main() {
    int picks[NUM_PRIZES];

    // seed randomness
    srand((unsigned)time(0));

    int count = 0;
    while (count < NUM_PRIZES) {
        int candidate = (rand() % NUM_FINALISTS) + 1; // 1..25

        if (!alreadyPicked(picks, count, candidate)) {
            picks[count] = candidate;
            count++;
        }
    }

    cout << "Prize winners (unique finalists):" << endl;
    for (int i = 0; i < NUM_PRIZES; i++) {
        cout << picks[i] << endl;
    }

    return 0;
}

bool alreadyPicked(const int picks[], int count, int candidate) {
    for (int i = 0; i < count; i++) {
        if (picks[i] == candidate) {
            return true;
        }
    }
    return false;
}
