#include <iostream>
#include <cmath>
using namespace std;

//maximum score
int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// minimum score
int findMin(int arr[], int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

// calculate average
double findAverage(int arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// calculate standard deviation
double findStdDev(int arr[], int size) {
    double mean = findAverage(arr, size);
    double sum = 0;

    for (int i = 0; i < size; i++) {
        sum += pow(arr[i] - mean, 2);
    }

    return sqrt(sum / size);
}

int main() {
    const int MAX_SIZE = 100;
    int scores[MAX_SIZE];
    int count = 0;
    int input;

    cout << "Enter exam scores (0–100). Enter a negative number to stop:\n";

    while (true) {
        cin >> input;

        if (input < 0) {
            break; 
        }

        if (input <= 100) {
            scores[count] = input;
            count++;
        } else {
            cout << "Score above 100 ignored.\n";
        }

        if (count == MAX_SIZE) {
            break; 
        }
    }

    if (count == 0) {
        cout << "No valid scores entered.\n";
        return 0;
    }

    //display results
    cout << "\nResults:\n";
    cout << "Maximum Score: " << findMax(scores, count) << endl;
    cout << "Minimum Score: " << findMin(scores, count) << endl;
    cout << "Average Score: " << findAverage(scores, count) << endl;
    cout << "Standard Deviation: " << findStdDev(scores, count) << endl;

    return 0;
}