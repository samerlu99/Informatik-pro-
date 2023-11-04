#include "Object.h"


namespace Sea {

    Object::Object(Coordinates const & newCoordinates, unsigned int newSize, Sea::Orientation newOrientation)
    : Coordinates(newCoordinates), size(newSize), orientation(newOrientation)
    {
    }

    bool Object::atCoordinates(Coordinates const & coordinates) const
    {
        auto orientationAsInt = static_cast<unsigned int>(orientation);
        unsigned int stepX = 1 - orientationAsInt,
                     stepY = orientationAsInt;
        for (unsigned int i = 0; i < size; ++i) {
            if (coordinates.samePositionAs(x + stepX * i, y + stepY * i)) {
                return true;
            }
        }
        return false;
    }

    bool Object::intersectsWith(Object const & otherObject) const
    {
        auto orientationAsInt = static_cast<unsigned int>(orientation);
        unsigned int stepX = 1 - orientationAsInt,
                     stepY = orientationAsInt;
        for (unsigned int i = 0; i < size; ++i) {
            if (otherObject.atCoordinates(Coordinates(x + stepX * i, y + stepY * i))) {
                return true;
            }
        }
        return false;
    }

    Orientation Object::getOrientation() const
    {
        return orientation;
    }

    unsigned int Object::getSize() const
    {
        return size;
    }

}
