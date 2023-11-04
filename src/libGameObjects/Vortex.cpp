#include "Vortex.h"

#include <list>
using std::list;
#include <vector>
using std::vector;
#include <tuple>
using std::tie;
using std::get;
#include <algorithm>
using std::begin;
using std::end;
using std::for_each;
using std::sort;
using std::find;
#include <cmath>
using std::hypot;

#include "Coordinates.h"
using Sea::Coordinates;
using Sea::FCoordinates;


namespace GameObjects {

    Vortex::Vortex(list<FCoordinates> const & trackerPositions, float newRadius)
    : FCoordinates(meanPosition(trackerPositions)), radius(newRadius)
    {
    }

    FCoordinates Vortex::meanPosition(list<FCoordinates> const & trackerPositions)
    {
        vector<float> Xs, Ys;
        Xs.reserve(trackerPositions.size());
        Ys.reserve(trackerPositions.size());

        // TODO Aufgabe 3:
        //  Zerlegt die `Coordinates` in `trackerPositions`, sodass ihre X- und Y-Werte entsprechend auf die beiden Vektoren `Xs` und `Ys` aufgeteilt werden.
        //  Ruft anschließend `calculatePreciseMeanPosition(..)` für jede der beiden Listen auf, um den jeweiligen Mittelwert zu berechnen.
        for_each(begin(trackerPositions), end(trackerPositions), [&](auto const & pos) { Xs.push_back(pos.getX()); Ys.push_back(pos.getY()); });

        float meanX = calculatePreciseMeanPosition(Xs);
        float meanY = calculatePreciseMeanPosition(Ys);
        return { meanX, meanY };
    }

    template<class SORTED_VECTOR_ITERATOR>
    float recursiveSum(SORTED_VECTOR_ITERATOR itBegin, SORTED_VECTOR_ITERATOR itEnd) {
        auto d = std::distance(itBegin, itEnd);
        if (d == 1)
            return *itBegin;
        return recursiveSum(itBegin, itBegin + d / 2) + recursiveSum(itBegin + d / 2, itEnd);
    }

    float Vortex::calculatePreciseMeanPosition(vector<float> nums)
    {
        // TODO Aufgabe 3:
        //  Berechnet hier für die übergebene Liste möglichst genau den Mittelwert der enthaltenen `float`-Zahlen, ohne den Datentyp `double` zu nutzen.
        //  Hinweis: VL-Video: Einführung und Basics > Basics > Präzision
        sort(begin(nums), end(nums));
        return recursiveSum(begin(nums), end(nums)) / nums.size();
    }

    bool Vortex::checkHit(Coordinates const & coordinates)
    {
        if (inRange(coordinates)) {
            hits.push_back(coordinates);
            return true;
        }
        return false;
    }

    bool Vortex::inRange(Coordinates const & coordinates) const
    {
        auto x2 = float(coordinates.getX()),
             y2 = float(coordinates.getY());
        return hypot(x - x2, y - y2) <= radius;
    }

    bool Vortex::hasHitSomething() const
    {
        return !hits.empty();
    }

    void Vortex::output(OutputGrid & grid) const
    {
        grid.walk2([&](auto & gridCell, Coordinates const & coords) {
            if (inRange(coords)) {
                gridCell.vortex = true;

                if (!gridCell.ship) {
                    // TODO Aufgabe 5:
                    //  Prüft, ob die aktuelle Position in der Trefferliste `hits` enthalten ist.
                    //  Wenn ja, setzt `gridCell.ship` auf `true`.
                    gridCell.ship = find(begin(hits), end(hits), coords) != end(hits);
                }
            }
        });
    }

}
