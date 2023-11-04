#ifndef BLATT8_ATTACK_H
#define BLATT8_ATTACK_H


#include "Output.h"


namespace GameObjects {

    class Attack {
    public:
        virtual ~Attack() = default;

        virtual bool checkHit(Sea::Coordinates const & coordinates) = 0;
        virtual bool hasHitSomething() const = 0;

        virtual void output(OutputGrid & grid) const = 0;
    };

}


#endif //BLATT8_ATTACK_H
