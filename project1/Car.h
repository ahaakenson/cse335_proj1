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

    CCar(CGame* game, const std::wstring& filename);
    CCar(CGame* game);

private:
    /// Image swap time
    double mSwapTime = 0;

};

