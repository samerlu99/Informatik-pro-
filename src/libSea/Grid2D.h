#ifndef BLATT7_GRID2D_H
#define BLATT7_GRID2D_H


#include <functional>
#include <vector>

#include "Coordinates.h"


namespace Sea {

    template<class T>
    class Grid2D {

    private:
        std::vector<std::vector<T>> grid;

    public:
        Grid2D(unsigned int sizeX, unsigned int sizeY, T const & initElement);

        unsigned int sizeX() const;
        unsigned int sizeY() const;
        unsigned int size() const;

        T const & operator[](Coordinates const & coords) const;
        T & operator[](Coordinates const & coords);

        T const & operator()(unsigned int x, unsigned int y) const;
        T & operator()(unsigned int x, unsigned int y);

        template <typename F>
        void walk(F operation) const;

        std::vector<T> filter(std::function<bool (T const &)> const & condition) const;

    };

}


#include "Grid2D.inl"


#endif //BLATT7_GRID2D_H
