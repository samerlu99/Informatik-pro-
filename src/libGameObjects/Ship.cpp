#include "Ship.h"

#include "Coordinates.h"
using Sea::Coordinates;

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

    void Ship::checkHits(Attack & attack)
    {
        for (unsigned int i = 0; i < size; ++i) {
            Coordinates shipHitPosition = (orientation == Sea::Orientation::X)
                    ? Coordinates(x + i, y)
                    : Coordinates(x, y + i);
            if (attack.checkHit(shipHitPosition)) {
                hitPositions.insert(shipHitPosition);
            }
        }
    }

    bool Ship::isDestroyed() const
    {
        return hitPositions.size() == size;
    }

    void Ship::output(OutputGrid & grid) const
    {
        for (unsigned int i = 0; i < size; ++i) {
            auto & cell = (orientation == Sea::Orientation::X)
                    ? grid(x + i, y)
                    : grid(x, y + i);
            cell.ship = true;
        }
    }

}
