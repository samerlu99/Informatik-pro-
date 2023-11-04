#include <array>
using std::array;

#include "PlayerSea.h"
using GameObjects::PlayerSea;

#include "init.h"
#include "game.h"


int main()
{
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

    return 0;
}
