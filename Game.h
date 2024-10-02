#ifndef GAME_H
#define GAME_H

#include "Currency.h"
#include "ExplorationEvent.h"
#include "Planet.h"
#include "RandomEvent.h"
#include "Spaceship.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

class Game {
private:
  std::vector<std::unique_ptr<Spaceship>> spaceships;
  std::vector<std::unique_ptr<Planet>> planets;
  Spaceship *selectedSpaceship;
  Currency currency;

public:
  // spaceship and planet display
  Game() : selectedSpaceship(nullptr) {
    spaceships.push_back(std::make_unique<CargoSpaceShip>(100, 10));
    spaceships.push_back(std::make_unique<SmallSpaceShip>(500, 5));

    planets.push_back(
        std::make_unique<Planet>("Planet Alpha\n\n\n "
                                 "         ,MMM8&&&.         \n"
                                 "    _...MMMMM88&&&&..._    \n"
                                 " .::'''MMMMM88&&&&&&'''::. \n"
                                 "::     MMMMM88&&&&&&     ::\n"
                                 "'::....MMMMM88&&&&&&....::'\n"
                                 "   `''''MMMMM88&&&&''''`   \n"
                                 "         'MMM8&&&'         \n\n\n",
                                 "A desert world with ancient ruins.", 50, 2));
    planets.push_back(
        std::make_unique<Planet>("Planet Beta \n"
                                 "o               .        ___---___           "
                                 "         .                   \n"
                                 "       .              .--\\        --.     . "
                                 "    .         .            \n"
                                 "                    ./.;_.\\     __/~ \\.    "
                                 "                            \n"
                                 "                   /;  / `-'  __\\    . \\   "
                                 "                            \n"
                                 " .        .       / ,--'     / .   .;   \\   "
                                 "     |                      \n"
                                 "                 | .|       /       __   |   "
                                 "   -O-       .             \n"
                                 "                |__/    __ |  . ;   \\ | . | "
                                 "     |                      \n"
                                 "                |      /  \\\\_    . ;| "
                                 "\\___|                             \n"
                                 "   .    o       |      \\  .~\\\\___,--'     "
                                 "|           .                \n"
                                 "                 |     | . ; ~~~~\\_    __|  "
                                 "                             \n"
                                 "    |             \\    \\   .  .  ; \\  /_/ "
                                 "  .                           \n"
                                 "   -O-        .    \\   /         . |  ~/    "
                                 "              .            \n"
                                 "    |    .          ~\\ \\   .      /  /~    "
                                 "      o                    \n"
                                 "  .                   ~--___ ; ___--~        "
                                 "                           \n"
                                 "                 .          ---         .    "
                                 "          -               \n",
                                 "A lush, forested planet.", 30, 1));
    planets.push_back(
        std::make_unique<Planet>("Planet Gamma \n  "
                                 "        ~+\n"
                                 "\n"
                                 "                 *       +\n"
                                 "           '                  |\n"
                                 "       ()    .-.,=\"``\"=.    - o -\n"
                                 "             '=/_       \\     |\n"
                                 "          *   |  '=._    |\n"
                                 "               \\     `=./`,        '\n"
                                 "            .   '=.__.=' `='      *\n"
                                 "   +                         +\n"
                                 "        O      *        '       .\n"
                                 "   ",
                                 "An icy world with harsh conditions.", 70, 3));
  }

  void displaySpaceships() {
    std::cout << "Available Spaceships:\n" << std::endl;
    for (size_t i = 0; i < spaceships.size(); ++i) {
      std::cout << "Spaceship " << i + 1 << ":\n";
      spaceships[i]->displayArt();
      std::cout << "Fuel capacity: " << spaceships[i]->getFuelCapacity()
                << "\nCrew capacity: " << spaceships[i]->getCrewCapacity()
                << "\n\n";
    }
  }

  void selectSpaceship() {
    displaySpaceships();
    std::cout << "  +------------------------+\n"
                 "  |        Spaceship       |\n"
                 "  |         1      2       |\n"
                 "  |  Type your # selection |\n"
                 "  +------------------------+";
    ;
    int choice;
    std::cin >> choice;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter a number." << std::endl;
      selectSpaceship();
      return;
    }

    if (choice > 0 && choice <= spaceships.size()) {
      selectedSpaceship = spaceships[choice - 1].get();
      std::cout << "You have selected the spaceship with fuel capacity "
                << selectedSpaceship->getFuelCapacity() << " and crew capacity "
                << selectedSpaceship->getCrewCapacity() << std::endl;
    } else {
      std::cout << "Invalid selection. Please try again." << std::endl;
      selectSpaceship();
    }
  }

  void displayPlanets() {
    std::cout << "\nAvailable Planets: (type '0' to enter the shop)\n"
              << std::endl;
    for (size_t i = 0; i < planets.size(); ++i) {
      std::cout << "Planet " << i + 1 << ": " << planets[i]->getName() << "-"
                << planets[i]->getDescription() << "\n"
                << "Hostility Level: " << planets[i]->getHostilityLevel()
                << "\n"
                << "Fuel Required: " << planets[i]->getFuelRequired() << "\n\n";
    }

    // Display remaining fuel of the selected spaceship
    std::cout << "You have " << selectedSpaceship->getCurrentFuel()
              << " units of fuel. Which planet would you like to go to?"
              << std::endl;
  }

  void shop() {
    std::cout << "       .-\"\"\"\"\"-.\n"
                 "          |==  ==|-.  \n"
                 "          |~~ ~~~|`\\ \n"
                 "          |Gas   | || \n"
                 "          |      |// \n"
                 "          |      |/  \n"
                 "          |      |   \n"
                 "        __|______|__ \n"
                 "       [____________]"
              << "\nWelcome to the Shop!\n";
    std::cout << "Your current balance: " << currency.getBalance()
              << " fuel units\n";

    int fuelToBuy;
    std::cout << "Enter the amount of fuel to purchase (0 to exit the shop): ";
    std::cin >> fuelToBuy;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout
          << "Invalid input. Please enter a valid amount of fuel to buy.\n";
      return;
    }

    if (fuelToBuy == 0) {
      std::cout << "Leaving the shop.\n";
      return;
    }

    if (fuelToBuy < 0) {
      std::cout
          << "Invalid input. Please enter a positive amount of fuel to buy.\n";
      return;
    }

    if (currency.canAfford(fuelToBuy)) {
      currency.spendCurrency(fuelToBuy);
      selectedSpaceship->refuel(fuelToBuy);
      std::cout << "You have purchased " << fuelToBuy << " units of fuel.\n";
      std::cout << "Remaining balance: " << currency.getBalance()
                << " fuel units\n";
    } else {
      std::cout
          << "You don't have enough fuel units to purchase that much fuel.\n";
    }
  }

  // bool explore planet
  bool explorePlanet(Planet &planet) {
    std::cout << "Exploring " << planet.getName() << "...\n" << std::endl;

    int fuelRequired = planet.getFuelRequired();
    selectedSpaceship->reduceFuel(fuelRequired);

    std::cout << "You have arrived at " << planet.getName() << ". You now have "
              << selectedSpaceship->getCurrentFuel()
              << " units of fuel remaining." << std::endl;

    //  Stranger event with a 1/4
    // probability
    if (std::rand() % 2 == 0) {
      StrangerEvent strangerEvent;
      strangerEvent.triggerEvent(*selectedSpaceship);
    }

    bool rechoose = false;
    do {
      if (selectedSpaceship->getCurrentFuel() < 0) {
        std::cout
            << "Game over. You don't have enough fuel to make the journey."
            << std::endl;
        return false;
      }

      int choice;
      std::cout << "Choose an exploration event:\n";
      std::cout
          << "1. Ancient Ruins Discovery\n\n"
          << "               ,@@@@@@@,\n"
          << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
          << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
          << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
          << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
          << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
          << "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
          << "       |o|        | |         | |\n"
          << "       |.|        | |         | |\n"
          << "    \\\\/ .\\_\\/\\_\\/  ,\\_\\/\\/__\\\\/.  \\_\\/\\/__/_\n\n\n";
      std::cout << "2. Treasure Chest Event\n"
                << "\n\n\n"
                   "         __________\n"
                   "        /\\____;;___\\\n"
                   "       | /         /\n"
                   "       `. ())oo() .\n"
                   "        |\\(%()*^^()^\\\n"
                   "       %| |-%-------|\n"
                   "      % \\ | %  ))   |\n"
                   "      %  \\|%________|\n"
                   "       %%%%\n\n\n";
      std::cout << "  ________________________________\n";
      std::cout << " |                                |\n";
      std::cout << " | Enter your choice: type '1' or '2' |\n";
      std::cout << " |________________________________|\n";
      std::cin >> choice;

      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter 1 or 2.\n";
      } else if (choice == 1) {
        if (planet.getName() == "Planet Gamma \n  "
                                "        ~+\n"
                                "\n"
                                "                 *       +\n"
                                "           '                  |\n"
                                "       ()    .-.,=\"``\"=.    - o -\n"
                                "             '=/_       \\     |\n"
                                "          *   |  '=._    |\n"
                                "               \\     `=./`,        '\n"
                                "            .   '=.__.=' `='      *\n"
                                "   +                         +\n"
                                "        O      *        '       .\n"
                                "   ") {
          AncientRuinsDiscovery ancientRuinsEvent;
          if (ancientRuinsEvent.triggerEvent(*selectedSpaceship, currency)) {
            if (ancientRuinsEvent.intendsToGoToSecretPlanet()) {
              std::cout << "Game over. You attempted to go to the secret "
                           "planet without enough fuel."
                        << std::endl;
              return false;
            }
            break;
          }
        } else { // For Planet Alpha and Planet Beta
          std::cout << "You discover a torn map in the ancient ruins. The "
                       "place gives you a creepy omen and you flee. "
                    << std::endl;
          break;
        }
      } else if (choice == 2) {
        TreasureChestEvent treasureChestEvent;
        if (treasureChestEvent.triggerEvent(*selectedSpaceship, currency)) {
          if (treasureChestEvent.intendsToGoToSecretPlanet()) {
            std::cout << "Game over. You attempted to go to the secret planet "
                         "without enough fuel."
                      << std::endl;
            return false;
          }
          break;
        }
      } else {
        std::cout << "Invalid choice. Please enter 1 or 2.\n";
      }

      char stayOrGo;
      std::cout << "Do you want to go to another planet (g) or stay at this "
                   "planet (s) ? ";
      std::cin >> stayOrGo;
      if (stayOrGo == 'g' || stayOrGo == 'G') {
        displayPlanets();
        std::cout << "  +-------------------------------------+\n"
                     "  | Type the # planet you want to go to |\n"
                     "  +-------------------------------------+";
        ;
        std::cin >> choice;

        if (std::cin.fail()) {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Invalid input. Please enter a number." << std::endl;
          continue;
        }

        if (choice == 0) {
          shop();
        } else if (choice > 0 && choice <= planets.size()) {
          Planet &selectedPlanet = *planets[choice - 1];
          std::cout << "Traveling to " << selectedPlanet.getName() << std::endl;
          rechoose = triggerRandomEvent();
          if (rechoose) {
            std::cout << "After your fuel leak, you may want to reconsider "
                         "where you want to go."
                      << std::endl;
          } else {
            if (selectedSpaceship->getCurrentFuel() <
                selectedPlanet.getFuelRequired()) {
              std::cout << "Game over. You don't have enough fuel to make the "
                           "journey."
                        << std::endl;
              return false;
            }
            explorePlanet(selectedPlanet);
          }
        } else {
          std::cout << "Invalid selection. Please try again." << std::endl;
        }
      }
    } while (true);

    return true;
  }

  // bool explore planet

  bool triggerRandomEvent() {
    if (std::rand() % 2 == 0) {
      FuelLeakEvent fuelLeak;
      fuelLeak.triggerEvent(*selectedSpaceship);
      return selectedSpaceship->getCurrentFuel() <
             selectedSpaceship->getFuelCapacity();
    }
    return false;
  }

  void endGame() {
    std::cout << "Congratulations! You have reached the end of the game."
              << std::endl;
  }
  void startGame() {
    std::cout << "Welcome to the Space Exploration Game!\n" << std::endl;
    selectSpaceship();

    bool continueExploring = true;
    do {
      displayPlanets();
      std::cout << "  +-------------------------------------+\n"
                   "  | Type the # planet you want to go to |\n"
                   "  +-------------------------------------+";
      ;
      int choice;
      std::cin >> choice;

      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number." << std::endl;
        continue;
      }

      if (choice == 0) {
        shop();
      } else if (choice > 0 && choice <= planets.size()) {
        Planet &selectedPlanet = *planets[choice - 1];

        if (selectedSpaceship->getCurrentFuel() <
            selectedPlanet.getFuelRequired()) {
          std::cout
              << "Game over. You don't have enough fuel to make the journey."
              << std::endl;
          break; // Exit the loop and end the game
        }

        std::cout << "Traveling to " << selectedPlanet.getName() << std::endl;
        bool rechoose = triggerRandomEvent();
        if (rechoose) {
          std::cout << "    /=//==//=/  \\  \n"
                       "    |=||==||=|    |  \n"
                       "    |=||==||=|~-, |  \n"
                       "    |=||==||=|^.`;|  \n"
                       "     \\=\\\\==\\\\=\\`.:\n"
                       "      `\"\"\"\"\"\"\"`^-,`.\n"
                       "               `.,~'\n"
                       "              ',~^:,  \n"
                       "              `.^;`.\n"
                       "               ^-.~=;.\n"
                       "                  `.^.:`."
                    << "After your fuel leak, you may want to reconsider where "
                       "you want to go."
                    << std::endl;
        } else {
          if (explorePlanet(selectedPlanet)) {
            if (selectedPlanet.getName() == "Secret Planet") {
              EndGameEvent endGameEvent;
              if (endGameEvent.triggerEvent(*selectedSpaceship, currency)) {
                endGame();
                break; // Exit the loop and end the game
              }
            }
          } else {
            break; // Exit the loop and end the game
          }
        }
      } else {
        std::cout << "Invalid selection. Please try again." << std::endl;
      }
    } while (continueExploring);
  }
};

#endif
