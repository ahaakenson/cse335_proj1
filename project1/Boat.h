/**
 * \file Boat.h
 *
 * \author Michael Dittman , Matthew Norris
 *
 * Class that describes the boat
 */

#pragma once
#include "Vehicle.h"

/**
 * Class that describes the boat
 */
class CBoat : public CVehicle
{
public:
    /// Default constructor (disabled)
    CBoat() = delete;

    /// Copy constructor (disabled)
    CBoat(const CBoat&) = delete;

    CBoat::CBoat(CGame* game, std::shared_ptr<Gdiplus::Bitmap> bitmap, double speed, int yPos, int xPos);

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node) override;


private:
    /// Image swap time for boat
    double mSwapTime = 0;

};

