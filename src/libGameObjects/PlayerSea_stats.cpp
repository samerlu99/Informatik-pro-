#include "PlayerSea.h"

#include <iostream>
using std::cout;
using std::endl;
#include <algorithm>
using std::max;
using std::count_if;
using std::begin;
using std::end;
#include <utility>
using std::pair;
using std::make_pair;

#include "Output.h"
using GameObjects::OutputGridCell;


namespace GameObjects {

    unsigned int numShipPositionsUnhit(OutputGrid const & grid)
    {
        auto size = grid.filter([](OutputGridCell const & cell) {
                return cell.ship && cell.missiles == 0 && !cell.vortex;
            }).size();
        return static_cast<unsigned int>(size);
    }

    unsigned int numWaterPositionsHit(OutputGrid const & grid)
    {
        auto size = grid.filter([](OutputGridCell const & cell) {
                return cell.missiles > 0 && !cell.ship;
            }).size();
        return static_cast<unsigned int>(size);
    }

    unsigned int numMaxMissilesPerPosition(OutputGrid const & grid)
    {
        unsigned int maxMissiles = 0;
        grid.walk([&](OutputGridCell const & cell) {
            maxMissiles = max(maxMissiles, cell.missiles);
        });
        return maxMissiles;
    }

    pair<unsigned int, unsigned int> numMultipleHits(OutputGrid const & grid)
    {
        unsigned int numMissiles = 0;
        unsigned int numPositions = 0;
        grid.walk([&](OutputGridCell const & cell) {
            if (cell.missiles > 1 && cell.ship) {
                numMissiles += cell.missiles;
                ++numPositions;
            }
        });
        return make_pair(numMissiles, numPositions);
    }

    unsigned int numVortexPositions(OutputGrid const & grid)
    {
        // TODO Aufgabe 2:
        //  Nutzt eine geeignete Funktion aus <algorithm> und ein Lambda, um alle Positionen zu "zählen, wenn" sie von einem Strudel betroffen waren.
        return (unsigned int) count_if(grid.begin(), grid.end(), [](OutputGridCell const & cell){ return cell.vortex; });
    }

    void PlayerSea::printStats() const
    {
        auto multipleHits = numMultipleHits(gridOtherSea);
        unsigned int numMultipleHitMissiles = multipleHits.first;
        unsigned int numMultipleHitPositions = multipleHits.second;

        cout << numShipPositionsUnhit(gridOwnSea) << " Position(en) der eigenen Schiffe sind ungetroffen" << endl;
        cout << numMultipleHitMissiles << " Mehrfach-Treffer auf " << numMultipleHitPositions << " Schiffsposition(en) des Gegners" << endl;
        cout << "Maximal " << numMaxMissilesPerPosition(gridOtherSea) << " Treffer auf der selben Position" << endl;
        cout << numWaterPositionsHit(gridOtherSea) << " Wasserposition(en) getroffen" << endl;
        cout << numVortexPositions(gridOtherSea) << " Position(en) von Strudeln erfasst" << endl;
    }

}