#include <iostream>
#include <vector>
using namespace std;

void deleteRepeatedChars(vector<char>& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] == v[j]) {
                v.erase(v.begin() + j);
                j--; // adjust index after erase
            }
        }
    }
}

void selectionSort(vector<char>& v) {
    for (int i = 0; i < v.size() - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] > v[maxIdx]) {
                maxIdx = j;
            }
        }
        swap(v[i], v[maxIdx]);
    }
}

int main() {
    vector<char> v;
    char c;

    cout << "Enter characters (enter '0' to stop): ";
    while (cin >> c && c != '0') {
        v.push_back(c);
    }

    deleteRepeatedChars(v);
    selectionSort(v);

    cout << "\nResult (no duplicates, sorted z->a): ";
    for (char ch : v) {
        cout << ch << " ";
    }
    cout << endl;

    return 0;
}