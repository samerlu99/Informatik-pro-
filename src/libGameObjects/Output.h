#ifndef BLATT8_OUTPUT_H
#define BLATT8_OUTPUT_H


#include <string>

#include "Grid2D.h"


namespace GameObjects {

    struct OutputGridCell {
        bool ship = false;
        unsigned int missiles = 0;
        bool vortex = false;

        std::string str() const;
    };

    using OutputGrid = Sea::Grid2D<OutputGridCell>;

}


#endif //BLATT8_OUTPUT_H
