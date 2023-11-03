#ifndef BLATT7_INIT_H
#define BLATT7_INIT_H


#include <string>
#include <array>

#include "Coordinates.h"
#include "Object.h"

#include "PlayerSea.h"
#include "Ship.h"


// TODO Aufgabe 1:
//  Passt die Funktionsdeklaration und -definition an den neuen Typ von `playerSeas` an.
void initializePlayerSeasWithShips(std::array<GameObjects::PlayerSea, 2> & playerSeas);
std::string inputPlayerName();

void initializeShips(GameObjects::PlayerSea & playerSea);
bool initializeShip(GameObjects::PlayerSea & playerSea, unsigned int size);
GameObjects::Ship inputShip(unsigned int size);

Sea::Coordinates inputCoordinates();
Sea::Orientation inputOrientation();
bool checkForInputError();


#endif //BLATT7_INIT_H
