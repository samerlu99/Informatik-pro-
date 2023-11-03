// TODO:
//  Entfernt die Kommentar-Zeichen (//) für Aufgaben, die erledigt sind und getestet werden sollen:


#define TEST_AUFGABE_1
#define TEST_AUFGABE_2


#include "test.h"

#include <iostream>
using std::cout;
using std::endl;
using std::stringstream;
#include <algorithm>
using std::count;

#include "Coordinates.h"
using Sea::Coordinates;
#include "PlayerSea.h"
using GameObjects::PlayerSea;

#include "utils.h"
using Utils::n_endl;


bool testPassed()
{
    bool testResult =
            testConstructor() &&
            testOperator();

    if (testResult) {
        cout << "Test OK." << n_endl(2);
        return true;
    }
    cout << "Test fehlgeschlagen." << n_endl(2);
    return false;
}

bool testConstructor()
{
#ifdef TEST_AUFGABE_1
    PlayerSea ps;
#endif
    return true;
}

bool testOperator()
{
#ifdef TEST_AUFGABE_2
    Coordinates c1(1, 1);
    Coordinates c2(2, 2);
    return c1 < c2 || c2 < c1;
#else
    return true;
#endif
}
