#include "Output.h"

#include <iostream>
using std::left;
#include <iomanip>
using std::setw;
#include <sstream>
using std::stringstream;

std::string GameObjects::OutputGridCell::str() const
{
    char symbol;
    if (missiles > 0) {
        symbol = ship ? '*' : '-';
    }
    else if (vortex) {
        symbol = ship ? '@' : '~';
    }
    else {
        symbol = ship ? 'X' : '-';
    }
    stringstream stream;
    stream << " " << symbol;
    if (missiles > 0) {
        stream << setw(2) << left << missiles;
    }
    else {
        stream << "  ";
    }
    return stream.str();
}
