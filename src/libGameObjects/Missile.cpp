#include "Missile.h"

#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;
#include <algorithm>
using std::clamp;

#include "Coordinates.h"
using Sea::Coordinates;
using Sea::FCoordinates;

#include "Constants.h"


namespace GameObjects {

    Missile::Missile(Coordinates const & coordinates)
    : Coordinates(coordinates), trackerCoordinates(randomizedTrackerCoordinates(coordinates))
    {}

    FCoordinates Missile::randomizedTrackerCoordinates(Coordinates const & coordinates)
    {
        static random_device randomNumberInitializer;
        static mt19937 randomNumbers(randomNumberInitializer());
        static uniform_real_distribution<float> floatPlusMinusAHalf(-.5f, .5f);

        float x = coordinates.getX() + floatPlusMinusAHalf(randomNumbers);
        float y = coordinates.getY() + floatPlusMinusAHalf(randomNumbers);

        x = clamp(x, 0.f, float(Constants::seaSizeX) - 1);
        y = clamp(y, 0.f, float(Constants::seaSizeX) - 1);

        return FCoordinates(x, y);
    }

    std::string Missile::getName()
    {
        return "Rakete";
    }

    bool Missile::checkHit(Coordinates const & coordinates)
    {
        if (*this == coordinates) {
            hit = true;
            return true;
        }
        return false;
    }

    bool Missile::hasHitSomething() const
    {
        return hit;
    }

    void Missile::collectTrackerCoordinates(std::list<Sea::FCoordinates> & coords) const
    {
        if (!hit) {
            coords.push_front(trackerCoordinates);
        }
    }

    void Missile::output(OutputGrid & grid) const
    {
        auto & cell = grid[*this];
        cell.missiles++;
        cell.ship = hit;
    }

}
