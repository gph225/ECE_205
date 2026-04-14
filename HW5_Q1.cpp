#include <iostream>
using namespace std;

class BicycleSpeedometer {
private:
    double distance; // miles
    double time;     // minutes

public:
    void setDistance(double d) {
        distance = d;
    }

    void setTime(double t) {
        time = t;
    }

    double computeSpeed() {
        return distance / (time / 60.0);
    }
};

int main() {
    BicycleSpeedometer bike;
    double d, t;

    cout << "Enter distance (miles): ";
    cin >> d;

    cout << "Enter time (minutes): ";
    cin >> t;

    bike.setDistance(d);
    bike.setTime(t);

    cout << "Average Speed: " << bike.computeSpeed() << " mph" << endl;

    return 0;
}