#ifndef BLATT7_GAME_H
#define BLATT7_GAME_H


#include <string>
#include <array>
#include <queue>

#include "Coordinates.h"

#include "PlayerSea.h"


// TODO Aufgabe 1:
//  Passt die Funktionsdeklaration und -definition an den neuen Typ von `playerSeas` an.
void gameLoop(std::array<GameObjects::PlayerSea, 2> & playerSeas);


unsigned int startGame(std::string const & playerName0, std::string const & playerName1);

unsigned int getStartingPlayerIdx(std::string const & playerName0, std::string const & playerName1);

unsigned int compareNumbers(std::priority_queue<unsigned int> & nums0, std::priority_queue<unsigned int> & nums1);

std::priority_queue<unsigned int> getPlayerRandomNumbers(std::string const & playerName);

unsigned int getRandomNumber();


bool gameTurn(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea, unsigned int round);

void selectTypeAndSendMissile(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea, unsigned int round);

template<class T>
bool sendMissile(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea);

Sea::Coordinates inputMissileTargetCoordinates(GameObjects::PlayerSea const & currentPlayerSea, std::string const & missileType);


bool checkGameFinished(GameObjects::PlayerSea const & currentPlayerSea, GameObjects::PlayerSea const & otherPlayerSea);

void printCountdownToNextRound();


// TODO Aufgabe 1:
//  Passt die Funktionsdeklaration und -definition an den neuen Typ von `playerSeas` an.
void printStats(std::array<GameObjects::PlayerSea, 2> & playerSeas);


#include "game.inl"


#endif //BLATT7_GAME_H
