/**
 * \file Car.cpp
 *
 * \author Michael Dittman
 */

#include "pch.h"
#include "Car.h"


 /**
  * Constructor for CDecor.
  *
  * \param game Pointer to the game this decor is a part of
  * \param filename file where image is stored
  */
CCar::CCar(CGame* game, const std::wstring& filename) :
    CVehicle(game, filename)
{
}
