#ifndef BLATT8_VORTEX_H
#define BLATT8_VORTEX_H


#include <list>

#include "Coordinates.h"

#include "Attack.h"
#include "Missile.h"
#include "Output.h"


namespace GameObjects {

    class Vortex : public Attack, public Sea::FCoordinates {
    private:

        std::list<Sea::Coordinates> hits;
        float radius;

        bool inRange(Sea::Coordinates const & coordinates) const;

    public:
        Vortex(std::list<Sea::FCoordinates> const & trackerPositions, float newRadius);

        static Sea::FCoordinates meanPosition(std::list<Sea::FCoordinates> const & pos);
        static float calculatePreciseMeanPosition(std::vector<float> nums);

        bool checkHit(Sea::Coordinates const & coordinates) override;
        bool hasHitSomething() const override;

        void output(OutputGrid & gridCell) const override;
    };

}


#endif //BLATT8_VORTEX_H
