#ifndef BLATT8_GAME_H
#define BLATT8_GAME_H


#include <string>
#include <array>
#include <queue>

#include "Coordinates.h"

#include "PlayerSea.h"


void gameLoop(std::array<GameObjects::PlayerSea, 2> & playerSeas);


unsigned int startGame(std::string const & playerName0, std::string const & playerName1);

unsigned int getStartingPlayerIdx(std::string const & playerName0, std::string const & playerName1);

unsigned int compareNumbers(std::priority_queue<unsigned int> & nums0, std::priority_queue<unsigned int> & nums1);

std::priority_queue<unsigned int> getPlayerRandomNumbers(std::string const & playerName);

unsigned int getRandomNumber();


bool gameTurn(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea, unsigned int round);

void selectTypeAndSendMissile(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea, unsigned int round);

bool createVortexOrSendDefaultMissile(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea, unsigned int round);

template<class T>
bool sendMissile(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea);

Sea::Coordinates inputMissileTargetCoordinates(GameObjects::PlayerSea const & currentPlayerSea, std::string const & missileType);


bool checkGameFinished(GameObjects::PlayerSea const & currentPlayerSea, GameObjects::PlayerSea const & otherPlayerSea);

void printCountdownToNextRound();


void printStats(std::array<GameObjects::PlayerSea, 2> & playerSeas);


#include "game.inl"


#endif //BLATT8_GAME_H
