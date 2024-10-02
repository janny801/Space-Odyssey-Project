#include "Game.h"

int main() {
  std::srand(std::time(nullptr)); // Seed the random number generator
  Game game;
  game.startGame();
  return 0;
}