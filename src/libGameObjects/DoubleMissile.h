#ifndef BLATT7_DOUBLEMISSILE_H
#define BLATT7_DOUBLEMISSILE_H


#include "Coordinates.h"

#include "Missile.h"
#include "TumblingMissile.h"


namespace GameObjects {

    class DoubleMissile : public Missile {
    private:
        TumblingMissile secondaryMissile;

    public:
        DoubleMissile(Sea::Coordinates const & coordinates);
        DoubleMissile(DoubleMissile const & missile);

        static std::string getName();

        bool checkHit(Sea::Coordinates const & coordinates) override;
        bool hasHitSomething() const override;

        void output(OutputGrid & grid) const override;
    };

}


#endif //BLATT7_DOUBLEMISSILE_H
