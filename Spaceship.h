#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <algorithm>
#include <iostream>
#include <string>

class Currency;

class Spaceship {
protected:
  int fuel_capacity;
  int crew_capacity;
  int current_fuel;
  int current_crew;
  std::string ascii_art; 
  Currency *currency;    

public:
  Spaceship(int fuel_cap, int crew_cap, const std::string &art)
      : fuel_capacity(fuel_cap), crew_capacity(crew_cap),
        current_fuel(fuel_cap), current_crew(crew_cap), ascii_art(art),
        currency(nullptr) {}

  int getFuelCapacity() const { return fuel_capacity; }
  int getCrewCapacity() const { return crew_capacity; }
  int getCurrentFuel() const { return current_fuel; } 
  int getCurrentCrew() const { return current_crew; } 

  void refuel(int fuel) {
    current_fuel = std::min(fuel_capacity, current_fuel + fuel);
  }
//crew members 
  void embark(int crew) {
    current_crew = std::min(crew_capacity, current_crew + crew);
  }

  void disembark(int crew) { current_crew = std::max(0, current_crew - crew); }
//crew members 


  void addCrew(int crew) { current_crew += crew; }

  void removeCrew(int crew) { current_crew = std::max(0, current_crew - crew); }
//had some issues so made 2 functions for adding and removing crew members
  bool canTravel(int fuel_needed) { return current_fuel >= fuel_needed; }

  void reduceFuel(int amount) {
    current_fuel = std::max(0, current_fuel - amount);
  }

  void displayArt() const { std::cout << ascii_art << std::endl; }
  void increaseFuelCapacity(int amount) { fuel_capacity += amount; }

  // Set the currency object associated with the spaceship
  void setCurrency(Currency *currency) { this->currency = currency; }

  // Access to currency object
  Currency *getCurrency() { return currency; }
};

class CargoSpaceShip : public Spaceship {
public:
  static const std::string ascii_art;

  CargoSpaceShip(int fuel_cap, int crew_cap)
      : Spaceship(fuel_cap, crew_cap * 1.5, ascii_art) {}
};

const std::string CargoSpaceShip::ascii_art = "       !       \n"
                                              "       !       \n"
                                              "       ^       \n"
                                              "      / \\      \n"
                                              "     /___\\     \n"
                                              "    |=   =|    \n"
                                              "    |     |    \n"
                                              "    |     |    \n"
                                              "    |     |    \n"
                                              "    |     |    \n"
                                              "    |     |    \n"
                                              "    |     |    \n"
                                              "    |     |    \n"
                                              "    |     |    \n"
                                              "   /|##!##|\\   \n"
                                              "  / |##!##| \\  \n"
                                              " /  |##!##|  \\ \n"
                                              "|  / ^ | ^ \\  |\n"
                                              "| /  ( | )  \\ |\n"
                                              "|/   ( | )   \\|\n";

class SmallSpaceShip : public Spaceship {
public:
  static const std::string ascii_art;

  SmallSpaceShip(int fuel_cap, int crew_cap)
      : Spaceship(fuel_cap * 2, crew_cap, ascii_art) {}
};

const std::string SmallSpaceShip::ascii_art = "      ___      \n"
                                              " ___/   \\___ \n"
                                              "/   '---'   \\\n"
                                              "'--_______--'\n";

#endif 
