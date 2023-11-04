#ifndef BLATT8_MISSILE_H
#define BLATT8_MISSILE_H


#include "Coordinates.h"

#include <list>

#include "Attack.h"
#include "Output.h"


namespace GameObjects {

    class Missile : public Attack, public Sea::Coordinates {
    private:
        bool hit = false;
        Sea::FCoordinates trackerCoordinates;

        static Sea::FCoordinates randomizedTrackerCoordinates(Sea::Coordinates const & coordinates);

    public:
        Missile(Sea::Coordinates const & coordinates);
        virtual ~Missile() = default;

        static std::string getName();

        virtual bool checkHit(Sea::Coordinates const & coordinates) override;
        virtual bool hasHitSomething() const override;

        virtual void collectTrackerCoordinates(std::list<Sea::FCoordinates> & coords) const;

        virtual void output(OutputGrid & grid) const override;
    };

}


#endif //BLATT8_MISSILE_H
