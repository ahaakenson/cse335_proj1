/**
 * \file Boat.h
 *
 * \author Michael Dittman
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

    CBoat::CBoat(CGame* game, std::shared_ptr<Gdiplus::Bitmap> bitmap, double speed);

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

};

