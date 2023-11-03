#ifndef BLATT7_SHIP_H
#define BLATT7_SHIP_H


#include <set>

#include "Object.h"
#include "Coordinates.h"

#include "Missile.h"
#include "Output.h"


namespace GameObjects {

    class Ship : public Sea::Object {
    private:
        // TODO Aufgabe 2:
        //  Ersetzt hier den vector-Typ der Variablen `missileHitPositions` durch ein `std::set`.
        std::set<Coordinates> missileHitPositions;

    public:
        using Sea::Object::Object;

        bool isInsideSeaBounds() const;

        void checkHits(Missile & missile);

        bool isDestroyed() const;

        void output(OutputGrid & grid) const;
    };

}


#endif //BLATT7_SHIP_H
