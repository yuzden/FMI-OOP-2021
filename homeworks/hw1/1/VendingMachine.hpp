#pragma once
#include "drink.hpp"
#include <cstring>

class VendingMachine {
public:
    VendingMachine();
    VendingMachine(const VendingMachine& from);
    VendingMachine& operator=(const VendingMachine& from);
    ~VendingMachine();

    bool add_drink(const Drink& to_add);
    int buy_drink(const char* drink_name, const double money);

    double get_income() const;

    void removeDrink(unsigned int index);
    void copyDrinks(const Drink*, unsigned int);

    int getIndex(const char*)const;
  
private:
    Drink* drinks;
    double income;
    unsigned int size;
};