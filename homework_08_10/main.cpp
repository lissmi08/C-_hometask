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

// Decorator: wrap any pricing function and add a protective case.
Price withCase(Price basePrice) {
    return [basePrice](int hours) {
        return basePrice(hours) + 50;
    };
}

int main() {
    int hours = 3;
    TelescopeRental rental(regularPrice);
    cout << "Regular rental: " << rental.cost(hours) << " RUB\n";

    rental.setStrategy(studentPrice);
    cout << "Student rental: " << rental.cost(hours) << " RUB\n";

    rental.setStrategy(withCase(studentPrice));
    cout << "Student rental with case: " << rental.cost(hours) << " RUB\n";

    rental.setStrategy(withCase(regularPrice));
    cout << "Regular rental with case: " << rental.cost(hours) << " RUB\n";
}
