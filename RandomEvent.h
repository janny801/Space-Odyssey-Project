#ifndef RANDOMEVENT_H
#define RANDOMEVENT_H

#include "Spaceship.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

class RandomEvent {
public:
  RandomEvent() {}
  virtual ~RandomEvent() {}

  virtual void triggerEvent(Spaceship &spaceship) = 0;
};

class StrangerEvent : public RandomEvent {
public:
  StrangerEvent() {}

  void triggerEvent(Spaceship &spaceship) override {
    std::srand(std::time(nullptr));
    int outcome = std::rand() % 2;

    if (outcome == 0) {

      std::cout << "           .-\"\"\"\"\"-.       .-\"\"\"\"\"-.\n"
                   "          /        \\     /        \\\n"
                   "         /_        _\\   /_        _\\\n"
                   "        // \\      / \\\\ // \\      / \\\\\n"
                   "        |\\__\\    /__/| |\\__\\    /__/|\n"
                   "         \\    ||    /   \\    ||    /\n"
                   "          \\        /     \\        /\n"
                   "           \\  __  /       \\  __  /\n"
                   "   .-\"\"\"\"-. '.__.'.-\"\"\"\"-. '.__.'.-\"\"\"\"-.\n"
                   "  /        \\ |  |/        \\ |  |/        \\\n"
                   " /_        _\\|  /_        _\\|  /_        _\\\n"
                   "// \\      / \\\\ // \\      / \\\\ // \\      / \\\\\n"
                   "||\\__\\    /__/| |\\__\\    /__/| |\\__\\    /__/|\n"
                   "|| \\    ||    /   \\    ||    /   \\    ||    /\n"
                   "||  \\        /     \\        /     \\        /\n"
                   "||   \\  __  /       \\  __  /       \\  __  /\n"
                   "||    '.__.'         '.__.'         '.__.'\n"
                   "jgs  |  |           |  |           |  |\n"
                   "     |  |           |  |           |  |\n\n"

                << "\n\nYou encounter a friendly stranger who shares valuable "
                   "information about the planet."
                << std::endl;
      std::cout << "He joins your crew and brings some of his friends."
                << std::endl;
      spaceship.addCrew(5);
      std::cout << "You now have " << spaceship.getCurrentCrew() << " members\n\n"
                << std::endl; // Increase crew members by 5
    } else {
      std::cout << "       _..._       \n"
                   "     .'     '.     \n"
                   "    /`\\     /`\\    |\\ \n"
                   "   (__|     |__)|\\  \\\\  /|\n"
                   "   (     \"     ) \\\\ || //\n"
                   "    \\         /   \\\\||//\n"
                   "     \\   _   /  |\\|`  /\n"
                   "      '.___.'   \\____/\n"
                   "       (___)    (___)\n"
                   "     /`     `\\  / /\n"
                   "    |         \\/ /\n"
                   "    | |     |\\  /\n"
                   "    | |     | \"`\n"
                   "    | |     |\n"
                   "    | |     |\n"
                   "    |_|_____| \n"
                   "   (___)_____)\n"
                   "   /    \\   |\n"
                   "  /   |\\|   |\n"
                   " //||\\\\  Y  |\n"
                   "|| || \\\\ |  |\n"
                   "|/ \\\\ |\\||  |\n"
                   "    \\||__|__|\n"
                   "     (___|___)\n"
                   "     /   A   \\\n"
                   "    /   / \\   \\\n"
                   "   \\___/   \\___/"
                << "\n\nYou encounter a stranger leads you into a trap! He steals "
                   "some of your fuel but you escape with only minor losses.\n"
                << std::endl;
      spaceship.reduceFuel(50);
      std::cout << "You now have " << spaceship.getCurrentFuel()
                << " units of fuel left." << std::endl;
      ; // Reduce fuel by 50 
    }
  }
};

class FuelLeakEvent : public RandomEvent {
public:
  FuelLeakEvent() {}

  void triggerEvent(Spaceship &spaceship) override {
    int initialFuel = spaceship.getCurrentFuel();
    std::srand(std::time(nullptr));
    int severity = std::rand() % 4;

    if (severity == 0) {
      std::cout << "\nMinor fuel leak detected. Some fuel loss, but manageable."
                << std::endl;
      spaceship.reduceFuel(10);
    } else if (severity == 1) {
      std::cout << "\nSignificant fuel leak! Immediate action required to "
                   "prevent major loss."
                << std::endl;
      spaceship.reduceFuel(25);
    } else if (severity == 2) {
      std::cout
          << "\nMajor fuel leak! Critical situation, risk of being stranded."
          << std::endl;
      spaceship.reduceFuel(50);
    } else {
      std::cout << "\nShip is in full working capacity. No fuel leak detected."
                << std::endl;
      return; // No fuel leak, so no further action required
    }

    int fuelLost = initialFuel - spaceship.getCurrentFuel();
    std::cout << "\nYou lost " << fuelLost << " units of fuel. \nYou now have "
              << spaceship.getCurrentFuel() << " units of fuel left."
              << std::endl;
  }
};

#endif
