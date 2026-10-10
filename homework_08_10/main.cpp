#include <iostream>
#include <functional>

using namespace std;

// A pricing function: hours -> price in rubles.
using Price = function<int(int)>;

int regularPrice(int hours) {
    return hours * 200;
}

int studentPrice(int hours) {
    return hours * 140;
}

// Strategy: the rental uses the selected pricing function.
class TelescopeRental {
    Price strategy;

public:
    TelescopeRental(Price price) {
        strategy = price;
    }

    void setStrategy(Price price) {
        strategy = price;
    }

    int cost(int hours) {
        return strategy(hours);
    }
};

int main() {
    int hours = 3;
    TelescopeRental rental(regularPrice);
    cout << "Regular rental: " << rental.cost(hours) << " RUB\n";
}
