#include "PlayerSea.h"

#include <string>
using std::string;
using std::to_string;
#include <list>
using std::list;
#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <algorithm>
using std::min;
using std::any_of;
using std::all_of;
using std::begin;
using std::end;

#include "Coordinates.h"
using Sea::Coordinates;
using Sea::FCoordinates;

#include "Vortex.h"
#include "Constants.h"


namespace GameObjects {

    void PlayerSea::setPlayerName(string const & newPlayerName)
    {
        playerName = newPlayerName;
    }

    string const & PlayerSea::getPlayerName() const
    {
        return playerName;
    }

    string PlayerSea::getSeaBounds()
    {
        return "Spielfeld: 0-" + to_string(Constants::seaSizeX - 1) +
                       " x 0-" + to_string(Constants::seaSizeY - 1);
    }

    bool PlayerSea::overlapWithExistingShips(Ship const & otherShip) const
    {
        // TODO Aufgabe 1:
        //  Die Funktion liefert `true`, sobald `ship.intersectsWith(..)` für *irgendein* Schiff `true` ergibt.
        //  Ersetzt die folgende for-Loop durch eine geeignete Funktion aus <algorithm>.
        return any_of(begin(ships), end(ships),
                      [&](Ship const & ship) { return ship.intersectsWith(otherShip); });
    }

    void PlayerSea::addShip(Ship const & ship)
    {
        if (!ship.isInsideSeaBounds()) {
            AddShipException e;
            e.outsideSeaBounds = true;
            throw e;
        }
        if (overlapWithExistingShips(ship)) {
            AddShipException e;
            e.overlapOtherShip = true;
            throw e;
        }
        ships.push_back(ship);
        ship.output(gridOwnSea);
    }

    bool PlayerSea::sendMissileTo(PlayerSea & otherSea, shared_ptr<Missile> missile)
    {
        otherSea.receiveMissile(missile);
        missilesSent.push_back(missile);
        missile->output(gridOtherSea);
        return missile->hasHitSomething();
    }

    bool PlayerSea::receiveMissile(shared_ptr<Missile> missile)
    {
        for (auto & ship : ships) {
            ship.checkHits(*missile);
        }
        missilesReceived.push_back(missile);
        missile->output(gridOwnSea);
        return missile->hasHitSomething();
    }

    list<FCoordinates> PlayerSea::collectTrackerCoordinates() const
    {
        list<FCoordinates> trackerCoordinates;
        for (auto & missile : missilesSent) {
            missile->collectTrackerCoordinates(trackerCoordinates);
        }
        return trackerCoordinates;
    }

    Vortex PlayerSea::createVortex(list<FCoordinates> const & trackerCoordinates, PlayerSea & otherSea)
    {
        Vortex vortex(trackerCoordinates, float(min(Constants::seaSizeX, Constants::seaSizeY)) / 4.f);
        for (auto & ship : otherSea.ships) {
            ship.checkHits(vortex);
        }
        vortex.output(gridOtherSea);
        vortex.output(otherSea.gridOwnSea);
        return vortex;
    }

    bool PlayerSea::allShipsDestroyed() const
    {
        // TODO Aufgabe 1:
        //  Die Funktion liefert `true`, wenn `ship.isDestroyed()` für *alle* Schiffe `true` ergibt.
        //  Ersetzt die folgende for-Loop durch eine geeignete Funktion aus <algorithm>.
        return all_of(begin(ships), end(ships),
                      [](Ship const & ship){ return ship.isDestroyed(); });
    }

    bool PlayerSea::isInsideSeaBounds(Coordinates const & coordinates)
    {
        return  coordinates.getX() < Constants::seaSizeX &&
                coordinates.getY() < Constants::seaSizeY;
    }

}
