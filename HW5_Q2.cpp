#include <iostream>
using namespace std;

class Pizza {
private:
    string type;
    string size;
    int toppings;

public:
    // Mutators
    void setType(string t) { type = t; }
    void setSize(string s) { size = s; }
    void setToppings(int t) { toppings = t; }

    // Accessors
    string getType() { return type; }
    string getSize() { return size; }
    int getToppings() { return toppings; }

    void outputDescription() {
        cout << size << " " << type 
             << " pizza with " << toppings 
             << " topping(s)" << endl;
    }

    double computePrice() {
        double base;

        if (size == "small") base = 10;
        else if (size == "medium") base = 14;
        else base = 17;

        return base + (2 * toppings);
    }
};

int main() {
    Pizza p;

    p.setType("deep dish");
    p.setSize("large");
    p.setToppings(3);

    p.outputDescription();
    cout << "Price: $" << p.computePrice() << endl;

    return 0;
}