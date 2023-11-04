#ifndef BLATT8_COORDINATES_H
#define BLATT8_COORDINATES_H


#include <string>
#include <iostream>


namespace Sea {

    template<typename T>
    class TCoordinates {
    protected:
        T x, y;

    public:
        TCoordinates(T newX, T newY);

        bool samePositionAs(T otherX, T otherY) const;

        T getX() const;
        T getY() const;

        std::string toString() const;

        template<typename O>
        bool operator==(TCoordinates<O> const & other) const;

        template<typename O>
        bool operator<(TCoordinates<O> const & other) const;
    };


    using Coordinates = TCoordinates<unsigned int>; // "Standard"-Koordinaten verwenden `unsigned int`
    using FCoordinates = TCoordinates<float>;

}

template<typename T>
std::ostream & operator<<(std::ostream & stream, Sea::TCoordinates<T> const & coordinates);


#include "Coordinates.inl"


#endif //BLATT8_COORDINATES_H
