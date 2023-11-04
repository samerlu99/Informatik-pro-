#ifndef BLATT8_GRID2D_H
#define BLATT8_GRID2D_H


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
        template <typename F>
        void walk2(F operation);

        std::vector<T> filter(std::function<bool (T const &)> const & condition) const;



    private:
        template<typename GridT, typename IT>
        class baseIterator {
            GridT &grid;
            unsigned int x, y;
        public:
            using iterator_category = std::forward_iterator_tag;
            using difference_type   = std::ptrdiff_t;
            using value_type        = IT;
            using pointer           = IT *;
            using reference         = IT &;

            baseIterator(GridT &newGrid, unsigned int x, unsigned int y) : grid(newGrid), x(x), y(y) {}
            baseIterator(baseIterator const & other) : grid(other.grid), x(other.x), y(other.y) {}

            baseIterator & operator++() { if (x < (grid.sizeX() - 1)) { ++x; } else { x = 0; ++y; } return *this; }
            baseIterator operator++(int) { auto oldPos = *this; ++(*this); return oldPos; }
            bool operator==(baseIterator const & other) const { return x == other.x && y == other.y; }
            bool operator!=(baseIterator const & other) const { return !(*this == other); }
            reference operator*() { return grid(x, y); }
            pointer operator->() { return &(grid(x, y)); }
        };

    public:
        using iterator = baseIterator<Grid2D<T>, T>;
        using const_iterator = baseIterator<Grid2D<T> const, T const>;

        iterator begin() { return iterator(*this, 0, 0); }
        iterator end() { return iterator(*this, 0, sizeY()); }

        const_iterator begin() const { return const_iterator(*this, 0u, 0u); }
        const_iterator end() const { return const_iterator(*this, 0u, sizeY()); }
    };

}


#include "Grid2D.inl"


#endif //BLATT8_GRID2D_H
