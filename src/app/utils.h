#ifndef BLATT8_UTILS_H
#define BLATT8_UTILS_H


#include <iostream>
#include <vector>


namespace Utils {

    struct n_endl {
        unsigned int n;

        explicit n_endl(unsigned int newN);
    };

    std::ostream & operator<<(std::ostream & stream, n_endl const & n);

}


#endif //BLATT8_UTILS_H
