#include <iostream>
#include <vector>
using namespace std;

void buildHistogram(const vector<int>& nums) {
    if (nums.empty()) return;

    int maxVal = nums[0];
    for (int n : nums) {
        if (n > maxVal) maxVal = n;
    }

    int numBins = maxVal / 10 + 1;
    vector<int> bins(numBins, 0);

    for (int n : nums) {
        bins[n / 10]++;
    }

    cout << "\nHistogram:\n";
    for (int i = 0; i < numBins; i++) {
        cout << i * 10 << "-" << i * 10 + 9 << ": " << bins[i] << endl;
    }
}

int main() {
    vector<int> nums;
    int x;

    cout << "Enter integers (negative number to stop): ";
    while (cin >> x && x >= 0) {
        nums.push_back(x);
    }

    buildHistogram(nums);
    return 0;
}