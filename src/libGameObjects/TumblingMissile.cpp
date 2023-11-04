#include "TumblingMissile.h"

#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
#include <algorithm>
using std::clamp;

#include "Constants.h"


namespace GameObjects {

    TumblingMissile::TumblingMissile(Sea::Coordinates const & coordinates)
    : Missile(randomizedMissileCoordinates(coordinates))
    {}

    std::string TumblingMissile::getName()
    {
        return "Taumelrakete";
    }

    Sea::Coordinates TumblingMissile::randomizedMissileCoordinates(Sea::Coordinates const & primaryCoordinates)
    {
        static random_device randomNumberInitializer;
        static mt19937 randomNumbers(randomNumberInitializer());
        static uniform_int_distribution<int> intPlusMinus1(-1, 1);

        int x = int(primaryCoordinates.getX()) + intPlusMinus1(randomNumbers);
        int y = int(primaryCoordinates.getY()) + intPlusMinus1(randomNumbers);

        x = clamp(x, 0, int(Constants::seaSizeX) - 1);
        y = clamp(y, 0, int(Constants::seaSizeX) - 1);

        return Sea::Coordinates((unsigned int)(x), (unsigned int)(y));
    }

}
