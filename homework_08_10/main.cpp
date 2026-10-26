// У нас есть несколько тарифов выбора телескопа, стратегия заключается в том, какой тариф мы выбираем
// Декоратор добавляет стоимость чехла к  тарифу, который мы выбрали

#include <iostream>
#include <functional>

using namespace std;
using Price = function<int(int)>;
int regularPrice(int hours) {
    return hours * 200;
}
int studentPrice(int hours) {
    return hours * 140;
}
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
