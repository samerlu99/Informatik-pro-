#ifndef BLATT8_SHIP_H
#define BLATT8_SHIP_H


#include <set>

#include "Object.h"
#include "Coordinates.h"

#include "Attack.h"
#include "Output.h"


namespace GameObjects {

    class Ship : public Sea::Object {
    private:
        std::set<Sea::Coordinates> hitPositions;

    public:
        using Sea::Object::Object;

        bool isInsideSeaBounds() const;

        void checkHits(Attack & attack);

        bool isDestroyed() const;

        void output(OutputGrid & grid) const;
    };

}


#endif //BLATT8_SHIP_H
