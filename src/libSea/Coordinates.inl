#include <string>
using std::to_string;

#include <iostream>
#include "Coordinates.h"

using std::ostream;


namespace Sea {

    template<typename T>
    TCoordinates<T>::TCoordinates(T newX, T newY)
    : x(newX), y(newY)
    {
    }

    template<typename T>
    bool TCoordinates<T>::samePositionAs(T otherX, T otherY) const
    {
        return x == otherX && y == otherY;
    }

    template<typename T>
    T TCoordinates<T>::getX() const
    {
        return x;
    }

    template<typename T>
    T TCoordinates<T>::getY() const
    {
        return y;
    }

    template<typename T>
    std::string TCoordinates<T>::toString() const
    {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }

    template<typename T>
    template<typename O>
    bool TCoordinates<T>::operator==(TCoordinates<O> const & other) const
    {
        return samePositionAs(other.x, other.y);
    }

    template<typename T>
    template<typename O>
    bool TCoordinates<T>::operator<(TCoordinates<O> const & other) const
    {
        return y < other.getY() || (y == other.getY() && x < other.getX());
    }
}

template<typename T>
ostream & operator<<(ostream & stream, Sea::TCoordinates<T> const & coordinates)
{
    return stream << coordinates.toString();
}
