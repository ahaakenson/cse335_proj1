/**
 * \file Car.h
 *
 * \author Michael Dittman
 *
 * Class that describes the car
 */


#pragma once
#include "Vehicle.h"


/**
 * Class that describes the car
 */
class CCar : public CVehicle
{
public:
    /// Default contructor (disabled)
    CCar() = delete;

    /// Copy constructor (disabled)
    CCar(const CCar&) = delete;

    CCar::CCar(CGame* game, std::shared_ptr<Gdiplus::Bitmap> bitmap);

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

private:
    /// Image swap time
    double mSwapTime = 0;

};

