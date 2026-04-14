#include <iostream>
#include <vector>
using namespace std;

class Pizza {
private:
    string type;
    string size;
    int toppings;

public:
    void setType(string t) { type = t; }
    void setSize(string s) { size = s; }
    void setToppings(int t) { toppings = t; }

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

class Order {
private:
    vector<Pizza> pizzas;

public:
    void addPizza(Pizza p) {
        pizzas.push_back(p);
    }

    void printOrder() {
        double total = 0;

        cout << "Order Details:\n";

        for (int i = 0; i < pizzas.size(); i++) {
            pizzas[i].outputDescription();
            total += pizzas[i].computePrice();
        }

        cout << "Total Price: $" << total << endl;
    }
};

int main() {
    Pizza p1, p2;

    p1.setType("deep dish");
    p1.setSize("large");
    p1.setToppings(3);

    p2.setType("pan");
    p2.setSize("small");
    p2.setToppings(1);

    Order order;
    order.addPizza(p1);
    order.addPizza(p2);

    order.printOrder();

    return 0;
}