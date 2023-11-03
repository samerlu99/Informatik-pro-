#ifndef BLATT7_MISSILE_H
#define BLATT7_MISSILE_H


#include "Coordinates.h"

#include "Output.h"


namespace GameObjects {

    class Missile : public Sea::Coordinates {
    private:
        bool hit = false;

    public:
        Missile(Sea::Coordinates const & coordinates);
        Missile(Missile const & missile);
        virtual ~Missile() = default;

        static std::string getName();

        virtual bool checkHit(Sea::Coordinates const & coordinates);
        void hitSomething();
        virtual bool hasHitSomething() const;

        virtual void output(OutputGrid & grid) const;
    };

}


#endif //BLATT7_MISSILE_H
