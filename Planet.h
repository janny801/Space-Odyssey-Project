#ifndef PLANET_H
#define PLANET_H

#include "ExplorationEvent.h" 
#include <memory>
#include <string>
#include <vector>

class Planet {
private:
  std::string name;
  std::string description;
  int fuel_required;
  int hostility_level;
  std::vector<std::unique_ptr<ExplorationEvent>> explorationEvents;

public:
  Planet(const std::string &name, const std::string &description,
         int fuel_required, int hostility_level)
      : name(name), description(description), fuel_required(fuel_required),
        hostility_level(hostility_level) {}

  std::string getName() const { return name; }

  std::string getDescription() const { return description; }

  int getFuelRequired() const { return fuel_required; }

  int getHostilityLevel() const { return hostility_level; }

  void addExplorationEvent(std::unique_ptr<ExplorationEvent> event) {
    explorationEvents.push_back(std::move(event));
  }

  void triggerRandomExplorationEvent(Spaceship &spaceship, Currency &currency) {
    if (!explorationEvents.empty()) {
      int eventIndex = std::rand() % explorationEvents.size();
      explorationEvents[eventIndex]->triggerEvent(
          spaceship, currency); // Pass both spaceship and currency
    }
  }
};

#endif 
