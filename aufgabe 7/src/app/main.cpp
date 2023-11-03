#include <array>
using std::array;

#include "PlayerSea.h"
using GameObjects::PlayerSea;

#include "init.h"
#include "game.h"
#include "test.h"


int main()
{
    if (testPassed()) {

        // TODO Aufgabe 1:
        //  Ersetzt hier den vector-Typ der Variablen `playerSeas` durch ein `std::array` der Größe 2.
        //also mussen wir here die vector typ durch ein array der grosse 2 ersetzen
        // ist ein array darstellt also playerseas enthalt zwei elmente die in player-sea array sind

        array<PlayerSea, 2> playerSeas;

#ifndef EXERCISE_SKIP_PLAYER_INIT
        initializePlayerSeasWithShips(playerSeas);
#else
        for (int i = 0; i < 2; ++i) {
            playerSeas[i].setPlayerName(i ? "Paddy" : "Flo");
            playerSeas[i].addShip(GameObjects::Ship({1, 2}, 2, Sea::Orientation::X));
        }
#endif

        gameLoop(playerSeas);

        printStats(playerSeas);
    }

    return 0;
}
