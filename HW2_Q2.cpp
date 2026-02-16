#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int NUM_SCORES = 5;

void readScores(const char filename[], double scores[], int size);
double computeAverage(const double scores[], int size);
double computeStdDev(const double scores[], int size, double avg);
void writeResults(const char outFilename[], double avg, double sd);

int main() {
    double scores[NUM_SCORES];

    readScores("scores.txt", scores, NUM_SCORES);

    double avg = computeAverage(scores, NUM_SCORES);
    double sd  = computeStdDev(scores, NUM_SCORES, avg);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Average: " << avg << endl;
    cout << "Standard Deviation: " << sd << endl;

    writeResults("output.txt", avg, sd);

    return 0;
}

void readScores(const char filename[], double scores[], int size) {
    ifstream fin;
    fin.open(filename);

    if (!fin) {
        cout << "Error: Could not open " << filename << endl;
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fin >> scores[i];
    }

    fin.close();
}

double computeAverage(const double scores[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum = sum + scores[i];
    }
    return sum / size;
}

double computeStdDev(const double scores[], int size, double avg) {
    double sumSq = 0.0;
    for (int i = 0; i < size; i++) {
        double diff = scores[i] - avg;
        sumSq = sumSq + diff * diff;
    }
    return sqrt(sumSq / size);
}

void writeResults(const char outFilename[], double avg, double sd) {
    ofstream fout;
    fout.open(outFilename);

    fout.setf(ios::fixed);
    fout.setf(ios::showpoint);
    fout.precision(2);

    fout << "Average: " << avg << endl;
    fout << "Standard Deviation: " << sd << endl;

    fout.close();
}
