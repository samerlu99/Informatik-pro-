#ifndef BLATT8_TUMBLINGMISSILE_H
#define BLATT8_TUMBLINGMISSILE_H


#include "Coordinates.h"

#include "Missile.h"


namespace GameObjects {

    class TumblingMissile : public Missile {
    public:
        TumblingMissile(Sea::Coordinates const & coordinates);

        static std::string getName();

    private:
        static Sea::Coordinates randomizedMissileCoordinates(Sea::Coordinates const & primaryCoordinates);
    };

}


#endif //BLATT8_TUMBLINGMISSILE_H
