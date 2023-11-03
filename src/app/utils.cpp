#include "utils.h"

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <sstream>
using std::stringstream;


namespace Utils {

    n_endl::n_endl(unsigned int newN)
    : n(newN)
    {
    }

    ostream & operator<<(ostream & stream, n_endl const & n)
    {
        if (n.n > 1) {
            stream << std::string(n.n - 1, '\n') << endl;
        }
        else {
            stream << endl;
        }
        return stream;
    }

}
