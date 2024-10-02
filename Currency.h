#ifndef CURRENCY_H
#define CURRENCY_H

#include "Spaceship.h"
#include <iostream>

class Currency {
private:
  int balance;

public:
  Currency() : balance(0) {}

  // Add currency to the balance
  void addCurrency(int amount) {
    if (amount > 0) {
      balance += amount;
    }
  }

  // Check if enough currency is available
  bool canAfford(int amount) { return amount <= balance; }

  // Spend currency if enough balance is available
  bool spendCurrency(int amount) {
    if (canAfford(amount)) {
      balance -= amount;
      return true;
    } else {
      std::cout << "Insufficient currency balance." << std::endl;
      return false;
    }
  }

  // Purchase fuel for the spaceship
  void purchaseFuel(Spaceship &spaceship, int fuelAmount) {
    if (spendCurrency(fuelAmount)) {
      spaceship.refuel(fuelAmount);
      std::cout << "Purchased " << fuelAmount << " units of fuel." << std::endl;
    }
  }

  // Get the current balance
  int getBalance() const { return balance; }
};

#endif
