#ifndef BLATT8_INIT_H
#define BLATT8_INIT_H


#include <string>
#include <array>

#include "Coordinates.h"
#include "Object.h"

#include "PlayerSea.h"
#include "Ship.h"


void initializePlayerSeasWithShips(std::array<GameObjects::PlayerSea, 2> & playerSeas);
std::string inputPlayerName();

void initializeShips(GameObjects::PlayerSea & playerSea);
bool initializeShip(GameObjects::PlayerSea & playerSea, unsigned int size);
GameObjects::Ship inputShip(unsigned int size);

Sea::Coordinates inputCoordinates();
Sea::Orientation inputOrientation();
bool checkForInputError();


#endif //BLATT8_INIT_H
