#ifndef BLATT8_DOUBLEMISSILE_H
#define BLATT8_DOUBLEMISSILE_H


#include "Coordinates.h"

#include "Missile.h"
#include "TumblingMissile.h"


namespace GameObjects {

    class DoubleMissile : public Missile {
    private:
        TumblingMissile secondaryMissile;

    public:
        DoubleMissile(Sea::Coordinates const & coordinates);

        static std::string getName();

        bool checkHit(Sea::Coordinates const & coordinates) override;
        bool hasHitSomething() const override;

        virtual void collectTrackerCoordinates(std::list<Sea::FCoordinates> & coords) const override;

        void output(OutputGrid & grid) const override;
    };

}


#endif //BLATT8_DOUBLEMISSILE_H
