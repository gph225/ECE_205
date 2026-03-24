#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int getSize();
void getNumbers(int numbers[], int size);
int findMax(int numbers[], int size);
void makeHistogram(int numbers[], int size, int bins[], int numBins);
void printHistogram(int bins[], int numBins);

int main() {
    int numbers[MAX_SIZE];
    int bins[MAX_SIZE];
    int size, maxValue, numBins;

    size = getSize();
    getNumbers(numbers, size);

    maxValue = findMax(numbers, size);
    numBins = maxValue / 10 + 1;

    makeHistogram(numbers, size, bins, numBins);
    printHistogram(bins, numBins);

    return 0;
}

int getSize() {
    int size;

    cout << "Enter the number of integers: ";
    cin >> size;

    while (size <= 0 || size > MAX_SIZE) {
        cout << "Invalid input. Enter a number from 1 to " << MAX_SIZE << ": ";
        cin >> size;
    }

    return size;
}

void getNumbers(int numbers[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];

        while (numbers[i] < 0) {
            cout << "Invalid input. Enter a non-negative integer: ";
            cin >> numbers[i];
        }
    }
}

int findMax(int numbers[], int size) {
    int maxValue = numbers[0];
    int i;

    for (i = 1; i < size; i++) {
        if (numbers[i] > maxValue) {
            maxValue = numbers[i];
        }
    }

    return maxValue;
}

void makeHistogram(int numbers[], int size, int bins[], int numBins) {
    int i;
    int binIndex;

    for (i = 0; i < numBins; i++) {
        bins[i] = 0;
    }

    for (i = 0; i < size; i++) {
        binIndex = numbers[i] / 10;
        bins[binIndex]++;
    }
}

void printHistogram(int bins[], int numBins) {
    int i;

    cout << endl;
    cout << "Histogram:" << endl;

    for (i = 0; i < numBins; i++) {
        cout << i * 10 << " - " << i * 10 + 9 << ": " << bins[i] << endl;
    }
}