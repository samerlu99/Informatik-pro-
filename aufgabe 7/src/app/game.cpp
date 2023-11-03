#include "game.h"
#include <string>
using std::string;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <iomanip>
using std::left;
using std::setw;
#include <vector>
using std::vector;
#include <array>
using std::array;
#include <queue>
using std::priority_queue;
#include <thread>
using std::this_thread::sleep_for;
#include <chrono>
using std::chrono::seconds;
using msec = std::chrono::milliseconds;
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
#include "Coordinates.h"
using Sea::Coordinates;
#include "Missile.h"
using GameObjects::Missile;
#include "TumblingMissile.h"
using GameObjects::TumblingMissile;
#include "DoubleMissile.h"
using GameObjects::DoubleMissile;
#include "PlayerSea.h"
using GameObjects::PlayerSea;
#include "init.h"
#include "utils.h"
using Utils::n_endl;



// TODO Aufgabe 1:
void gameLoop(array<PlayerSea, 2> & playerSeas)
{
    unsigned int startingPlayerOffset = startGame(playerSeas[0].getPlayerName(), playerSeas[1].getPlayerName());
    for (unsigned int turn = 0;; ++turn) {
        PlayerSea & currentPlayerSea = playerSeas[(turn + startingPlayerOffset)     % 2];
        PlayerSea & otherPlayerSea   = playerSeas[(turn + startingPlayerOffset + 1) % 2];

        bool finished = gameTurn(currentPlayerSea, otherPlayerSea, turn / 2);
        if (finished) {
            break;
        }
    }
}

unsigned int startGame(std::string const & playerName0, std::string const & playerName1)
{
    unsigned int firstTurn = getStartingPlayerIdx(playerName0, playerName1);
    cout << endl << (firstTurn ? playerName1 : playerName0) << " darf beginnen. Tippe [Enter] zum Starten...";
    getchar();
    cout << "Los geht's." << n_endl(2);
    return firstTurn;
}

unsigned int getStartingPlayerIdx(string const & playerName0, string const & playerName1)
{
    cout << "Wer bekommt den ersten Zug?" << n_endl(2);
    auto nums0 = getPlayerRandomNumbers(playerName0),
         nums1 = getPlayerRandomNumbers(playerName1);
    cout << "Wir vergleichen nacheinander die jeweils hoechsten Augenzahlen:" << endl;

    // TODO Aufgabe 3:
    //  Vergleicht hier die beiden Listen von Augenzahlen (nums0, nums1), wie im Aufgabenblatt angegeben.
    //  Hinweis: Auch die Funktion `getPlayerRandomNumbers(..)` darf dazu angepasst werden.
// done
    cout << left << setw(19) << playerName0 << " " << playerName1 << endl;
    return compareNumbers(nums0, nums1);
}

unsigned int compareNumbers(priority_queue<unsigned int> & nums0, priority_queue<unsigned int> & nums1)
{
    while (!nums0.empty()) {
        auto const n0 = nums0.top(),
                   n1 = nums1.top();
        nums0.pop();
        nums1.pop();
        cout << left << setw(10) << n0
             << setw(10) << (n0 > n1 ? ">" : (n1 > n0 ? "<" : "="))
             << n1 << endl;
        if (n0 > n1) return 0;
        else if (n1 > n0) return 1;
    }
    return 0;
}
//done
priority_queue<unsigned int> getPlayerRandomNumbers(string const & playerName)
{
    cout << playerName << " laesst die Wuerfel rollen ..." << endl;
    priority_queue<unsigned int> nums;
    for (auto i = 0; i < 10; ++i) {
        sleep_for(msec(i * i * 10));
        auto num = getRandomNumber();
        nums.push(num);
        cout << num << " ";
    }
    cout << n_endl(2);
    return nums;
}

unsigned int getRandomNumber()
{
    static random_device randomNumberInitializer;
    static mt19937 randomNumbers(randomNumberInitializer());
    static uniform_int_distribution<unsigned int> int1to6(1, 6);

    return int1to6(randomNumbers);
}

bool gameTurn(PlayerSea & currentPlayerSea, PlayerSea & otherPlayerSea, unsigned int round)
{
    cout << "Runde " << round << n_endl(2) << currentPlayerSea;

    selectTypeAndSendMissile(currentPlayerSea, otherPlayerSea, round);

    if (!checkGameFinished(currentPlayerSea, otherPlayerSea)) {
        printCountdownToNextRound();
        return false;
    }
    return true;
}

void selectTypeAndSendMissile(PlayerSea & currentPlayerSea, PlayerSea & otherPlayerSea, unsigned int round)
{
    bool hit;
    switch (round % 3) {
        case 2: hit = sendMissile<TumblingMissile>(currentPlayerSea, otherPlayerSea); break;
        case 1: hit = sendMissile<DoubleMissile>(currentPlayerSea, otherPlayerSea); break;
        default: hit = sendMissile<Missile>(currentPlayerSea, otherPlayerSea);
    }
    cout << endl << (hit ? "Treffer!" : "Daneben!") << endl << string(80, '=') << endl;
}

Coordinates inputMissileTargetCoordinates(PlayerSea const & currentPlayerSea, std::string const & missileType)
{
    while (true) {
        cout << currentPlayerSea.getPlayerName() << " zielt mit einer " << missileType << " auf" << endl;
        Coordinates targetCoordinates = inputCoordinates();

        if (!PlayerSea::isInsideSeaBounds(targetCoordinates)) {
            cout << "Diese Koordinaten liegen nicht im Spielfeld." << endl;
            continue;
        }
        return targetCoordinates;
    }
}

bool checkGameFinished(PlayerSea const & currentPlayerSea, PlayerSea const & otherPlayerSea)
{
    if (otherPlayerSea.allShipsDestroyed()) {
        cout << "Das letzte Schiff von " << otherPlayerSea.getPlayerName() << " ist versenkt. "
             << currentPlayerSea.getPlayerName() << " hat gewonnen." << endl
             << currentPlayerSea;
        return true;
    }
    return false;
}

void printCountdownToNextRound()
{
#ifndef EXERCISE_SKIP_WAITING
    sleep_for(seconds(2));
#endif
    cout << "Spielerwechsel in..." << n_endl(4);
#ifndef EXERCISE_SKIP_WAITING
    sleep_for(seconds(1));
#endif
    for (int i = 3; i > 0; --i) {
        cout << i << "..." << n_endl(4);
#ifndef EXERCISE_SKIP_WAITING
        sleep_for(seconds(1));
#endif
    }
}

// TODO Aufgabe 1:
void printStats(array<PlayerSea, 2> & playerSeas)
{
    cout << "Spielstatistik:" << n_endl(2);
    for (auto const & playerSea : playerSeas) {
        cout << playerSea.getPlayerName() << endl;
        playerSea.printStats();
        cout << endl;
    }
}
