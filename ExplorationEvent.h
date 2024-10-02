#ifndef EXPLORATIONEVENT_H
#define EXPLORATIONEVENT_H

#include "Currency.h"
#include "Spaceship.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>

class ExplorationEvent {
public:
  ExplorationEvent() {}
  virtual ~ExplorationEvent() {}

  virtual bool triggerEvent(Spaceship &spaceship, Currency &currency) = 0;
  virtual bool intendsToGoToSecretPlanet() const { return false; }
};

class AncientRuinsDiscovery : public ExplorationEvent {
private:
  bool secretPlanetUnlocked;

public:
  AncientRuinsDiscovery() : secretPlanetUnlocked(false) {}

  bool triggerEvent(Spaceship &spaceship, Currency &currency) override {
    std::cout << "You are at ancient ruins of this planet\n\n" << std::endl;

    std::srand(std::time(nullptr));
    int discovery = std::rand() % 3;

    switch (discovery) {
    case 0:
      std::cout
          << "    __,          \n"
             "   .-'  /           ,--------,  \n"
             " .'    /   /`.    ,--------,' | \n"
             " |    /   /  |   |    _     | | \n"
             " |    \\__/   |   |  .' `.   | | \n"
             " `.         .'   |  `._.'   | | \n"
             "   `.     .'     |          |,',-,-,-,-,-,-,-,-,-,-,-,-,-,-==, \n"
             "     | ][ |      |__________\\------------------------------=='\n"
             "     | ][ |\n"
             "     | ][ |\n"
             "     | ][ |\n"
             "     | ][ |     .----.                                .---.\n"
             "     | ][ |    '---,  `.____________________________.'  _  `.\n"
             "     | ][ |         )   ____________________________   <_>  :\n"
             "     | ][ |    .---'  .'                            `.     .'\n"
             "     | ][ |     `----'                                `---'\n"
             "     | ][ |\n"
             "   .'  __  `.\n"
             "   |  /  \\  |     \n"
             "   |  \\__/  |\n"
             "   `.      .'\n"
             "     `----'"
          << "\n\nYou found these weird ancient tools used by a civiliation "
             "long "
             "ago!"
          << std::endl;
      spaceship.increaseFuelCapacity(100);
      std::cout << "Your spaceship's maximum fuel capacity has increased to "
                << spaceship.getFuelCapacity() << "." << std::endl;
      break;
    case 1:
      std::cout << "Among the ruins, you find a hidden cache of fuel.\n\n"
                << std::endl;
      spaceship.refuel(30); // Refuel the spaceship
      std::cout << ",.--'`````'--.,       \n"
                   "(\'-.,_____,.-'/)     \n"
                   " \\-.,_____,.-//      \n"
                   " ;\\         //|      \n"
                   " | \\  ___  // |      \n"
                   " |  '-[___]-'  |      \n"
                   " |             |      \n"
                   " |             |      \n"
                   " |    FUEL     |      \n"
                   " `'-.,_____,.-''      \n"
                << "\n\nYou gained 30 units of fuel. You now have "
                << spaceship.getCurrentFuel() << " total fuel." << std::endl;
      break;
    case 2:
      std::cout << "              .-\"\"\"\"\"-.              \n"
                   "             /        \\             \n"
                   "            /_        _\\            \n"
                   "           // \\      / \\\\           \n"
                   "           |\\__\\    /__/|           \n"
                   "            \\    ||    /            \n"
                   "             \\        /             \n"
                   "              \\  __  /  \\  /          "
                   "________________________________\n"
                   "               '.__.'    \\/          /                    "
                   "             \\\n"
                   "                |  |     /\\         |                 "
                   "Hello There!       |\n"
                   "                |  |    O  O        |          I have a "
                   "secret           |\n"
                   "                ----    //         O "
                   "\\_________________________________/\n"
                   "               (    )  //        O\n"
                   "              (\\\\     //       o\n"
                   "             (  \\\\    )      o\n"
                   "             (   \\\\   )   /\\\n"
                   "   ___[\\______/^^^^^^^\\__/) o-)__\n"
                   "  |\\__[=======______//________)__\\\n"
                   "  \\|_______________//____________|\n"
                   "      |||      || //||     |||\n"
                   "      |||      || @.||     |||\n"
                   "       ||      \\/  .\\/      ||\n"
                   "                  . ."
                << "\n\nA stranger offers to take you this secret planet. It "
                   "requires 500 fuel to get to the secret planet.  \n\n"
                << "+-------------------------------+  "
                   "+-------------------------------+  "
                   "+-------------------------------+"
                << std::endl;
      std::cout << "| 'x' explore secret planet    |  | 's' stay               "
                   "      |  | 'g' go to another planet     |"
                << std::endl;
      std::cout
          << "+-------------------------------+  "
             "+-------------------------------+  "
             "+-------------------------------+"
          << std::endl
          // "requires 500 fuel to go to. Press 'x' if you would like to make "
          // "the journey to this secret planet. If you'd like to stay press "
          //"'s' and if you'd like to go to another planet press 'g'"
          << std::endl;
      char secretChoice;
      std::cin >> secretChoice;
      if (secretChoice == 'x' || secretChoice == 'X') {
        if (spaceship.getCurrentFuel() >= 500) {
          std::cout << "Welcome to the Secret Planet!\n\n"
                    << "             ,-\"     \"-.             \n"
                       "            / o       o \\            \n"
                       "           /   \\     /   \\           \n"
                       "          /     )-\"-(     \\          \n"
                       "         /     ( 6 6 )     \\         \n"
                       "        /       \\ \" /       \\        \n"
                       "       /         )=(         \\       \n"
                       "      /   o   .--\"-\"--.   o   \\      \n"
                       "     /    I  /  -   -  \\  I    \\     \n"
                       " .--(    (_}y/\\       /\\y{_)    )--. \n"
                       "(    \".___l\\/__/\\_____/__\\/l___,\"    )\n"
                       " \\                                 / \n"
                       "  \"-._      o O o O o O o      _,-\"  \n"
                       "      `--Y--.___________.--Y--'      \n"
                       "         |==.___________.==|         \n"
                       "         '==.___________.=='         \n\n"
                       "+-----------+  +-----------+\n"
                       "|   Fight(f)|  | Explore(e)|\n"
                       "+-----------+  +-----------+\n"
                    << std::endl;
          char explorationChoice;

          std::cin >> explorationChoice;

          if (explorationChoice == 'f' || explorationChoice == 'F') {
            if (spaceship.getCurrentCrew() >= 20) {
              std::cout << "                                         )  (  (   "
                           " (                   \n"
                           "                                         (  )  () "
                           "@@  )  (( (           \n"
                           "                                     (      (  )( "
                           "@@  (  )) ) (           \n"
                           "                                   (    (  ( ()( "
                           "/---\\   (()( (         \n"
                           "     _______                            )  ) )(@ "
                           "!O O! )@@  ( ) ) )       \n"
                           "    <   ____)                      ) (  ( )( ()@ "
                           "\\ o / (@@@@@ ( ()( )    \n"
                           " /--|  |(  o|                     (  )  ) ((@@(@@ "
                           "!o! @@@@(@@@@@)() (  \n"
                           "|   >   \\___|                      ) ( @)@@)@ "
                           "/---\\-/---\\ )@@@@@()() (  \n"
                           "|  /---------+                    (@@@@)@@@( // "
                           "/-----\\ \\\\ @@@)@@@@@()(  \n"
                           "| |    \\ =========______/|@@@@@@@@@@@@@(@@@ // @ "
                           "/---\\ @ \\\\ @(@@@(@@@.  \n"
                           "|  \\   \\\\=========------\\|@@@@@@@@@@@@@@@@@ O "
                           "@@@ /-\\ @@@ O @@(@@)@@@ @  \n"
                           "|   \\   \\----+--\\-)))           @@@@@@@@@@ !! "
                           "@@@@ % @@@@ !! @@)@@@ .. .  \n"
                           "|   |\\______|_)))/             .    @@@@@@ !! @@ "
                           "/---\\ @@ !! @@(@@@ @ . .  \n"
                           " \\__==========           *        .    @@ /MM  "
                           "/\\O   O/\\  MM\\ @@@@@@@. .  \n"
                           "    |   |-\\   \\          (       .      @ !!!  "
                           "!! \\-/ !!  !!! @@@@@ .  \n"
                           "    |   |  \\   \\          )   -cfbd-   .  @@@@ "
                           "!!     !!  .(. @.  .. .  \n"
                           "    |   |   \\   \\        (    /   .(  . \\)). ( "
                           "|O  )( O! @@@@ . )      .\n"
                           "    |   |   /   /         ) (      )).  ((  .) !! "
                           "((( !! @@ (. ((. .   .\n"
                           "    |   |  /   /   ()  ))   ))   .( ( ( ) ). ( !!  "
                           ")( !! ) ((   ))  ..\n"
                           "    |   |_<   /   ( ) ( (  ) )   (( )  )).) ((/ |  "
                           "(  | \\(  )) ((. ).\n"
                           "____<_____\\\\__\\__(___)_))_((_(____))__(_(___."
                           "oooO_____Oooo.(_(_)_)((_("

                        << "\n\nYou and your crew have successfully beaten the "
                           "boss who "
                           "owned the universe. You and your crew are now in "
                           "charge.\n\nYou win!"
                        << std::endl;
              abort(); // endgame
            } else {
              std::cout << "      /_.  ._\\      \n"
                           "     (( \\\\// ))     \n"
                           "      \\\\ \\/ //      \n"
                           "       \\\\/\\//       \n"
                           "  \\\\\\  ( '' )  ///  \n"
                           "   )))  \\__/  (((   \n"
                           "  (((.'__||__'.)))  \n"
                           "   \\\\  )    (  //   \n"
                           "    \\/.'  '.\\//    \n"
                           "     \\/ |,,| \\/     \n"
                           "        |  |        \n"
                           "        |  |        \n"
                           "        //\\\\        \n"
                           "       //  \\\\       \n"
                           "      ||    ||      \n"
                           "      ||    ||      \n"
                           "      ||    ||      \n"
                           "   ___))    ((___   \n"
                           "  (____)    (____)  \n"
                        << "You were defeated in the battle. Bring a larger "
                           "crew next time.\n\nYou lost. Game over"
                        << std::endl;
              // Throw an exception to signal game over
              abort(); // endgame
            }
          } else if (explorationChoice == 'e' || explorationChoice == 'E') {
            // Gain 20 crew members
            spaceship.addCrew(20);
            std::cout
                << "        .-\"\"\"\"-.        .-\"\"\"\"-.\n"
                   "      /        \\      /        \\\n"
                   "     /_        _\\    /_        _\\\n"
                   "    // \\      / \\\\  // \\      / \\\\\n"
                   "    |\\__\\    /__/|  |\\__\\    /__/|\n"
                   "     \\    ||    /    \\    ||    /\n"
                   "      \\        /      \\        /\n"
                   "       \\  __  /        \\  __  /\n"
                   "        '.__.'          '.__.'\n"
                   "         |  |            |  |\n"
                   "         |  |            |  |\n"
                << "You meet a odd group of people and they kidnap you and "
                   "take you back to their home planet. You turn out to enjoy "
                   "their company. You gained 20 crew members. Now you have "
                << spaceship.getCurrentCrew()
                << " crew members.\n\nYou don't know how to get back and have "
                   "to find the stranger once again"
                << std::endl;
            return false;
          } else {
            std::cout << "Invalid choice. Please enter 'f' to fight or 'e' to "
                         "explore."
                      << std::endl;
          }
          secretPlanetUnlocked = true;
          return false;
        } else {
          std::cout << "You don't have enough fuel to go to the secret planet."
                    << std::endl;
        }
      } else if (secretChoice == 's' || secretChoice == 'S') {
        std::cout << "You decided not to go to the secret planet." << std::endl;
      }
      break;
    default:
      std::cout
          << "\n\n        _    .  ,   .           .     \n"
             "    *  / \\_ *  / \\_      _  *        *   /\\'__        * \n"
             "      /    \\  /    \\,   ((        .    _/  /  \\  *'. \n"
             " .   /\\/\\  /\\/ :' __ \\_  `          _^/  ^/    `--. \n"
             "    /    \\/  \\  _/  \\-'\\      *    /.' ^_   \\_   .\\  * \n"
             "  /\\  .-   `. \\/     \\ /==~=-=~=-=-;.  _/ \\ -. `_/   \\\n"
             " /  `-.__ ^   / .-'.--\\ =-=~_=-=~=^/  _ `--./ .-'  `- \n"
             "/jgs     `.  / /       `.~-^=-=~=^=.-'      '-._ `._"
          << "The ruins are fascinating, but you find nothing of "
             "immediate value.\n\n"
          << std::endl;
      break;
    }

    return false;
  }

  bool intendsToGoToSecretPlanet() const override {
    return secretPlanetUnlocked;
  }
};

class TreasureChestEvent : public ExplorationEvent {
public:
  TreasureChestEvent() {}

  bool triggerEvent(Spaceship &spaceship, Currency &currency) override {
    std::srand(std::time(nullptr));
    int outcome = std::rand() % 2;

    if (outcome == 0) {
      std::cout << "The treasure chest contains some money.\n\n"
                << "             _.oood\"\"\"\"\"\"booo._\n"
                   "         _.o\"\"   |`.  |    |   \"\"o._\n"
                   "       oP\"  |`.  |  `.|    |    |  \"Yo\n"
                   "     o8 `.  |  `.|    |.   |    |    `8o\n"
                   "    d'    `.|    |.   | `. |    |      `b\n"
                   "   d\"-------*====+====+====+====+-------\"b\n"
                   "  8'  `.    INNNNINNNNINNNNINNNNI        `8\n"
                   " 8      `.  INNNNINNNNINNNNINNNNI          8\n"
                   ",8----------+====*====+====+====+----------8.\n"
                   "8'  `.     `|    |`.  |gnnnnnnnn|.         `8\n"
                   "8     `.    |`.  |  `.|8   |.   | `.        8\n"
                   "8-----------+----+----*8---+----+-----------8\n"
                   "8        `. |   `|    |8,gnnnn:.|    `.     8\n"
                   "8.         `|    |`.  |8P\".| \"Yb|..png.`.  ,8\n"
                   "`8----------+----+----+----+---8+-8--`\"----8'\n"
                   " 8          | `. |   `|n.  |`.dP| 8`. n    8\n"
                   "  8.        |   `|    |\"YbnnndP.| `bnnP  ,8\n"
                   "   Y.-------+----+----+----+----+-------.P\n"
                   "    Y.      |    | `. |   `|    |`.    ,P\n"
                   "     \"8.    | cg |   `|    |`.  |  `. 8\"\n"
                   "       \"Y_  | mm |  19|89  |  `.|  _P\"\n"
                   "         `\"\"\"boooooood\"\"\"'"
                << std::endl;
      currency.addCurrency(50); // Add currency to the player
      std::cout << "\n\nYou gained 50 units of currency. You now have "
                << currency.getBalance() << " total currency." << std::endl;
    } else {

      std::cout << "\n\n"
                << "    /=//==//=/  \\  \n"
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
                << "\n\nIt's a trap! The treasure chest triggers a fuel leak."
                << std::endl;

      spaceship.reduceFuel(50); // Reduce fuel in the spaceship
      std::cout << "You lost 50 units of fuel. You now have "
                << spaceship.getCurrentFuel() << " total fuel." << std::endl;
    }

    char stayOrGo;
    std::cout
        << "Do you want to stay on this planet (s) or go to another one (g)? ";
    std::cin >> stayOrGo;
    if (stayOrGo == 'g' || stayOrGo == 'G') {
      std::cout << "You decided to go to another planet." << std::endl;
      return true; // Return true to indicate the player wants to go to another
                   // planet
    }

    return false; // Continue exploring on the same planet
  }
};

class EndGameEvent : public ExplorationEvent {
public:
  EndGameEvent() {}

  bool triggerEvent(Spaceship &spaceship, Currency &currency) override {
    std::cout << "Welcome to the Endgame Planet!" << std::endl;
    return true; // Return true to end the game
  }
};

#endif
