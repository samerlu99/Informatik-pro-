#include "Ship.h"

#include "PlayerSea.h"


namespace GameObjects {

    bool Ship::isInsideSeaBounds() const
    {
        if (PlayerSea::isInsideSeaBounds(*this)) {
            auto orientationAsInt = static_cast<unsigned int>(orientation);
            Coordinates shipEnd(
                x + (1 - orientationAsInt) * (size - 1),
                y + orientationAsInt * (size - 1));
            return PlayerSea::isInsideSeaBounds(shipEnd);
        }
        return false;
    }

    void Ship::checkHits(Missile & missile)
    {
        for (unsigned int i = 0; i < size; ++i) {
            Coordinates shipHitPosition = (orientation == Sea::Orientation::X)
                    ? Coordinates(x + i, y)
                    : Coordinates(x, y + i);
            if (missile.checkHit(shipHitPosition)) {
                // TODO Aufgabe 2:
                //in checkHits die Funktion set::insert statt vector::push_back verwendet.
                missileHitPositions.insert(shipHitPosition);
            }
        }
    }

    bool Ship::isDestroyed() const
    {
        // TODO Aufgabe 2:
        //  Der Test, ob das Schiff versenkt wurde, ist nun mit einem einzelnen Vergleich möglich.

        //korrekt geprüft, ob alle Schiffspositionen getroffen wurden.
        return missileHitPositions.size() == size;
    }


    void Ship::output(OutputGrid & grid) const
    {
        for (unsigned int i = 0; i < size; ++i) {
            auto & cell = (orientation == Sea::Orientation::X)
                    ? grid(x + i, y)
                    : grid(x, y + i);
            cell.ship = true;
            cell.output = " X  ";
        }
    }

}
