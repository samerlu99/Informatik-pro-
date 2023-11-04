#ifndef BLATT8_PLAYERSEA_H
#define BLATT8_PLAYERSEA_H


#include <string>
#include <vector>
#include <list>
#include <memory>
#include <exception>
#include <iostream>

#include "Coordinates.h"

#include "Ship.h"
#include "Missile.h"
#include "Vortex.h"
#include "Constants.h"


namespace GameObjects {
    class PlayerSea; // forward declaration
}

std::ostream & operator<<(std::ostream & stream, GameObjects::PlayerSea const & playerSea);

namespace GameObjects {

    class PlayerSea {
    private:
        std::string playerName;
        std::vector<Ship> ships;
        std::vector<std::shared_ptr<Missile>> missilesSent, missilesReceived;

        bool receiveMissile(std::shared_ptr<Missile> missile);

        OutputGrid gridOwnSea = OutputGrid(Constants::seaSizeX, Constants::seaSizeY, {});
        OutputGrid gridOtherSea = gridOwnSea;

    public:
        void setPlayerName(std::string const & newPlayerName);

        std::string const & getPlayerName() const;

        static std::string getSeaBounds();

        static bool isInsideSeaBounds(Sea::Coordinates const & coordinates);

        bool overlapWithExistingShips(Ship const & otherShip) const;

        class AddShipException : public std::exception {
        public:
            bool outsideSeaBounds = false;
            bool overlapOtherShip = false;
        };
        void addShip(Ship const & ship);

        bool sendMissileTo(PlayerSea & otherSea, std::shared_ptr<Missile> missile);

        std::list<Sea::FCoordinates> collectTrackerCoordinates() const;
        Vortex createVortex(std::list<Sea::FCoordinates> const & trackerCoordinates, PlayerSea & otherSea);

        // (TODO Aufgabe 4:)
        //
        //
        //

        bool allShipsDestroyed() const;

        void printStats() const;

        friend std::ostream & ::operator<<(std::ostream & stream, GameObjects::PlayerSea const & playerSea);

    private:
        void printHeader(std::ostream & stream) const;
        void printLine(std::ostream & stream, unsigned int y) const;
        static void printHorizontalBorder(std::ostream & stream);
    };

}


#endif //BLATT8_PLAYERSEA_H
