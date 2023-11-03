#include "Coordinates.h"

#include<string>
using std::to_string;

#include<iostream>
using std::ostream;


namespace Sea {

    Coordinates::Coordinates(unsigned int newX, unsigned int newY)
    : x(newX), y(newY)
    {
    }

    bool Coordinates::samePositionAs(unsigned int otherX, unsigned int otherY) const
    {
        return x == otherX && y == otherY;
    }

    bool Coordinates::operator==(Coordinates const & otherCoordinates) const
    {
        return samePositionAs(otherCoordinates.x, otherCoordinates.y);
    }

    unsigned int Coordinates::getX() const
    {
        return x;
    }

    unsigned int Coordinates::getY() const
    {
        return y;
    }

    std::string Coordinates::toString() const
    {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }

    // TODO Aufgabe 2:
    // Definiert hier den `operator<`.
    //also here vergleichen alle möglichen Koordinaten-Paare

    bool Coordinates::operator<(Coordinates const & other) const
    {
        return y < other.y || (y == other.y && x < other.x);
    }

}

ostream &operator<<(ostream &stream, Sea::Coordinates const &coordinates) {
    return stream << coordinates.toString();
}

