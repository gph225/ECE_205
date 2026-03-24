#include <iostream>
using namespace std;

const int NUM_JUDGES = 7;

double getDifficulty();
void getScores(double scores[]);
double findHighest(double scores[]);
double findLowest(double scores[]);
double findSum(double scores[]);
double calculateScore(double scores[], double difficulty);

int main() {
    double scores[NUM_JUDGES];
    double difficulty;
    double finalScore;

    difficulty = getDifficulty();
    getScores(scores);
    finalScore = calculateScore(scores, difficulty);

    cout << endl;
    cout << "Final score: " << finalScore << endl;

    return 0;
}

double getDifficulty() {
    double difficulty;

    cout << "Enter degree of difficulty (1.2 to 3.8): ";
    cin >> difficulty;

    while (difficulty < 1.2 || difficulty > 3.8) {
        cout << "Invalid input. Enter degree of difficulty from 1.2 to 3.8: ";
        cin >> difficulty;
    }

    return difficulty;
}

void getScores(double scores[]) {
    int i;

    for (i = 0; i < NUM_JUDGES; i++) {
        cout << "Enter judge score " << i + 1 << ": ";
        cin >> scores[i];

        while (scores[i] < 0 || scores[i] > 10) {
            cout << "Invalid input. Enter a score from 0 to 10: ";
            cin >> scores[i];
        }
    }
}

double findHighest(double scores[]) {
    double highest = scores[0];
    int i;

    for (i = 1; i < NUM_JUDGES; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }

    return highest;
}

double findLowest(double scores[]) {
    double lowest = scores[0];
    int i;

    for (i = 1; i < NUM_JUDGES; i++) {
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }

    return lowest;
}

double findSum(double scores[]) {
    double sum = 0;
    int i;

    for (i = 0; i < NUM_JUDGES; i++) {
        sum = sum + scores[i];
    }

    return sum;
}

double calculateScore(double scores[], double difficulty) {
    double sum, highest, lowest;

    sum = findSum(scores);
    highest = findHighest(scores);
    lowest = findLowest(scores);

    sum = sum - highest - lowest;

    return sum * difficulty * 0.6;
}